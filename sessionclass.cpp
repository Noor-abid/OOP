#include<iostream>
#include<ctime>
using namespace std;
class Session{
private:
time_t startTime;
time_t endTime;
public:
Session(){
    startTime =time(0);
    cout<<"session started "<<endl;
}
~Session(){
    endTime=time(0);
    cout<<"session ended "<<endl;
    cout<<"Duration: "<< endTime-startTime<<" seconds "<<endl;
}
};
int main(){
Session obj;
for(int i=0;i<500000;i++){
    continue;
}
}