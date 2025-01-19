#include<iostream>
using namespace std;
class Info{
    private:
    int p;
    int x;
    string username;
    int a[5];
    public:
    void password(){
        cout<<"enter the password"<<endl;
        cin>>p;
        if (p==12345)
        cout<<"Login successfully ! "<<endl;

    }
    void setusername(string x){
        username=x;
    }
    void displaypassword(){
        if(p!=12345){{
            for(int i=0;i<3;i++){
                cout<<"Enter the password again"<<endl;
                cin>>p;
                if(p==12345)
                break;
            
            }}
            if(p!=12345){
            cout<<"Press C to change the password"<<endl;
            char y;
            cin>>y;
            if(y=='C' || y=='c')
            cout<<"enter new password"<<endl;
            cin>>p;
            cout<<"Password changed successfully!"<<endl;
            
        }
        else if(p==12345){
        cout<<"Login successfully!"<<endl;
        cout<<"Welcome "<<username<<"!"<<endl;}
    }
    }
     void inputArray(){
        cout<<"enter the values in array"<<endl;
        for(int i=0;i<5;i++){
            cin>>a[i];
        }
    }
    int displaysum(){
        int sum=0;
        
            cout<<"How many values you want to add"<<endl;
            cin>>x;
            for(int i=0;i<x;i++){
sum+=a[i];

            }
            cout<<"the sum is "<<endl;
            return sum;
        }
void displayMax() {
    int max = a[0];
    for (int i = 1; i < 5; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    cout << "Max value in array: " << max << endl;
}

void displayMin() {
    int min = a[0];
    for (int i = 1; i < 5; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    cout << "Min value in array: " << min << endl;
}


void searchArray() {
    int target;
    cout << "Enter value to search for: ";
    cin >> target;
    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (a[i] == target) {
            found = true;
            break;
        }
    }
    if (found) {
        cout << "Value found in array!" << endl;
    } else {
        cout << "Value not found in array!" << endl;
    }
}
    void checkEvenOdd() {
        int evenCount = 0;
        int oddCount = 0;
        for (int i = 0; i < 5; i++) {
            if (a[i] % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
        cout << "Even values in array: " << evenCount << endl;
        cout << "Odd values in array: " << oddCount << endl;
    }

    void size(){
    int s=0;
    for(int i=0;i<5;i++){
        s++;
    }
    cout<<"the values in array are "<< s <<endl;
    }
};


   
    

int main(){
    Info obj;
    obj.password();
    obj.setusername("BSCS");
    obj.displaypassword();
    obj.inputArray();
   start:
        cout << "Menu:" << endl;
        cout << "Press 1 to display sum of array values" << endl;
        cout << "Press 2 to Display max value in array" << endl;
         cout << "Press 3 to Display min value in array" << endl;
        cout << "Press 4 to Search the values in array" << endl;
        cout << "Press 5 to check even or odd values in an array" << endl;
        cout << "Press 6 to check how many values in an array" << endl;
        cout << "Press 0 to Exit program" << endl;
        int choice;
        cin >> choice;
        switch (choice){
    case 1:
cout<<obj.displaysum()<<endl;
goto start;
    case 2:
obj.displayMax();
goto start;
    case 3:
obj.displayMin();
goto start;
    case 4:
obj.searchArray();
goto start;
    case 5:
obj.checkEvenOdd();
goto start;
    case 6:
obj.size();
goto start;  
    
}}
