
/**
 * @file content.h
 * @brief Header file for the Content class and related exception classes.
 */
#ifndef CONTENT_H
#define CONTENT_H
#include <iostream>
#include<vector>
using namespace std;


/**
 * @class Exception
 * @brief Represents an exception that occurred during content processing.
 *
 * The Exception class provides a generic base class for content-related exceptions.
 * It stores the error message and the line where the error occurred.
 */
class Exception{
    public:
         /**
         * @brief Constructor for the Exception class.
         * @param error The error message describing the exception.
         * @param line The line where the exception occurred.
         */
        Exception(string error,string line);

        /**
         * @brief Retrieves the error message.
         * @return The error message.
         */
        string getError();

        /**
         * @brief Retrieves the line where the exception occurred.
         * @return The line where the exception occurred.
         */
        string getLine();
    protected:
        string error;
        string line;
    
        
};

/**
 * @class MissingField
 * @brief Represents an exception for a missing field in content processing.
 *
 * The MissingField class is derived from the Exception class and represents an exception
 * that occurs when a required field is missing in the content.
 */
class MissingField:public Exception
{
    /**
     * @brief Constructor for the MissingField class.
     * @param error The error message describing the missing field.
     * @param line The line where the missing field occurred.
     */
     MissingField(string error,string line):Exception(error,line){};
        
};

/**
 * @class DuplicateEntry
 * @brief Represents an exception for a duplicate entry in content processing.
 *
 * The DuplicateEntry class is derived from the Exception class and represents an exception
 * that occurs when a duplicate entry is encountered in the content.
 */
class DuplicateEntry:public Exception
{
    public:
        /**
         * @brief Constructor for the DuplicateEntry class.
         * @param error The error message describing the duplicate entry.
         * @param line The line where the duplicate entry occurred.
         */
        DuplicateEntry(string error,string line):Exception(error,line){};
};

/**
 * @class WrongCommend
 * @brief Represents an exception for an invalid command in content processing.
 *
 * The WrongCommend class is derived from the Exception class and represents an exception
 * that occurs when an invalid command is encountered in the content.
 */
class WrongCommend:public Exception
{

    /**
     * @brief Constructor for the WrongCommend class.
     * @param error The error message describing the invalid command.
     * @param line The line where the invalid command occurred.
     */
    WrongCommend(string error, string line):Exception(error,line){};
    
};   

/**
 * @class Content
 * @brief Represents a generic content.
 *
 * The Content class is an abstract base class for representing different types of content.
 * It provides common properties and functions that can be inherited by specific content types.
 */
class Content
{
    protected:

        string title;
        string year;
    public:
        /**
         * @brief Parameterized constructor for the Content class.
         * @param title The title of the content.
         * @param year The year of the content.
         */
        Content(string title,string year);

        /**
         * @brief Constructor for the Content class that initializes object from a string.
         * @param line A string containing content information in a specific format.
         */
        Content(string line);

        /**
         * @brief Retrieves the title of the content.
         * @return The title of the content.
         */
        string getTitle();

        /**
         * @brief Retrieves the year of the content.
         * @return The year of the content.
         */
        string getYear();

        /**
         * @brief Sets the title of the content.
         * @param newTitle The new title of the content.
         */
        void setTitle(string newTitle);

        /**
         * @brief Sets the year of the content.
         * @param newYear The new year of the content.
         */
        void setYear(string newYear);

        /**
         * @brief Splits a line into a vector of strings based on a delimiter.
         * @param line The line to be split.
         * @param delimiter The delimiter used for splitting.
         * @return A vector of strings containing the split parts of the line.
         */
        vector<string> splitLine(string line,char delimeter);

         /**
         * @brief Checks if a string contains only whitespace characters.
         * @param str The string to be checked.
         * @return True if the string contains only whitespace, False otherwise.
         */
        bool isStringWhiteSpace(const std::string& str);

        /**
         * @brief Retrieves the type of content (abstract).
         * @return The type of content.
         */
        virtual string getType() = 0;
        /**
         * @brief Retrieves the author of the content (only applicable to specific content types).
         * @return The author of the content.
         */
        string getAuthor() {return "";};
         /**
         * @brief Retrieves the tags associated with the content (only applicable to specific content types).
         * @return The tags associated with the content.
         */
        string getTags() {return "";};

        /**
         * @brief Retrieves the artist of the content (only applicable to specific content types).
         * @return The artist of the content.
         */
        string getArtist() {return"";};

        /**
         * @brief Retrieves the director of the content (only applicable to specific content types).
         * @return The director of the content.
         */
        string getDirector() {return "";};

        /**
         * @brief Retrieves the starring cast of the content (only applicable to specific content types).
         * @return The starring cast of the content.
         */
        string getStarring() {return "";};

        /**
         * @brief Retrieves the genre of the content (only applicable to specific content types).
         * @return The genre of the content.
         */
        string getGenre() {return "";};
        

};


#endif 