#include<iostream>
using namespace std;
class college{
private:
 string college_id;
 string college_name;
 int no_of_classes=5;
 int strength[5];
 int setstrength;
 int total=0;
 int additional;
 int expected_strength;
  
 public:
 void get(){
    cout<<"enter the name of college "<<endl;
    cin>>college_name;
    cout<<"enter the id of college"<<endl;
    cin>>college_id;

}
 void getstrength(){
    cout<<"enter the strength of each class "<<endl;
for(int i=0;i<no_of_classes;i++){
    cout<<"the strength of class "<< i+1 <<" is "<<endl;
    cin>>strength[i];
 }
 }
 void show(){
    cout<<"college name is "<<college_name<<endl;
    cout<<"college id is "<<college_id<<endl;
    cout<<"total no of classes in college are "<<no_of_classes<<endl;
    for(int i=0;i<no_of_classes;i++){
    cout<<"the strength of class "<< i+1 <<" is "<<strength[i]<<endl;
    
 }
 }
 void sum(){
     total=0;
    for(int i=0;i<no_of_classes;i++){
        total+=strength[i];
        
    }
    cout<<"the total strenth is "<<total<<endl;
 }
 void collegestrength(int setstrength) {
      
      expected_strength = setstrength; 
   
        if (expected_strength == total)
            cout << "Strength is okay" << endl;
        else
            cout << "Strength is not okay" << endl;
 }
 void Rem_capacity(){
    if(total<expected_strength){
    additional=expected_strength-total;
    cout<<"there is still space for "<< additional  <<" students "<<endl;}
    else
    cout<<"No more capacity for additional student"<<endl;
 }

void minstrength() {
    int min = strength[0];
    for (int i = 0; i < no_of_classes; i++) {
        if (strength[i] < min) {
            min = strength[i];
        }
    }
    cout << "Min strength of class is: " << min << endl;
}
void maxstrength() {
    int max = strength[0];
    for (int i = 0; i < no_of_classes; i++) {
        if (strength[i] > max) {
            max = strength[i];
        }
    }
    cout << "Max strength of class is: " << max << endl;
}


};
int main(){
    college obj;
    obj.get();
    obj.getstrength();
    obj.show();
    obj.sum();
    obj.collegestrength(250);
    obj.Rem_capacity();
    obj.minstrength();
    obj.maxstrength();
}