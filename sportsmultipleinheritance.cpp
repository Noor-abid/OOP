#include<iostream>
using namespace std;
class Athlete {
    protected:
    string sportname;
    public:
    void getin(){
        cout<<"enter the name of the sport: ";
        cin>>sportname;
    }
    void display(){
        cout<<"The name of the sport is "<<sportname<<endl;
    }

};
class Scholar{
    protected :
    string grade;
    public:
    void getin(){
        cout<<"enter the grade of the scholar: ";
        cin>>grade;
    }
    void display(){
        cout<<"The grade of the scholar is "<<grade<<endl;
    }

};
class scholarathlete:public Athlete,public Scholar {
    public:
    void getin(){
        Athlete::getin();
        Scholar::getin();
        
    }
    void display(){
        Athlete::display();
        Scholar::display();
    }

};
int main(){
    scholarathlete s;
    s.getin();
    s.display();
}