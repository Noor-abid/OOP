#include<iostream>
using namespace std;
class Student{
    private:
    string name;
    string c;
    int roll_num;
    int marks;
    public:
    Student(){
        name="null";
        c="null";
        marks=0;
        roll_num=0;
    }
    char checkgrade(){
        if(marks>=80 && marks<=100){
        return 'A';
    }
    else if(marks>=70 && marks<80){
        return 'B';
    }
    else if(marks>=60 && marks<70){
        return 'C';
    }
    else if(marks>=40 && marks<60){
        return 'E';
    }
    else 
        return 'F';
    }
    void displaydetails(){
        cout<<" Name: "<<name<<endl;
        cout<<" Roll number: "<<roll_num<<endl;
        cout<<" Marks: "<<marks<<endl;
        cout<<" Class: "<<c<<endl;
        cout<<" Grade: "<<checkgrade()<<endl;
    }
    void get(){
        cout<<"Enter the name of student"<<endl;
        getline(cin,name);
        cout<<"Enter the class of student"<<endl;
        getline(cin,c);
        cout<<"Enter the roll number of student "<<endl;
        cin>>roll_num;
        cout<<"Enter the marks of student "<<endl;
        cin>>marks;
    }
    void set(string n2,string cl2,int m2,int r2){
        name=n2;
        c=cl2;
        marks=m2;
        roll_num=r2;
    }
    int obtainedmarks(){
        return marks;
    }
};
int main(){
Student obj1,obj2;

obj1.get();
cout<<"Student 1: "<<endl;
obj1.displaydetails();
cout<<endl;
cout<<"Student 2: "<<endl;
obj2.set("Eman","BS Biochem",90,04);
obj2.displaydetails();
cout<<endl;
if(obj1.obtainedmarks()>obj2.obtainedmarks()){
    cout<<"The marks of Student 1 is higher than Student 2 "<<endl;
}
else if(obj2.obtainedmarks()>obj1.obtainedmarks()){
    cout<<"The marks of Student 2 is higher than the Student 1"<<endl;
}
else
cout<<"Both students have got the same marks "<<endl;
}