#ifndef COURSE_H
#define COURSE_h

#include <iostream>
#include "Student.h"
using namespace std;
namespace PA4
{   
    /**
     * @brief A class representing a course.
     * */
    class Course
    {
        public:

            Course();

             /**
             * @brief Constructor for Course class.
             * @param courseName The name of the course.
             * @param code The code for the course.
             */
            Course(string courseName, string code);

            /**
             * @brief Destructor for Course class.
             */
            ~Course();

            /**
             * @brief Get the name of the course.
             * @return The name of the course.
             */
            string getName() const;

            /**
             * @brief Get the code for the course.
             * @return The code for the course.
             */
            string getCode() const;

            /**
             * @brief Set the name of the course.
             * @param newName The new name for the course.
             * @return The updated name of the course.
             */
            string setName(string newName);

            /**
             * @brief Set the code for the course.
             * @param newCode The new code for the course.
             * @return The updated code for the course.
             */
            string setCode(string newCode);

            /**
             * @brief Get the index of a given student in the list of enrolled students.
             * @param studentC The student to look for.
             * @return The index of the student if found, -1 otherwise.
             */
            int getIndex(Student studentC);

            /**
             * @brief Add a new student to the list of enrolled students.
             * @param newStudent The new student to add.
             */
            void addStudent(Student newStudent);

            /**
             * @brief Remove a student from the list of enrolled students.
             * @param deleteStudent The student to remove.
             */
            void deleteStudent(Student deleteStudent);

            /**
             * @brief Increase the capacity of the array of enrolled students.
             */
            void growStudent();

            /**
             * @brief Overloads the << operator to output information about a course.
             * @param os The output stream to write to.
             * @param course The course to write information about.
             * @return The output stream.
             */
            friend ostream& operator<<(ostream& os, Course &course);

            /**
             * @brief Overloads the == operator to compare two courses.
             * @param main The first course to compare.
             * @param other The second course to compare.
             * @return True if the two courses have the same name and code, false otherwise.
             */
            friend bool operator == (Course &main, Course &other);

        protected:
            int size;  /**< The number of enrolled students. */
            int capacity;  /**< The current capacity of the array of enrolled students. */
            string courseName;  /**< The name of the course. */
            string code; /**< The code for the course. */
            Student* enrollStudents ; /**< The array of enrolled students. */

    };
}


#endif