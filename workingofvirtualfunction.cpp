#include<iostream>
using namespace std;
class person{
    private:
    string name;
    public:
    person(){
        name="noor";
    }
 virtual void showinfo(){

    cout<<"the details of the person "<<name<<endl;
 }
};
class student:public person {
    private:
    string roll_no;

    public:
    student(){
        roll_no="292";
    }
void showinfo ()override{
    cout<<"the roll no of student is "<<roll_no<<endl;
}
};
class teacher:public person{
private:
string id;
public:
teacher(){
    id="123";
}
void  showinfo()override{
    cout<<"the id of the teacher is "<<id<<endl;
}
};
int main(){
    person *p[3];
    p[0]=new person();
    p[1]=new student();
    p[2]=new teacher();
    for(int i=0;i<3;i++){
        p[i]->showinfo();
    }
    return 0;
}
