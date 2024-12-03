#include<iostream>
using namespace std;
void swap(int &a ,int &b){
    int t;
    t=a;
    a=b;
    b=t;
    cout<<"the swapped values are x="<< a <<" "<<"y="<< b<<endl;

}
int main(){
    int x=10,y=20;
    swap(x,y);
    
}