//implement a student class with the private attributes for marks in three subjects.
//add public methods to calculate the total and average marks 
#include<iostream>
using namespace std;
class student{
    private:
    int m[3];
    int total;
    int average;
    int i;
    public:
    void getmarks(){
        for(int i=0;i<3;i++){
        cout<<"enter the marks of "<<"subject "<<i+1<<endl;
        cin>>m[i];}
    }
    void totalmarks(){
         total=0;
        for(int i=0;i<3;i++){
            total+=m[i];
        }
        cout<<"the total marks of three subjects are "<<total<<endl;
         
    } 
    void Average(){
        
            int average=total / 3;
        
        cout<<"the average of marks of three subjects is "<<average;
    }
};
int main(){
student s;
s.getmarks();
s.totalmarks();
s.Average();
}