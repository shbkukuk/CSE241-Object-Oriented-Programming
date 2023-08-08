#pragma once
#ifndef ROOMBA_H
#define ROOMBA_H
#include<iostream>
#include"World.h"
#include"Robot.h"

using namespace std;
/**
*@brief The Roomba class is a subclass of the Robot class that represents a specific type of cleaning robot.
*The Roomba class inherits the properties and methods of the Robot class and adds its own implementation
*for the getDamage() and getType() methods.
*/
class Roomba: public Robot
{
    public:
        /*
        * @brief The default constructor for the Roomba class.
        */
        Roomba();

        /**
         * @brief The constructor for the Roomba class that initializes the object with the specified parameters.
         * 
         * @param newworld A pointer to the world object that the robot is part of.
         * @param x The x-coordinate of the robot's initial location.
         * @param y The y-coordinate of the robot's initial location.
         * @param robotname The name of the robot.
         */
        Roomba(World *newworld, int x, int y,string robotname);
        
        /**
         * @brief Calculates the damage that the robot can deal to another robot during a fight.
         * 
         * This method overrides the getDamage() method of the Robot class to always return 0, since a Roomba robot
         * does not have any fighting capabilities.
         * 
         * @return An integer representing the damage that the robot can deal.
         */
        string getType();

         /**
         * @brief Returns the type of the robot as a string.
         * 
         * This method overrides the getType() method of the Robot class to return the type of the robot as "Roomba".
         * 
         * @return A string representing the type of the robot.
         */
        int  getDamage();
    

};

#endif