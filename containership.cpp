#include<iostream>
using namespace std;
class Result {
    private:
   int array[3];
   int total=0;
    float average=0.0;
    public:
    void input(){
        cout<<"Enter the marks of 3 subjects: ";
        for(int i=0;i<3;i++){
            cin>>array[i];
        }
    }
    void display (){
        for(int i=0;i<3;i++){
            total+=array[i];
        }
        
        average=total/3;
        cout<<"Total marks: "<<total<<endl;
        cout<<"Average marks: "<<average<<endl;
    }
};
class Student{
    private:
    string roll_no;
    string name;
    Result r;
    public:
    void input(){
        cout<<"Enter the roll number: ";
        cin>>roll_no;
        cout<<"Enter the name: ";
        cin>>name;
        r.input();
    }
    void display(){
        cout<<"Roll number: "<<roll_no<<endl;
        cout<<"Name: "<<name<<endl;
        r.display();
    }
};
int main(){
    Student s;
    s.input();
    s.display();
    return 0;
}
