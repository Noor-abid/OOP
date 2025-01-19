//create a wallet class with the private attribute for the balance. Write methods to add money
//and check the current balance, ensuring that balance can't be set directly  
#include<iostream>
using namespace std;
class Wallet{
    private:
int balance;
int money;
public:
Wallet(){
    balance=0;
}
void getbalance(){
    cout<<"enter the balance"<<endl;
    cin>>balance;
}
int Add(){
    cout<<"enter the money you want to add in your wallet"<<endl;
    cin>>money;
    balance+=money;
    return balance;
}
void Currentbalance(){
    if(balance==0){
        cout<<"your wallet is currently empty "<<endl;
    }
    else
    cout<<"the current balance is: "<<balance<<endl;;
   
}

};
int main(){
Wallet w;
w.getbalance();
w.Add();
w.Currentbalance();

}