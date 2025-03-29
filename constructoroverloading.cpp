#include<iostream>
using namespace std;
class employee{
    private:
    string name;
    int id;
    double salary;
    public :
    employee(string name ,int id){
        this->name=name;
        this->id=id;
    }
    employee(string name ,int id,double salary){
        this->name=name;
        this->id=id;
        this->salary=salary;
    }
    void  displayinfo(){
        cout<<"the name of employee is "<<name<<endl;
        cout<<"id of employee is "<<id<<endl;
      
    }
    void displaysalary(){
        cout<<"salary of employee is "<<salary<<endl;
    }
};
int main(){
    employee obj("noor ",123);
    employee obj1("eman ",345,20000.0);
    obj.displayinfo();
    obj1.displayinfo();
    obj1.displaysalary();

}