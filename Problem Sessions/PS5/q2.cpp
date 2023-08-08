#include <iostream>
#include <string>

using namespace std;

class Student{
    public:
        Student();
        void InputData();
        void OutputData();
        void ResetClasses();
        Student& operator=(const Student& other);
        ~Student();
    private:
        string name;
        int numClasses;
        string *classList;
};

int main()
{
Student s1, s2;
s1.InputData(); // Input data for student 1
cout << "Student 1's data:" << endl;
s1.OutputData(); // Output data for student 1
cout << endl;
s2 = s1;
cout << "Student 2's data after assignment from student 1:" << endl;
s2.OutputData(); // Should output same data as for student 1
s1.ResetClasses();
cout << "Student 1's data after reset:" << endl;
s1.OutputData(); // Should have no classes
cout << "Student 2's data, should still have original classes:" << endl;
s2.OutputData(); // Should still have original classes
cout << endl;
return 0;
}

Student::Student(){
    name = "";
    numClasses=0;
    classList = NULL;

}

void Student::InputData(){
    cin>>(this->name);
    cin>>(this->numClasses);
    cin.ignore();
    classList = new string[this->numClasses];
    string line;
    for (int i = 0; i < numClasses; i++){
        cin>>line;
        classList[i] = line;

    }

}

void Student::OutputData(){
    cout << "Name: " << name << std::endl;
    cout << "Classes: ";
    for (int i = 0; i < numClasses; i++) {
        cout << classList[i];
        if (i < numClasses-1) {
            cout << ", ";
        }
    }
    cout<< endl;
}
void Student::ResetClasses(){
    delete[] classList;
    numClasses = 0;
    classList = NULL;
}

Student& Student::operator=(const Student& other) {
        if (this != &other) {
            delete[] classList;
            name = other.name;
            numClasses = other.numClasses;
            classList = new string[numClasses];
            for (int i = 0; i < numClasses; i++) {
                classList[i] = other.classList[i];
            }
        }
        return *this;
}

Student::~Student(){
    delete [] classList;
}
