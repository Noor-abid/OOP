#include<iostream>
using namespace std;
class Bankaccount{
private:
string depositor_name;
string account_no;
string account_type;
int balance;
int deposited_amount;
public:
Bankaccount(string name, string ac_no ,string ac_type,int totalbalance){
  depositor_name=name;
  account_no=ac_no; 
  account_type=ac_type;
  balance=totalbalance; 
}
int deposit(int amount){
    balance+=amount;
deposited_amount=amount;
return deposited_amount;
}
void display();
};
void Bankaccount::display(){
    cout<<"the name of depositor is "<< depositor_name<<endl;
cout<<"the bank balance with reference to account number "<<account_no << " is "<< balance << endl;

}
int main(){
    Bankaccount  obj("Noor", "000111333" , "Current",300000);
    obj.display();
    obj.deposit(20000);
   cout<<"the current balance after depositing the amount is "<<endl;
    obj.display();
}
