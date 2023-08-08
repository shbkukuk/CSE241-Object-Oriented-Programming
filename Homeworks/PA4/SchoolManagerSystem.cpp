#include <iostream>
using namespace std;
#include "SchoolManagerSystem.h"
namespace
{
    //helper functions: 
    bool isNumber(const string& str)
    {
        for(char c : str){
        if(!isdigit(c)){
            return false;
            }
        }
    return true;
    }
}

namespace PA4
{
    istream& operator>>(istream& inputStream, SchoolManagerSystem& sys)
    {
        string name;
        string fullname;
        string id;

        inputStream >> name;
        while (!isNumber(name))
        {
            
            fullname += name + " ";
            inputStream>>name;
        }
        id = name;
        sys.setName(fullname);
        sys.setID(id);
       
    return inputStream;

    }

    bool operator == (const Student& tempstudent,  SchoolManagerSystem& sys)
    {
        if(tempstudent.getName()==sys.nameStudent && tempstudent.getID()== sys.idStudent)
            return true;
        return false;
    }
    void SchoolManagerSystem::setName(string newName)
    {
        nameStudent = newName;
    }

    void SchoolManagerSystem::setID(string newID)
    {
        idStudent = newID;
    }
    
    SchoolManagerSystem::SchoolManagerSystem()
    {

        capacityStudent = 1;
        sizeStudent = 0;
        enrollStudent = new Student[capacityStudent];

        capacityCourse = 1;
        sizeCourse = 0;
        takenCoursesz = new Course[capacityCourse];
    }
    
    SchoolManagerSystem::~SchoolManagerSystem()
    {
        delete [] enrollStudent;
        delete [] takenCoursesz;
    }
    
    void SchoolManagerSystem::mainMenu()
    {
        string select;
        cout<<"Main_menu "<<endl;
        cout<<"0 exit\n" << "1 student\n" << endl; 
        cin>>select;

        if(!isNumber(select))
        {
            mainMenu();

        }
        else
        {
            int chosee = stoi(select);
            switch (chosee)
            {
            case 0:
                exit(1);
                break;
            case 1:
                studentMenu();
                break;
            case 2:
                courseMenu();
                break;
            case 3:
                listAllStudent();
                break;
            case 4:
                listAllCourses();
                break;
            default:
                mainMenu();
                break;
            }
        }
            
        mainMenu();
    }

    void SchoolManagerSystem::studentMenu()
    {   
        string select;
        cout<<"0 up"<<endl;
        cout<<"1 add_student\n"<<"2 select_student\n"<<endl;
        cin>>select;
        if(!isNumber(select))
        {
            studentMenu();
        }
            
        else
        {
            int chosee = stoi(select);
            switch (chosee)
            {
            case 0:
                mainMenu();
                break;
            case 1:
                addStudent();
                break;
            case 2:
                selectStudent();
                break;
            default:
                studentMenu();
                break;
            }
        }
        studentMenu();   
    }

    void SchoolManagerSystem::addStudent()
    {
        cin>>*this;
        Student  newStudent = Student(nameStudent,idStudent);
        if(sizeStudent==capacityStudent)
        {
            growArrayStudent();
        }
        enrollStudent[sizeStudent] = newStudent;
        sizeStudent++;
        
        
        studentMenu();

    }
    void SchoolManagerSystem::growArrayStudent()
    {
        Student* tempt = new Student[capacityStudent*2];
        for(int i=0; i<sizeStudent;i++)
        {
            tempt[i] = enrollStudent[i];
        }

        delete[] enrollStudent;
        enrollStudent = tempt;
        capacityStudent = capacityStudent*2;
    }

    void SchoolManagerSystem::selectStudent()
    {
        cin>>*this;
        cout<<"0 up"<<endl;
        cout<<"1 delete_student\n "
        <<"2 add_selected_student_to_a_course\n "<<"3 drop_seleceted_student_from_a_course\n"
        <<endl; 

        string select;
        cin>>select;
        if(!isNumber(select))
        {
            selectStudent();
        }
        else
        {
            int choose = stoi(select);
            switch (choose)
            {
            case 0:
                studentMenu();
                break;
            case 1:
                deleteStudent();
                break;
            case 2:
                enrollCourse();
                break;
            case 3:
                dropCourse();
                break;
            default:
                selectStudent();
                break;
            }
        }
    }

    void SchoolManagerSystem::deleteStudent()
    {
        int ind = indexStudent();
        //delete enrollStudent[ind];
        for(int i=ind; i<sizeStudent;i++)
        {
            enrollStudent[i] = enrollStudent[i+1];

        }
        //enrollStudent[sizeStudent-1]= NULL;

        sizeStudent--;

        selectStudent();
    }

