#include<iostream>
using namespace std;
class Car{
    private:
    double speed;
    double fuellevel;
    double fuelefficiency;
    public:
    Car(double fuelefficiency=25.0){
        this->fuelefficiency=fuelefficiency;
        fuellevel=0.0;
        speed=0;
    }
    double getFuellevel(){
        return speed;
    }
    double getspeed(){
        return speed;
    }
    //accelerate method
    void accelerate(double amount){
        if(fuellevel>0){
            speed+=amount;
            fuellevel-=amount/fuelefficiency;
        
        if(fuellevel<0){
            fuellevel=0;
        }
        }
        else{
            cout<<"Out of fuel! "<<endl;
        }
    }
    //refuel method
    void refuel(double amount){
        fuellevel+=amount;
    }
    //display status
    void displaystatus(){
cout<<"speed: "<<speed<<" mph "<<endl;
cout<<"Fuel level: "<<fuellevel<<" gallons "<<endl;
    }
};
int main(){
Car c(30.0);
c.refuel(30.0);
c.accelerate(40.0);
c.displaystatus();
c.accelerate(30.0);
c.displaystatus();
}