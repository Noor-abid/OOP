#include<iostream>
using namespace std;
class result{
    private:
    int m[3];
    string name;
    int r;
    public:
    void get(){
        cout<<"enter the name of student "<<endl;
        cin>>name;
        cout<<"enter the roll no of student  "<<endl;
        cin>>r;
        cout<<"enter the marks of three subject"<<endl;
        for(int i=0;i<3;i++){
            cin>>m[i];
        }
    }
    void data(){
        cout<<"the name of the student is "<<name <<endl;
        cout <<"the roll no of the student is "<<r<<endl;
        cout<<"the marks of the three subjects are "<<endl;
        for(int i=0;i<3;i++){
            cout<<m[i]<<endl;
        }

    }
    int total(){
        int t=0;
        for(int i=0;i<3;i++){
        t+=m[i];}
        return t;

    }
    float average (){
    float a=0;
    int t=0;
    for(int i=0;i<3;i++){
       t+=m[i];
    }
    a=t/3;
    return a;
    }
};
int main(){
    result student;
    student.get();
    student.data();
    cout<<"the total marks of three subjects is "<<student.total()<<endl;
    cout<<"the average is "<<student.average()<<endl;
}