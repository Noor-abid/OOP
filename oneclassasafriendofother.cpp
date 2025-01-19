//making two classes friends by taking the private members in one class and displaying the 
//value  of that members in other class 
#include<iostream>
using namespace std;
class A{
private:
int a;
int b;
public:
A(){
    a=10;
    b=20;
}
friend class B;

};
class B{
    public:
    void show1(A x){
        cout<<"the value of obj1  is "<<x.a <<endl;}
void show2(A y){
        cout<<"the value of obj2  is "<<y.b <<endl;

    }

};
int main(){
    A obj1;
    B obj2;
   
    obj2.show1(obj1);
    obj2.show2(obj1);
}