#include<iostream>
#include<fstream>
using namespace std;
class Filehandler{
    private:
    ofstream file;
    public:
    Filehandler(string &myfile){
        file.open(myFile);
        if(file.is_open()){
            cout<<"File opened: "<<myFile<<endl;
        }
        else{
            cout<<"failed to open the file "<<
        }
    }
};
int main(){

}
