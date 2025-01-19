//making two classes and displaying values of their private members by using a separate friend
//function (by declaring friend function in both classes so that it can access private members of both classes) 
#include<iostream>
using namespace std ;
class B;
class A{
    private:
    int a;
    public:
    A(){
        a=20;
    }
    friend void show(A x,B y);
};
class B{
    private:
    int b;
    public:
    B(){
        b=30;
    }
    friend void show(A x,B y);
};
void show(A x,B y){
    int z;
    z=x.a+y.b;
    cout<<"the value of class A is "<<x.a<<endl;
    cout<<"the value of class B is "<<y.b<<endl;
    cout<<"the total of both classes is "<<z<<endl;
}
int main(){
A obj1;
B obj2;
show(obj1,obj2);
}