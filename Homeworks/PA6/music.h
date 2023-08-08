
/**
 * @file music.h
 * @brief Header file for the Music class.
 */
#ifndef MUSIC_H
#define MUSIC_H
#include "content.h"
#include<iostream>
using namespace std;

/**
 * @class Music
 * @brief Represents a music as a type of content.
 *
 * The Music class inherits from the Content class and adds additional
 * properties such as artist and genre.
 */
class Music :  public Content
{
    private:
        string artist;
        string genre;
    
    public:
    /**
         * @brief Parameterized constructor for the Music class.
         * @param title The title of the music.
         * @param artist The artist of the music.
         * @param year The release year of the music.
         * @param genre The genre of the music.
         */
        Music(string title,string artist,string year,string genre);

        /**
         * @brief Constructor for the Music class that initializes object from a string.
         * @param line A string containing music information in a specific format.
         */
        Music(string line);

        /**
         * @brief Retrieves the artist of the music.
         * @return The artist of the music.
         */
        string getArtist();

        /**
         * @brief Retrieves the genre of the music.
         * @return The genre of the music.
         */
        string getGenre();

        /**
         * @brief Sets the artist of the music.
         * @param newArtist The new artist of the music.
         */
        void setArtist(string newArtist);

        /**
         * @brief Sets the genre of the music.
         * @param newGenre The new genre of the music.
         */
        void setGenre(string newGenre);

         /**
         * @brief Retrieves the type of content (music).
         * @return The type of content (music).
         */
        string getType();

        /**
         * @brief Prints the information of the music.
         * @return A string containing the formatted information of the music.
         */
        string printInfo();

        /**
         * @brief Checks if the current music is equal to another music.
         * @param otherMusic The music to compare with.
         * @return True if the music are equal, False otherwise.
         */
        bool operator==(const Music& otherMusic);


};


#endif