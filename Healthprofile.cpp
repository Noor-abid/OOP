#include<iostream>
using namespace std;
class HealthProfile{
    private:
float height;
float weight;
float bmi;
public:
HealthProfile(float height,float weight){
this->height=height;
this->weight=weight;
}

 float calculateBMI(){
    if(height>0 && weight>0){
        return weight/(height*height);
    }
       
    else {
        return -1;
        cout<<"invalid height";
    }
}
void profiledisplay(){
   cout<<"height: "<<height<<endl;
   cout<<"weight: "<<weight<<endl;
   float bmi=calculateBMI();
   if (bmi!=-1){
    cout<<"BMI "<<bmi<<endl;
   }
}
};
int main(){
HealthProfile p(2000,45);
p.calculateBMI();
p.profiledisplay();
}