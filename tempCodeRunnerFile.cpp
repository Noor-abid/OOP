#include<iostream>
using namespace std;
class student{
private:
int age;
int rollno;
string name;
public:
student (){
    cout<<"enter the name of student 1"<<endl;
    cin>>name;
    cout<<"enter the age of student 1"<<endl;
    cin>>age;
    cout<<"enter the roll number of student 1 "<<endl;
    cin>>rollno;

}
student (int a,int r,string n){
    age=a;
    rollno=r;
    name=n;

}
void show();

};
void student::show(){
    cout<<"Roll number: "<< rollno<<endl;
    cout<<"Name: "<< name<<endl;
    cout<<"Age: "<< age<<endl;
    }
    int main(){
        
        student s1;
        cout<<"STUDENT 1:"<<endl;
      s1.show();

        student s2(18,292,"Noor");
        cout<<"STUDENT 2:"<<endl;
      s2.show();

    }