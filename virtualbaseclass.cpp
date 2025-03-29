#include<iostream>
using namespace std;
class person{   
public:
string name;
person(){
   name="noor"; 
}
};
class Administration:virtual public person{};
class LibraryStaff:virtual public person{};
class Professor:public Administration,public LibraryStaff{};
int main(){
    Professor p;
    cout<<"name: "<<p.name;
}