    void SchoolManagerSystem::enrollCourse()
    {
        cout<<"0 up"<<endl;
        for(int i=0; i<sizeCourse; i++)
        {
            cout<<i+1<<" "<<takenCoursesz[i].getCode()<<" "<<takenCoursesz[i].getName()<<endl;
        }
        int choose;
        cin>>choose;
        if (choose==0)
        {
            selectStudent();
        }
        else
        {
            int ind = indexStudent();
            enrollStudent[ind].addCourse(takenCoursesz[choose-1]);
            takenCoursesz[choose-1].addStudent(enrollStudent[ind]);
        }

    }

    void SchoolManagerSystem::dropCourse()
    {
        int ind = indexStudent();
        cout<<"0 up" <<endl;

        Course* temps = enrollStudent[ind].takeCourse();
        int sizeC = enrollStudent[ind].getSize();

        for(int i=0; i<sizeC;i++)
        {
            cout<<i+1<<" "<<temps[i].getCode() << " "<<temps[i].getName()<<endl;
        }

        int chose;
        cin>>chose;

        if(chose==0)
        {
            selectStudent();
        }
        else
        {
            enrollStudent[ind].deleteCourse(temps[chose-1]);
            temps[chose-1].deleteStudent(enrollStudent[ind]);
        }

        selectStudent();
    }

    void SchoolManagerSystem::courseMenu()
    {
        cout<<"0 up"<<endl;
        cout<<"1 add_course\n"<<"2 select_Course\n"<<endl;
        int choose;
        cin>>choose;
        switch (choose)
        {
        case 0:
            mainMenu();
            break;
        case 1:
            addCourse();
            break;
        case 2:
            selectCourse();
            break;
        default:
            courseMenu();
            break;
        }
        courseMenu();
    }

    void SchoolManagerSystem::addCourse()
    {
        getCourseCodeName(cin);
        Course newCourse = Course(course,code);

        if(sizeCourse==capacityCourse)
        {
            growArrayCourse();
        }

        takenCoursesz[sizeCourse] = newCourse;
        sizeCourse++;
        courseMenu();
    }

    void SchoolManagerSystem::selectCourse()
    {
        getCourseCodeName(cin);
        cout<<"0 up"<<endl;
        cout<<"1 delete_course\n"<<
            "2 list_students_registered_to_the_selected_course\n"<<endl;
        int chose;
        cin>>chose;

        switch (chose)
        {
        case 0:
            courseMenu();
            break;
        case 1:
            deleteCourse();
            break;
        case 2:
            listStudentCourse();
            break;
        default:
            selectCourse();
            break;
        }
        selectCourse();
    }
    void SchoolManagerSystem::deleteCourse()
    {
        int index = indexCourse();
        for(int i=index; i<sizeCourse; i++)
        {
            takenCoursesz[i] = takenCoursesz[i+1];

        }
        //takenCoursesz[takenCoursesz-1]= NULL;

        takenCoursesz--;

        selectCourse();

    }
    void SchoolManagerSystem::listStudentCourse()
    {
        int index = indexCourse();
        Course selected = takenCoursesz[index];
        cout << selected;

        selectCourse();
    }

    void SchoolManagerSystem::listAllCourses()
    {
        for(int i=0; i<sizeCourse;i++)
        {
            cout <<" "<<takenCoursesz[i].getCode()  <<" "<<takenCoursesz[i].getName() <<endl; 
        }

        mainMenu();
    }

    void SchoolManagerSystem::listAllStudent()
    {
        for(int i=0; i<sizeStudent;i++)
        {
            cout <<" "<<enrollStudent[i].getID()  <<" "<<enrollStudent[i].getName() <<endl; 
        }

        mainMenu();
    }

    void SchoolManagerSystem::growArrayCourse()
    {
        Course* tempt = new Course[capacityCourse*2];
        for(int i=0; i<sizeCourse;i++)
        {
            tempt[i] = takenCoursesz[i+1];
        }

        delete[] takenCoursesz;
        takenCoursesz = tempt;
        capacityCourse = capacityCourse*2;
    }
    void SchoolManagerSystem::getCourseCodeName(istream& input)
    {   string combined;
        string name;
        input>>code;
        while (input>>name)
        {
            combined += name + " "; 
        }
        course = combined;
    }


    int SchoolManagerSystem::indexStudent()
    {
        for(int i=0; i<sizeStudent; i++)
        {
            if(enrollStudent[i]==*this)
                return i;
        }
        return -1;
    }

    int SchoolManagerSystem::indexCourse()
    {
        for(int i=0; i<sizeCourse;i++)
        {
            if(takenCoursesz[i].getName()==course &&  takenCoursesz[i].getCode()==code)
                return i;
            
        }
        return -1;
    }


}

