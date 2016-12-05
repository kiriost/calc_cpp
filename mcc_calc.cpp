#include<iostream>
using namespace std;
//��
template<typename T>
T add_self(T a,T b){
    return a+b;
}
//��
template<typename T>
T minus_self(T a,T b){
    return a-b;
}
//��
template<typename T>
T multiply_self(T a,T b){
    return (T)(a*b);
}
//��
template<typename T>
T divide_self(T a,T b){
    return (T)(a/b);
}


int main(){
    float a,b;
    char sign;
    while(cin>>a>>sign>>b){
        switch(sign){
        case '+':
            cout<<add_self(a,b)<<endl;
            break;
        case '-':
            cout<<add_self(a,b)<<endl;
            break;
        case '*':
            cout<<add_self(a,b)<<endl;
            break;
        case '/':
            cout<<add_self(a,b)<<endl;
            break;
        default:
            cout<<"Input error!"<<endl;
    }
    }
    return 0;
}
