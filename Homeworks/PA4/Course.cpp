#include <iostream>
#include "Course.h"
#include "Student.h"
using namespace std;

namespace PA4
{
    Course::Course()
    {
        //BLANK
    }
    Course::Course(string coursName, string code)
    {
        courseName = coursName;
        code = code;
        size = 0;
        capacity = 1;

        enrollStudents = new Student[capacity];
    }

    Course::~Course()
    {
        delete[] enrollStudents;
    }
    string Course::getName() const
    {
        return courseName;
    }

    string Course::getCode() const
    {
        return code;
    }

    string Course::setName(string newName)
    {   string temp = courseName;
        courseName = newName;
        return temp;
    }

    string Course::setCode(string newCode)
    {
        string temp = code;
        code = newCode;
        return temp;
    }

    void Course::addStudent(Student newStudent)
    {
        if(size==capacity)
        {
            growStudent();
        }

        enrollStudents[size] = newStudent;
        size++;
    }

    void Course::growStudent()
    {
        Student*  temp = new Student[capacity*2];

        for(int i=0;i<size;i++)
        {
            temp[i]=enrollStudents[i];
        }

        delete enrollStudents;
        enrollStudents = temp;
        capacity = capacity*2;
    }
    void Course::deleteStudent(Student deleteStudent)
    {
        int index = getIndex(deleteStudent);

        for(int i=index;i<size;i++)
        {
            enrollStudents[i] = enrollStudents[i+1];
        }

        //enrollStudents[size-1] = NULL;
        size--;
    }

    int Course::getIndex(Student studentC)
    {
        for(int i=0; i<size;i++)
        {
            if(enrollStudents[i].getName()==studentC.getName() &&  enrollStudents[i].getID()==studentC.getID())
                return i;
            
        }
        return -1;
    }

    bool operator == (Course &main, Course &other)
    {
        return main.getName() == other.getName()&& main.getCode()==other.getCode();
    }

    ostream& operator<<(ostream& os, Course &course)
    {
        for(int i=0;i<course.size;i++)
        {
            os << course.enrollStudents[i].getName() << " " << course.enrollStudents[i].getID()<< endl;

        }
        return os;
    }

}
