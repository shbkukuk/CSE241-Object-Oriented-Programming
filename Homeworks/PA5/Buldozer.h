#pragma once
#ifndef BULDOZER_H
#define BULDOZER_H
#include<iostream>
#include"World.h"
#include"Robot.h"

using namespace std;

/**
* @brief The Buldozer class is a subclass of the Robot class that represents a bulldozer robot in the world.
* The Buldozer class inherits the properties and methods of the Robot class and adds its own implementation
* for the getType() method to return the string "Buldozer".
*/
class Buldozer: public Robot
{
    public:
        /*
        * @brief The default constructor for the Buldozer class.
        */
        Buldozer();
         /**
         * @brief The constructor for the Buldozer class that initializes the object with the specified parameters.
         * 
         * @param newworld A pointer to the world object that the robot is part of.
         * @param x The x-coordinate of the robot's initial location.
         * @param y The y-coordinate of the robot's initial location.
         * @param robotname The name of the robot.
         */
        Buldozer(World *newworld, int x, int y,string robotname);
        
        /**
         * @brief Returns the type of the robot as a string.
         * 
         * This method overrides the getType() method of the Robot class to return the string "Buldozer".
         * 
         * @return A string representing the type of the robot.
         */
        string getType() ;

};

#endif