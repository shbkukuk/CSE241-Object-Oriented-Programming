#ifndef SCHOOLMANAGERSYSTEM_H
#define SCHOOLMANAGERSYSTEM_H

#include <iostream>
#include "Course.h"
#include "Student.h"
using namespace std;


namespace PA4
{
    /**
     * @class SchoolManagerSystem
     * @brief This class represents a school management system.
     */
    class SchoolManagerSystem
    {
    protected:
        /* data */
        int sizeCourse;        ///< Current size of the course array
        int capacityCourse;  ///< Maximum capacity of the course array
        int sizeStudent;     ///< Current size of the student array
        int capacityStudent;  ///< Maximum capacity of the student array
        string nameStudent; ///< Name of the student
        string idStudent; ///< ID of the student
        string course; ///< Course name 
        string code; ///< Course code
    
        Student* enrollStudent;  ///< Pointer to the array of enrolled students
        Course* takenCoursesz;   ///< Pointer to the array of taken courses
    public:
         /**
         * @brief Constructor for SchoolManagerSystem class.
         */
        SchoolManagerSystem();

        /**
         * @brief Destructor for SchoolManagerSystem class.
         */
        ~SchoolManagerSystem();

        /**
         * @brief Sets the name of the student.
         * @param newName The new name of the student.
         */
        void setName(string newName);

        /**
         * @brief Sets the ID of the student.
         * @param newID The new ID of the student.
         */
        void setID(string newID);

        /**
         * @brief Displays the main menu of the system.
         */
        void mainMenu();

        /**
         * @brief Displays the student menu of the system.
         */
        void studentMenu();

        /**
         * @brief Displays the course menu of the system.
         */
        void courseMenu();

        /**
         * @brief Adds a new student to the system.
         */
        void addStudent();

        /**
         * @brief Selects a student from the system.
         */
        void selectStudent();

        /**
         * @brief Deletes a student from the system.
         */
        void deleteStudent();

        /**
         * @brief Enrolls a student in a course.
         */
        void enrollCourse();

        /**
         * @brief Drops a course from a student's schedule.
         */
        void dropCourse();

        /**
         * @brief Adds a new course to the system.
         */
        void addCourse();

        /**
         * @brief Selects a course from the system.
         */
        void selectCourse();

        /**
         * @brief Deletes a course from the system.
         */
        void deleteCourse();

        /**
         * @brief Lists all courses taken by a student.
         */
        void listStudentCourse();

        /**
         * @brief Lists all students in the system.
         */
        void listAllStudent();

        /**
         * @brief Lists all courses in the system.
         */
        void listAllCourses();

        //helper function

        /**
         * @brief Increases the size of the student array.
         */
        void growArrayStudent();

        /**
         * @brief Increases the size of the course array.
         */
        void growArrayCourse();

        /**
         * @brief Returns the index of the selected student.
         * @return The index of the selected student.
         */
        int indexStudent();

        /**
         * @brief Returns the index of the selected course.
         * @return The index of the selected course.
         */
        int indexCourse();

        /**
         * @brief Gets the course code and name from input stream.
         * @param input The input stream to get the course code and name from.
         */
        void getCourseCodeName(istream& input);

        /**

        * @brief Overloads the >> operator for the SchoolManagerSystem class.
        * @param inputStream The input stream to read from.
        * @param sys The SchoolManagerSystem object to read into.
        * @return The input stream.
        */
        friend istream& operator>>(istream& inputStream,  SchoolManagerSystem& sys);

        /**

        * @brief Overloads the == operator for the Student class and SchoolManagerSystem class.
        * @param tempstudent The Student object to compare.
        * @param sys The SchoolManagerSystem object to compare.
        * @return True if the student is enrolled in the system, false otherwise.
        */
        friend bool operator == (const Student& tempstudent,  SchoolManagerSystem& sys);
        
    };
}








#endif