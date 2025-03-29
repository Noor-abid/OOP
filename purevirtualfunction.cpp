#include<iostream>
using namespace std ;
// abstract class because it has atleast one pure virtual function
class Shape{
    public:
    virtual void draw()=0;
};
class Circle:public Shape{
    public:
    void draw()override{
        cout<<"drawing the circle "<<endl;
    }
};
class square:public Shape {
    public:
    void draw()override{
        cout<<"drawing the square "<<endl;
    }
};
int main(){
    Shape *s=new Circle();
    Shape *s1=new square();
    s->draw();
s1->draw();
}