#include<iostream>
using namespace std;
double pi=3.14159;
class Circle{
private:

double r;
public:
Circle(double radius){
    r=radius;
}
double CircleArea(){
    return pi*r*r;
}
double CirclePerimeter(){
    return 2*pi*r;
}
};
class Rectangle{
private:
double length;
double width;
public:
Rectangle(double l,double w){
    length=l;
    width=w;
}
double RectangleArea(){
    return length+width;
}
double RectanglePerimeter(){
    return 2*length+width;
}
};
int main(){
Circle c(1.56);
cout<<"Circle "<<endl;
cout<<"Area: "<<c.CircleArea()<<endl;
cout<<"Perimeter: "<<c.CirclePerimeter()<<endl;
Rectangle r(5.57,4.52);
cout<<"Rectangle "<<endl;
cout<<"Area: "<<r.RectangleArea()<<endl;
cout<<"Perimeter: "<<r.RectanglePerimeter()<<endl;
}