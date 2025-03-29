#include<iostream>
using namespace std ;
class Payment {
    public:
    virtual void payAmount()=0;
};
class CreditCard:public Payment {
    private:
    int money;
    public :
    CreditCard(){
        cout<<"enter the money you want to deduct via creditcard ";
        cin>>money;
    }
void payAmount()override{
    cout<<"the money deducted via card is: "<<money<<endl;
}
};
class Paypal:public Payment {
    private:
    int money2;
    public :
    Paypal(){
        cout<<"enter the money you want to deduct via paypal ";
        cin>>money2;
    }

void payAmount()override{
    cout<<"the money deducted via Paypal is: "<<money2<<endl;
}
};

int main(){
    Payment *obj=new CreditCard();
    
    obj->payAmount();
    Payment *obj1=new Paypal();
    
    obj1->payAmount();

}
