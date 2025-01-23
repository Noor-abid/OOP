#include<iostream>
#include<fstream>
using namespace std;

class Filehandler{
private:
    ofstream file;
public:
    Filehandler(string &myfile){
        file.open(myfile);
        if(file.is_open()){
            cout<<"File opened: "<<myfile<<endl;
        } else{
            cout<<"Failed to open the file "<<myfile<<endl;
        }
    }

    ~Filehandler(){
        if (file.is_open()){
            file.close();
            cout<<"File closed"<<endl;
        }
    }

    void writeData(const string &data){
        if(file.is_open()){
            file<<data<<endl;
            cout<<"Data written to file: "<<data<<endl;
        } else {
            cout << "Failed to write data to file." << endl;
        }
    }
};

int main() {
    string filename = "obj.txt";
    Filehandler fileHandler(filename);
    fileHandler.writeData("Hello, World!");
    return 0;
}
