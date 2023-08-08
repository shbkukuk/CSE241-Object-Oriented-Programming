
/**
 * @file book.h
 * @brief Header file for the Book class.
 */
#ifndef BOOK_H
#define BOOK_H
#include "content.h"
#include<iostream>
using namespace std;

/**
 * @class Book
 * @brief Represents a book as a type of content.
 *
 * The Book class inherits from the Content class and adds additional
 * properties such as author and tags.
 */
class Book :  public Content
{
    private:
        string author;
        string tags;
    
    public:
        /**
         * @brief Parameterized constructor for the Book class.
         * @param title The title of the book.
         * @param author The author of the book.
         * @param year The publication year of the book.
         * @param tags The tags associated with the book.
         */
        Book(string title,string author,string year,string tags);

        /**
         * @brief Constructor for the Book class that initializes object from a string.
         * @param line A string containing book information in a specific format.
         */
        Book(string line);

        /**
         * @brief Retrieves the author of the book.
         * @return The author of the book.
         */
        string getAuthor();

        /**
         * @brief Retrieves the tags associated with the book.
         * @return The tags associated with the book.
         */
        string getTags();

        /**
         * @brief Sets the author of the book.
         * @param newAuthor The new author of the book.
         */
        void setAuthor(string newAuthor);

        /**
         * @brief Sets the tags associated with the book.
         * @param newTags The new tags associated with the book.
         */
        void setTags(string newTags);

        /**
         * @brief Retrieves the type of content (book).
         * @return The type of content (book).
         */
        string getType();

        /**
         * @brief Prints the information of the book.
         * @return A string containing the formatted information of the book.
         */
        string printInfo();

        /**
         * @brief Checks if the current book is equal to another book.
         * @param otherBook The book to compare with.
         * @return True if the books are equal, False otherwise.
         */
        bool operator==(const Book& otherMovie);



};


#endif