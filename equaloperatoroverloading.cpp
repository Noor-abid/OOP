#include<iostream>
using namespace std;
class Array{
    private:
    int a[5];
    public:
    Array(){
         for(int i=0;i<5;i++){
            a[i]=-1;
        }
    }
    void get(){
        cout<<"enter the value "<<endl;
        for(int i=0;i<5;i++){
            cin>>a[i];
        }
    }  
    void display(){
        for (int i=0;i<5;i++){
            cout<<"the value of index "<<i+1<<" is: "<<a[i]<<endl;
        }
    }  
    bool operator==(const Array x){
        for(int i=0;i<5;i++){
        if(a[i]==x.a[i]){
            return true;
        }
            else 
            return false ;
        }
    }
};
int main(){
Array arr1,arr2;
arr1.get();
arr2.get();

arr1.display();
cout<<endl;
 arr2.display();
cout<<endl;
if(arr1==arr2){
    cout<<"Both arrays have the same values "<<endl;
}
else{
    cout<<"Both arrays have the different values "<<endl;
}
}