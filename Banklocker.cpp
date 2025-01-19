//design a Banklocker class where only the authorized can open the locker.
//use encapsulation to secure the lock combination  
#include<iostream>
using namespace std;
class Banklocker{
    private:
    string combination;
    bool isOpen;
    public:
    Banklocker(string combo){
        combination=combo;
        isOpen=false;
    }
    void open(string combo){
        if (combo==combination){
            isOpen=true;
            cout<<"Locker opened successfully! "<<endl;
        }
        else {
            cout<<"Invalid Combination "<<endl;
        }
    }
    void close(){
        isOpen=false;
        cout<<"Locker closed successfully "<<endl;
    }
    void status(){
        if(isOpen){
            cout<<"locker is open "<<endl;
        }
        else{
            cout<<"locker is closed "<<endl;
        }
    }
};
int main(){
Banklocker locker("n34f6");
locker.status();
locker.open("n34f6");
locker.status();
locker.close();
locker.status();
}