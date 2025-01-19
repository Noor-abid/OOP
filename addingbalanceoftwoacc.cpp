#include<iostream>
using namespace std;
class Bankaccount  {
    private:
    static int count;
    string name;
    int account_num;
    string acc_type;
    int balance;
    int  withdrawal_amount;
    int deposited_amount;
    public:
    Bankaccount(){
        cout<<"enter the name of the depositor: ";
        cin>>name;
        cout<<"enter the account number: ";
        cin>>account_num;
        cout<<"enter account type: ";
        cin>>acc_type;
        cout<<"enter the balance of the account: ";
        cin>>balance;
        count++;
    }
    void withdraw(int w){
        if (w<=balance){
        withdrawal_amount=w;
        balance-=withdrawal_amount;
        cout<<"the withdrawal amount is: "<<withdrawal_amount<<endl;
        }
        else 
        cout<<"Sorry! Insufficient balance for withdrawal "<<endl;

    }
    void deposit(int d ){
        deposited_amount=d;
        balance+=deposited_amount;
        cout<<"the deposited amount is: "<<deposited_amount<<endl; 
    }
    void display(){
        cout<<"the name of the depositor is: "<<name<<endl;
        cout<<"the accountype is: "<<acc_type<<endl;
        cout<<"the account number is: "<<account_num<<endl;
    }
    void displaybalance(){
        cout<<"The balance is: "<<balance<<endl;
    }
   int  operator+(Bankaccount &obj2){
        
       return balance+obj2.balance;
       
    }
    static int getcount(){
        return count;
    }
};
int Bankaccount::count=0;
int main(){
Bankaccount obj1,obj2;
cout<<" "<<endl;
cout<<"Account 1 "<<endl;
obj1.display();
obj1.displaybalance();
obj1.deposit(5000);
obj1.displaybalance();
obj1.withdraw(7000);
obj1.displaybalance();
cout<<" "<<endl;
cout<<"Account 2: "<<endl;
obj2.display();
obj2.displaybalance();
obj2.deposit(3000);
obj2.displaybalance();

 int total_balance=obj1+obj2;
cout<<"Total balance of both the accounts is: "<<total_balance<<endl;

 cout<<"the total number of bank accounts are "<<Bankaccount::getcount()<<endl;

}