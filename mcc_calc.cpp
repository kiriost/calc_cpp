#include<iostream>
using namespace std;
//¼Ó
template<typename T>
T add_self(T a,T b){
    return a+b;
}
//¼õ
template<typename T>
T minus_self(T a,T b){
    return a-b;
}
//³Ë
template<typename T>
T multiply_self(T a,T b){
    return (T)(a*b);
}
//³ý
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
