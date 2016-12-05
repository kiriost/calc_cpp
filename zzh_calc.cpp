#include <iostream>
#include <stack>
using namespace std;
int precede(char op1,char op2)//> 1,= 0,<-1
{
 switch(op1)
 {
 case '+':
  if(op2=='+' || op2=='-' || op2==')' || op2=='#')
   return 1;
  return -1;
 case '-':
  if(op2=='+' || op2=='-' || op2==')' || op2=='#')
   return 1;
  return -1;
 case '*':
  if(op2=='(')
   return -1;
  return 1;
 case '/':
  if(op2=='(')
   return -1;
  return 1;
 case '(':
  if(op2==')')
   return 0;
  return -1;  
 case ')':
  return 1;
 case '#':
  return -1;
 default:
  break;
 }
 return 0;
}
int compute(int num1,char op,int num2)
{
 int num=0;
 switch(op)
 {
 case '+':
  num=num1+num2;
  break;
 case '-':
  num=num1-num2;
  break;
 case '*':
  num=num1*num2;
  break;
 case '/':
  num=num1/num2;
  break;
 }
 return num;
}
int calculator(char str[205])
{
 int i,pre,num,num1,num2;
 char op1;
 bool flag;
 stack<char> charsta;
 stack<int> intsta;
 charsta.push('#');
 i=strlen(str);
 str[i]='#';
 str[i+1]='\0';
 i=0,num=0;
 flag=false;
 while(str[i])
 {
  if(str[i]>='0' && str[i]<='9')
  {
   flag=true;
   num=num*10+str[i]-'0';
   i++;
  }
  else
  {
   if(flag)
   {
    flag=false;
    intsta.push(num);
    num=0;
   }
   op1=charsta.top();
   if(op1=='#' && str[i]=='#')
    break;
   pre=precede(op1,str[i]);
   switch(pre)
   {
   case 0:
    charsta.pop();
    i++;
    break;
   case 1:
    charsta.pop();
    num2=intsta.top();
    intsta.pop();
    num1=intsta.top();
    intsta.pop();
    intsta.push(compute(num1,op1,num2));
    break;
   case -1:
    charsta.push(str[i]);
    i++;
    break;
   }
  }
 }
 num=intsta.top();
 intsta.pop();
 return num;
}
int main()
{
 char str[205];
 int i,n;
 cin>>n;//数据组数
 for(i=0;i<n;i++)
 {
  cin>>str; //输入表达式,如((5-3)*2-1)
  printf("%d\n",calculator(str));//计算结果
 } 
 return 0;
}