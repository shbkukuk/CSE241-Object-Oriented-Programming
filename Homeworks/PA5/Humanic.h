#pragma once
#ifndef HUMANIC_H
#define HUMANIC_H
#include<iostream>
#include"World.h"
#include"Robot.h"

using namespace std;


/**
* @brief The Humanic class is a subclass of the Robot class that represents a humanoid robot in the world.
* The Humanic class inherits the properties and methods of the Robot class and adds its own implementation
* for the getDamage() and getType() methods.
*/
class Humanic: public Robot
{
    public:

        /*
        * @brief The default constructor for the Humanic class.
        */
        Humanic();

         /**
         * @brief The constructor for the Humanic class that initializes the object with the specified parameters.
         * 
         * @param newworld A pointer to the world object that the robot is part of.
         * @param x The x-coordinate of the robot's initial location.
         * @param y The y-coordinate of the robot's initial location.
         * @param robotname The name of the robot.
         * @param strength The strength of the robot, which determines the damage it can deal.
         * @param hitpoints The hit points of the robot, which represent the amount of damage it can take.
         */
        Humanic(World *newworld, int x, int y,string robotname,int strenght, int hitpoints);
        
        /**
         * @brief Calculates the damage that the robot can deal to another robot during a fight.
         * 
         * This method overrides the getDamage() method of the Robot class to calculate the damage that the humanoid
         * robot can deal based on its strength and the type of robot it is fighting against.
         * 
         * @return An integer representing the damage that the robot can deal.
         */
        int  getDamage();

        /**
         * @brief Returns the type of the robot as a string.
         * 
         * This method overrides the getType() method of the Robot class to be a pure virtual function, which means
         * that it has to be implemented by any class that inherits from the Humanic class. This is because the 
         * type of the humanoid robot is not known, as there are different types of humanoid robots with different
         * characteristics and behaviors.
         * 
         * @return A string representing the type of the robot.
         */
        virtual string getType() = 0;
    

};

#endif