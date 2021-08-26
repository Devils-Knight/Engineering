#include <bits/stdc++.h>
using namespace std;

class Student{

    static int count;

    string name;
    int roll_no;
    string Class;
    string DOB;
    string blood_grp;
    string address;
    long long phone_no;
    string driving_license;

    public:
        Student(){
            count += 1;
        }

        Student(const Student &stu){  // copy constructor
            name = stu.name;
            roll_no = stu.roll_no;
            Class = stu.Class;
            DOB = stu.DOB;
            blood_grp = stu.blood_grp;
            address = stu.address;
            phone_no = stu.phone_no;
            driving_license = stu.driving_license;
            count += 1;
        }
        ~Student(){  // destructor

        }

        inline static int total_students(){
            return count;
        }

        int compare_roll_no(Student &stu){
            return this->roll_no > stu.roll_no;
        }

        void getDetails(){
            cout << endl << "Enter the student details ......." << endl;
            cout << "Name:";
            cin.ignore();
            getline(cin, name);
            cout << "Roll number:"; 
            cin >> roll_no;
            cout << "Class:" ; 
            cin >> Class;
            cout  << "Date of Birth: "; 
            cin >> DOB;
            cout  << "Blood group: "; 
            cin >> blood_grp;
            cout << "Address: "; 
            // cin >> address;
            cin.ignore();
            getline(cin, address);
            cout  << "Phone number: "; 
            cin >> phone_no;
            cout << "Driving License: ";
            cin >> driving_license;
            cout << endl;
        }

        void showDetails(){
            cout << endl << "The Student details are as follow: " << endl;
            cout << "Name: " << name << endl;
            cout << "Roll number: " << roll_no << endl;
            cout << "Class: " << Class << endl;
            cout << "Date of Birth: " << DOB << endl;
            cout << "Blood group: " << blood_grp << endl;
            cout << "Address: " << address << endl;
            cout << "Phone number: "<< phone_no << endl;
            cout << "Driving Lisence: " << driving_license << endl;
        }

        friend class secondary;

};

int Student::count = 0;

class secondary{
    private:
        int sec;

    public:
        secondary(){
            sec = 0;
        }

        void show(Student &stu){
            cout << "Name of the student through friend class: " << stu.name << endl;
        }

};



int main(){


    Student S, P;
    S.getDetails();
    S.showDetails();
    P.getDetails();
    P.showDetails();


    Student Q = S;  
    cout << endl << "Student details using copy constructor" << endl;
    Q.showDetails();


    if (P.compare_roll_no(S)){
        cout << "Roll no of P is greater than that of S" << endl;
    }
    else{
        cout << "Roll no of P is smaller than S" << endl;
    }


    int size{0};
    cout << endl << "Enter the number of students in the group: ";
    cin >> size;


    // dynamic memory allocation
    Student *group = new(nothrow) Student[size];
    for (int i=0; i < size; ++i){
        group[i].getDetails();
    }

    delete[] group;

    cout << "Total Students are: " << Student::total_students() << endl;

    secondary alpha;
    alpha.show(S);


    return 0;
}