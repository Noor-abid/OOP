#include<iostream>
using namespace std;
class Info{
private:
int p;
public:
void password(){
    cout<<"enter the password"<<endl;
    cin>>p;
    
}
void displaypassword(){
    if(p!=12345){
    for(int i=0;i<3;i++){
        cout<<" enter the password again"<<endl;
    }
    cout<<"press C to change the password "<<endl;}
    
}
};
int main(){
    Info obj;
    obj.password();
    obj.displaypassword();
}