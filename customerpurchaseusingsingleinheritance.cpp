  #include<iostream>
  using namespace std;
  class CustomerData{
    protected:
    long CustomerNumber;
    string MailingAddress;
    public:
     void InputCustomerData(){
        cout<<"enter the contact number of customer ";
        cin>>CustomerNumber;
        cin.ignore();
        cout<<"enter the mailing address of customer: ";
       getline(cin,MailingAddress);
        
    }
    void DisplayCustomerData(){
        cout<<"Details of Customer: "<<endl;
        cout<<"Customer's number: "<<CustomerNumber<<endl;
        cout<<"Mailing Address: "<<MailingAddress<<endl;
    }
  };
  class PrefferedCustomer:public CustomerData{
    private:
    double purchasesamount;
    double discountLevel;
    double discountamount;
    public:
    void InputCustomerData(){
      CustomerData::InputCustomerData();
      cout<<"Enter the total purchase made by the customer($): ";
      cin>>purchasesamount;
    }
    void Discountplan(){
if(purchasesamount>=500){
  discountLevel=5.0;
}
else if(purchasesamount>=1000){
  discountLevel=6.0;
}
else if(purchasesamount>=1500){
  discountLevel=7.0;
}
else if(purchasesamount>=2000){
  discountLevel=10.0; 
}
else {
  discountLevel=0.0;

 }
    }
    void DisplayCustomerData(){
      CustomerData::DisplayCustomerData();
      cout<<"Customer made the purchase of total "<<purchasesamount<<"$ "<<endl;
      if(discountLevel==0.0){
        cout<<"Sorry! Please made the purchase of atleast 500$ to be eligible for discount "<<endl; 
      }
      else{
      cout<<" Total of "<<discountLevel <<"% discount is offered to the customer on future purchases "<<endl;}
    }
  };
  int main(){
PrefferedCustomer obj;
obj.InputCustomerData();
obj.Discountplan();
obj.DisplayCustomerData();
  }