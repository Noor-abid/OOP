#include<iostream>
using namespace std;
class Temperature {
    private:
    int celsius;
    int fahrenheit;
    public:
    Temperature(){
         celsius=0;
         fahrenheit=0;
    }
    void getcelsius(){
        cout<<"enter the temperature in celsius ";
        cin>>celsius;
        fahrenheit=(celsius*9/5)+32;
    }
    void setfahrenheit(int f){
        fahrenheit=f;
        celsius=(f-32)*5/9;
    }
    void displayfahrenheit(){
        cout<<"the temperature after converting into Fahrenheit is: "<<fahrenheit<<endl;
    }
    void displaycelsius(){
        cout<<"the temperature after converting into celsius is: "<<celsius<<endl;
    }
};
int main(){
Temperature t;
t.getcelsius();
t.displayfahrenheit();
t.setfahrenheit(90);
t.displaycelsius();
} 