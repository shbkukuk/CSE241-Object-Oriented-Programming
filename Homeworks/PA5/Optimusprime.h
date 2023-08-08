#pragma once
#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H
#include<iostream>
#include"World.h"
#include"Humanic.h"

using namespace std;

/**
*@brief The Optimusprime class is a subclass of the Humanic class that represents a specific type of humanoid robot.
*The Optimusprime class inherits the properties and methods of the Humanic class and adds its own implementation
*for the getDamage() and getType() methods.
*/

class Optimusprime: public Humanic
{
    public:

        /*
        * @brief The default constructor for the Optimusprime class.
        */
        Optimusprime();
         /**
         * @brief The constructor for the Optimusprime class that initializes the object with the specified parameters.
         * 
         * @param newworld A pointer to the world object that the robot is part of.
         * @param x The x-coordinate of the robot's initial location.
         * @param y The y-coordinate of the robot's initial location.
         * @param robotname The name of the robot.
         */
        Optimusprime(World *newworld, int x, int y,string robotname);
        
        /**
         * @brief Calculates the damage that the robot can deal to another robot during a fight.
         * 
         * This method overrides the getDamage() method of the Humanic class to calculate the damage that the Optimusprime
         * robot can deal based on its strength and the type of robot it is fighting against. The Optimusprime robot has
         * a special ability to deal additional damage to Megatron robots.
         * 
         * @return An integer representing the damage that the robot can deal.
         */
        int  getDamage() ;

        /**
         * @brief Returns the type of the robot as a string.
         * 
         * This method overrides the getType() method of the Humanic class to return the type of the robot as "Optimusprime".
         * 
         * @return A string representing the type of the robot.
         */
        string getType() ;
    

};

#endif