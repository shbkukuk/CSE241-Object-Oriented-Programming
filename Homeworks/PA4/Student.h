#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;


namespace PA4
{
    class Course;

    /**
     * @brief Represents a student in a school management system.
     */
    class Student
    {
        public:
            /**
             * @brief Constructs a default Student object with empty name and ID.
             */
            Student();

            /**
             * @brief Constructs a Student object with given name and ID.
             * @param name The name of the student.
             * @param ID The ID of the student.
             */
            Student(string name, string ID);

            /**
             * @brief Destroys the Student object and frees any dynamically allocated memory.
             */
            ~Student();

            /**
             * @brief Gets the name of the student.
             * @return The name of the student.
             */
            string getName() const;

            /**
             * @brief Gets the ID of the student.
             * @return The ID of the student.
             */
            string getID() const ;

            /**
             * @brief Gets the number of courses the student is taking.
             * @return The number of courses the student is taking.
             */
            int getSize() const;

            /**
             * @brief Gets the index of the given course in the student's list of courses.
             * @param courseC The course to find the index of.
             * @return The index of the course, or -1 if the course is not in the list.
             */
            int getIndex(Course courseC);

            /**
             * @brief Sets the name of the student.
             * @param newName The new name of the student.
             * @return The new name of the student.
             */
            string setName(string newName);

            /**
             * @brief Sets the ID of the student.
             * @param newID The new ID of the student.
             * @return The new ID of the student.
             */
            string setID(string newID);

            /**
             * @brief Adds a course to the student's list of courses.
             * @param newCourse The course to add.
             */
            void addCourse(Course newCourse);

            /**
             * @brief Deletes a course from the student's list of courses.
             * @param deleteCourse The course to delete.
             */
            void deleteCourse(Course deleteCourse);

            /**
             * @brief Gets a pointer to an array of the courses the student is taking.
             * @return A pointer to an array of the courses the student is taking.
             */
            Course* takeCourse() const;

            /**
             * @brief Increases the capacity of the student's list of courses.
             */
            void growCourse();

            /**
             * @brief Checks if two Student objects are equal by comparing their names and IDs.
             * @param main The first Student object.
             * @param other The second Student object.
             * @return true if the objects are equal, false otherwise.
             */
            friend bool operator==(Student &main ,Student& other);

            /**
             * @brief Outputs the Student object to the output stream.
             * @param os The output stream.
             * @param stu The Student object to output.
             * @return The output stream.
             */
            friend ostream& operator>>(ostream& os,Student &stu);
        protected:
            int size; /**< The number of courses the student is taking. */
            int capacity;  /**< The maximum number of courses the student can take. */
            string name;  /**< The name of the student. */
            string ID;  /**< The ID of the student. */
            Course* takenCourses; /**< The array of Course */

    };

}


#endif