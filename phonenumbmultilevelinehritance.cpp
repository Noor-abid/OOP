#include<iostream>
using namespace std;
class Localphone{
    protected:
    int phone;
    public:
    void getin(){
    cout<<"enter the phone number"<<endl;
    cin>>phone;
    }
    void show(){
        cout<<"the local phone number is: "<<phone<<endl;
    }
};
class Natphone:public Localphone{
    protected:
    int citycode;
    public:
void getin(){
    cout<<"enter the city code: ";
    cin>>citycode;
    Localphone::getin();
}
void show(){
    Localphone::show();
    cout<<"the city code is: "<<citycode<<endl;
   cout<<"the national phone number is "<<citycode<<"-"<<phone<<endl;
}
};
class Intphone:public Natphone{
    private:
    int countrycode;
    public:
void getin(){
    
    Natphone::getin();
    cout<<"enter the country code: ";
    cin>>countrycode;
}
void show(){
    
    Natphone::show();
    cout<<"the country code is: "<<countrycode<<endl;
    cout<<"international phone number is "<<"+"<<countrycode<<"-"<<citycode<<"-"<<phone<<endl;
}
};
int main(){
    Intphone obj;
    obj.getin();
    obj.show();
}