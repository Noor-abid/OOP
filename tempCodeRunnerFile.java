#include<iostream>
using namespace std;
class college{
private:
 string college_id;
 string college_name;
 int no_of_classes=5;
 int strength[100];
 int setstrength={25,30,40,45,50}
 public:
 void get(){
    cout<<"enter the name of college "<<endl;
    cin>>college_name;
    cout<<"enter the id of college"<<endl;
    cin>>college_id;

}
 void getstrength(){
    cout<<"enter the strength of each class "<<endl;
for(int i=1;i<=no_of_classes;i++){
    cout<<"the strength of class "<< i <<" is "<<endl;
    cin>>strength[i];
 }
 }
 void show(){
    cout<<"college name is "<<college_name<<endl;
    cout<<"college id is "<<college_id<<endl;
    cout<<"total no of classes in college are "<<no_of_classes<<endl;
    for(int i=1;i<=no_of_classes;i++){
    cout<<"the strength of class "<< i <<" is "<<strength[i]<<endl;
    
 }
 }
 int sum(){
    int total=0;
    for(int i=1;i<=no_of_classes;i++){
        total+=strength[i];
        
    }
    return total;
 }
};
int main(){
    college obj;
    obj.get();
    obj.getstrength();
    obj.show();
    cout<<"the total strength is "<<obj.sum();
}