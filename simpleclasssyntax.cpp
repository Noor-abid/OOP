#include<iostream>
using namespace std ;
class A{
    private:
    string name;
    public:
    void getin(){
        cout<<"enter the name "<<endl;
        cin>>name;
    }
    void display(){
        cout<<"name: "<<name;
    }
};
int main(){
    A obj;
    obj.getin();
    obj.display();
}