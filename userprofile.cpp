#include<iostream>
using namespace std;
class User{
    private:
    string password;
    string username;
    string musername;
    string mpassword;
    string npassword;
    char x;
    public:
    User(string u,string p){
        username=u;
        password=p;
    }
    void login(){
      cout<<"enter the username "<<endl;
      cin>>musername;
      if(username==musername){
        cout<<"enter your password "<<endl;
            cin>>mpassword;
            if(mpassword==password){
                cout<<"login successfully!"<<endl;
            
            }
            else if(password!=mpassword){
               
                for(int i=0;i<2;i++){
                 cout<<"incorrect passord! enter your password again "<<endl;
                cin>>mpassword;}
                if(password!=mpassword){
                    cout<<"you have no more attempts!...change your password "<<endl;
                    cout<<"to change the password press c "<<endl;
                    cin>>x;
                    if(x=='c'||x=='C'){
                        cout<<" enter the new  password that you want to set "<<endl;
                        cin>>npassword;
                        password=npassword;
                        cout<<"password changed successfully "<<endl;
                        cout<<"now enter your new password to login "<<endl;
                        cin>>npassword;
                        if(npassword==password){
                            cout<<"login successfully! "<<endl;
                        }
                    }
                }
            }
        }
      }
      
    };
    
   
int main(){
User u("noor","12345");
u.login();
}