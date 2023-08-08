/**
 * @file catalog.h
 * @brief Header file for the Catalog class.
 */

#ifndef CATOLOG_H
#define CATOLOG_H
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Exception;
class MissingField;
class DuplicateEntry;
class WrongCommend;

/**
 * @class Catalog
 * @brief Represents a catalog that stores and manages a collection of objects of type T.
 *
 * The Catalog class is a templated class that can store objects of any type T. It provides
 * functionality to add objects, sort them, search for objects based on specified fields,
 * and generate an output string.
 */
template <class T>
class Catalog
{
    protected:
        vector<T*> productions; //Contents
        vector<string> keys; // For sorted object
        vector<string> sortedKeys; 
        set<string> fields; // tag all contents
        queue<string> output; // Output string
    public:
        friend class Exception;
        friend class MissingField;
        friend class DuplicateEntry;
        friend class WrongCommend;

        /**
         * @brief Default constructor for the Catalog class.
         */
        Catalog();

        /**
         * @brief Constructor for the Catalog class that initializes objects from a queue of strings.
         * @param content A queue of strings containing object information in a specific format.
         */
        Catalog(queue<string> content);

        /**
         * @brief Adds an object of type T to the catalog.
         * @param type A pointer to the object to be added.
         */
        void push(T* type);

        /**
         * @brief Converts the catalog objects to a string.
         */
        void toString();
        //~Catalog();

        /**
         * @brief Sorts the catalog objects based on a specified field.
         * @param field The field used for sorting.
         */
        void sort(string field);

        /**
         * @brief Creates keys for sorting the catalog objects based on a specified field.
         * @param field The field used for creating keys.
         */
        void creatKeys(string field);

        /**
         * @brief Writes a line to the output string.
         * @param line The line to be written to the output.
         */
        void writeOutput(string line);

        /**
         * @brief Prints the number of unique objects in the catalog.
         */
        void uniqueSize();

        /**
         * @brief Searches for objects in the catalog based on a specified target and field.
         * @param target The target to search for.
         * @param field The field to search in.
         * @param main Flag indicating whether the search is for the main catalog or a subset.
         * @return A vector of size_t containing the indices of matching objects.
         */
        vector<size_t> search(string target, string field,bool main=false);

        /**
         * @brief Creates the output string by processing the stored lines.
         */
        void createOutput();

};




#endif 