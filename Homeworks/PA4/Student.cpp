#include <iostream>
#include "Student.h"
#include "Course.h"
using namespace std;

namespace PA4
{
    Student::Student()
    {
        //BLANK
    }
    Student::Student(string name, string ID)
    {
        name = name;
        ID = ID;

        size = 0;
        capacity = 1;
        takenCourses = new Course[capacity];
    }
    

    Student::~Student()
    {
        delete[] takenCourses;
    }

    string Student::getName() const
    {
        return name;
    }

    string Student::getID() const
    {
        return ID;
    }

    string Student::setName(string newName)
    {   string temp = name;
        name = newName;
        return temp;
    }

    string Student::setID(string newID)
    {
        string temp = ID;
        ID = newID;
        return temp;
    }
    int Student::getSize() const
    {
        return size;
    }

    Course* Student::takeCourse() const
    {
        return takenCourses;
    }

    void Student::addCourse(Course newCourse)
    {
        if(size==capacity)
        {
            growCourse();
        }

        takenCourses[size] = newCourse;
        size++;
    }

    void Student::deleteCourse(Course deleteCourse)
    {
        int index = getIndex(deleteCourse);

        for(int i=index;i<size;i++)
        {
            takenCourses[i] = takenCourses[i+1];
        }

        //takenCourses[size-1] = NULL;
        size--;
    }

    void Student::growCourse()
    {
        Course*  temp = new Course[capacity*2];

        for(int i=0;i<size;i++)
        {
            temp[i]=takenCourses[i];
        }

        delete takenCourses;
        takenCourses = temp;
        capacity = capacity*2;
    }

    int Student::getIndex(Course courseC)
    {
        for(int i=0; i<size;i++)
        {
            if(takenCourses[i].getName()==courseC.getName() &&  takenCourses[i].getCode()==courseC.getCode())
                return i;
            
        }
        return -1;
    }



    bool operator==(Student &main ,Student &other)
    {
        return main.getName()==other.getName() && main.getID()==other.getID();
    }

    ostream &operator>>(ostream &os, Student &stu)
    { 
        for(int i=0;i<stu.getSize();i++)
        {
            os << stu.takenCourses[i].getName() << " " << stu.takenCourses[i].getCode()<< endl;

        }
        return os;
    }

}