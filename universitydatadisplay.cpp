#include<iostream>
using namespace std;
    class Person{
        
        
    public:
    string name;
        int age;
    Person(string name ,int age){
        this ->name=name;
        this ->age=age;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }};
    // inheritance 
    class Student:public Person{
        private:
        string studentID;
        public :
        Student (string studentID ,string name,int age):Person(name,age){
            this ->studentID=studentID;
        }
        void display(){
            Person::display();
            cout<<"Student ID: "<<studentID<<endl;
        }
    };
     // inheritance 
     class Teacher:public Person{
        private:
        string teacherID;
        public :
        Teacher(string teacherID ,string name,int age):Person(name,age){
            this-> teacherID=teacherID;
        }
        void display(){
            Person::display();
            cout<<"Teacher ID: "<<teacherID<<endl;
        }
    };
    // Aggregation
    class Department{
        private:
        string deptname ;
        Teacher *teacher;
        public:
        Department(string deptname,Teacher *teacher){
            this ->deptname=deptname;
            this-> teacher =teacher;
        }
        void display(){
            cout<<"Department Name: "<<deptname<<endl;
            teacher->display();
        }


    };
    class Course {
        private:
            string courseName;
            Teacher teacher;  // Teacher object as a member (not reference)
        
        public:
            // Constructor that accepts a Teacher object by reference
            Course(string courseName, Teacher &teacher) : courseName(courseName), teacher(teacher) {
                // Using initializer list to directly initialize the teacher object
            }
        
            void display() {  // Marked as const since it doesn't modify the object
                cout << "Course Name: " << courseName << endl;
                teacher.display();  // Call the teacher's display method
            }
        };
        
    
    class University {
    private:
    string uniname;
    public:
    University(string uniname){
        this ->uniname=uniname;

    }
    void display(){
        cout<<"university Name "<<uniname<<endl;
    }
    void associatestudent(const Student &s1){
        cout<<"Student "<<s1.name<<"is associated with "<<uniname<<endl;
    }
void associateteacher(const Teacher &t1){
    cout<<"Teacher "<<t1.name<<"is associated with the "<<uniname <<endl;
}
    };
    int main(){
       Student s("123","noor",20);
       Teacher t("345","zara",35);
       Department d("CS",&t) ;
       Course c("abc",t);
       University uni("UCP");
       uni.display();
       uni.associatestudent(s);
       uni.associateteacher(t);
       c.display();
       d.display();
    }