/**
 * @file movie.h
 * @brief Header file for the Movie class.
 */


#ifndef MOVIE_H
#define MOVIE_H
#include<iostream>
#include"content.h"
using namespace std;

/**
 * @class Movie
 * @brief Represents a movie as a type of content.
 *
 * The Movie class inherits from the Content class and adds additional
 * properties such as director, genre, and starring actors.
 */
class Movie : public Content
{
    private:
        string director;
        string genre;
        string starring;
       
    
    public:
        /**
         * @brief Parameterized constructor for the Movie class.
         * @param title The title of the movie.
         * @param director The director of the movie.
         * @param year The release year of the movie.
         * @param genre The genre of the movie.
         * @param starring The starring actors in the movie.
         */
        Movie(string title,string director,string year,string genre, string starring);
        
        /**
         * @brief Constructor for the Movie class that initializes object from a string.
         * @param line A string containing movie information in a specific format.
         */
        Movie(string line);

        /**
         * Deconstructor
        */
        ~Movie() {};
        /**
         * @brief Retrieves the director of the movie.
         * @return The director of the movie.
         */
        string getDirector();

        /**
         * @brief Retrieves the genre of the movie.
         * @return The genre of the movie.
         */
        string getGenre();
        
        /**
         * @brief Retrieves the starring actors in the movie.
         * @return The starring actors in the movie.
         */
        string getStarring();

        /**
         * @brief Sets the director of the movie.
         * @param newDirector The new director of the movie.
         */
        void setDirector(string newDirector);

        /**
         * @brief Sets the genre of the movie.
         * @param newGenre The new genre of the movie.
         */
        void setGenre(string newGenre);

        /**
         * @brief Sets the starring actors in the movie.
         * @param newStarring The new starring actors in the movie.
         */
        void setStarring(string newStarring);

        /**
         * @brief Retrieves the type of content (movie).
         * @return The type of content (movie).
         */
        string getType();

        /**
         * @brief Prints the information of the movie.
         * @return A string containing the formatted information of the movie.
         */
        string printInfo();

         /**
         * @brief Checks if the current movie is equal to another movie.
         * @param otherMovie The movie to compare with.
         * @return True if the movies are equal, False otherwise.
         */
        bool operator==(const Movie& otherMovie);


};



#endif 