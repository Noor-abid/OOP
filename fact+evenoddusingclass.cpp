#include<iostream>
using namespace std;
class check{
    private:
    int n;
    int a; 
    public:
        int fact(int n){
        if (n==0)
        return 1;
        else 
        return n*fact(n-1);
    }
    string checkit (){
        cout<<"enter the number to check if its even or odd"<<endl;
        cin>>a;
    
        if(a%2==0)
        return "even" ;
        else 
        return "odd";
    }

};
int main(){
    check n1;
   cout<<"the factorial of 4 is"<< n1.fact(4)<<endl;
    
    cout<<n1.checkit();
}