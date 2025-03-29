#include<iostream>
using namespace std ;
class Base{
    protected:
    int a;
    int b;
    int sum=0;
    int sub=0;
    int mul=0;
    int div=0;
    public:
    void get(){
        cout<<"enter the values of a and b: ";
        cin>>a>>b;
    }
    void displaysum(){
        sum=a+b;  
        cout<<"the sum of two number is "<<sum<<endl;
    }
    void displaysub(){
        sub=a-b;  
        cout<<"the sub of two number is "<<sub<<endl;
    }
    void displaymul(){
        mul=a*b;  
        cout<<"the mul of two number is "<<mul<<endl;
    }
    void displaydiv(){
        div=a/b;  
        cout<<"the div of two number is "<<div<<endl;
    }
};
class Child:public Base{
    public:
    void sum(){
        if(a>0 && b>0){
            Base::displaysum();
        }
        else 
        cout<<"Error the number should be greater than 0 "<<endl;
    }
    void sub(){
        if(a>0 && b>0){
            Base::displaysub();
        }
        else 
        cout<<"Error the number should be greater than 0 "<<endl;
    }
    void mul(){
        if(a>0 && b>0){
            Base::displaymul();
        }
        else 
        cout<<"Error the number should be greater than 0 "<<endl;
    }
    void div(){
        if(a>0 && b>0){
            Base::displaydiv();
        }
        else 
        cout<<"Error the number should be greater than 0 "<<endl;
    }
};
int main(){
    Child obj;
    obj.get();
    obj.sum();
    obj.sub();
    obj.mul();
    obj.div();
}