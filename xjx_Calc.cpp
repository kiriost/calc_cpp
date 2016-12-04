#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;


int main()
{
    double a;
    
    while (scanf("%lf",&a)==1) {
        
        int div_zero=0;
        int finish=0;
        int undeclared=0;
        
        char symbol;
        double result[50];
        double finally=0;
        
        int boxes=1;
        int box_index=0;
        int num_index=0;
        
        double num[50][50]={0};
        num[0][0]=a;
        vector<char> symbols;
        
        while (scanf("%c",&symbol)==1) {
            symbols.push_back(symbol);
            switch (symbol) {
                case '+':
                    scanf("%lf",&a);
                    
                    box_index++;
                    boxes++;
                    num_index=0;
                    num[box_index][num_index]=a;
                    
                    break;
                    
                case '-':
                    scanf("%lf",&a);
                    
                    box_index++;
                    num_index=0;
                    boxes++;
                    num[box_index][num_index]=a;
                    
                    break;
                    
                case '*':
                    scanf("%lf",&a);
                    
                    num_index++;
                    num[box_index][num_index]=a;
                    
                    break;
                    
                case '/':
                    scanf("%lf",&a);
                    
                    num_index++;
                    num[box_index][num_index]=a;
                    
                    if (a==0) {
                        div_zero=1;
                        finish=0;
                        break;
                    }
        
                    break;
                    
                case '=':
                    finish=1;
                    break;
                    
                default:
                    undeclared=1;
                    finish=0;
                    break;
                    
            }
            
            //cout<<boxes<<endl;
            
            
            
            
            int sign=1;
            if(finish||undeclared||div_zero) {
                if (finish) {
                    int j=0;
                    for (int i=0; i<boxes; i++) {
                        
                        //cout<<num[i][0]<<endl;
                        if (i!=0){
                        if (symbols[j]=='-') {
                            sign=-1;
                            j++;
                        }
                        else {
                            sign=1;
                            j++;
                        }}
                        result[i]=num[i][0];
                        
                        cout<<symbols[j];
                        
                        for (int k=1;symbols[j]=='*'||symbols[j]=='/'; j++,k++) {
                            
                            //cout<<symbols[j];
                            
                            if (symbols[j]=='*') {
                                
                                //cout<<num[i][k]<<endl;
                                
                                result[i]*=num[i][k];
                            }
                            else if (symbols[j]=='/'){
                                result[i]/=num[i][k];
                            }
                            
                            
                        }
                        
                        cout<<symbols[j];
                        
                        cout<<"result:"<<result[i]<<" sign:"<<sign<<endl;
                        
                        finally += sign*result[i];
                        
                        if (symbols[j]=='=') {
                            break;
                        }
                        
                    }
                    cout<<finally<<endl;
                    
//                    for (int i=0; i<boxes; i++) {
//                        for (int j=0; j<3; j++) {
//                            cout<<num[i][j]<<" ";
//                        }
//                    }
//                    
//                    cout<<endl;
//                    
//                    for (int i=0  ; i<symbols.size(); i++) {
//                        cout<<symbols[i]<<" ";
//                    }
//                    
//                    
                }
                else if (undeclared){
                    cout<<"Undeclared indentifier"<<endl;
                }
                else if(div_zero){
                    cout<<"ZeroDivisionError"<<endl;
                }
                break;
            }
        }
        char ch;
        while ((ch=getchar())!='\n') {
            
        }
    }
        

}