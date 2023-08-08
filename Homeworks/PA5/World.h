#pragma once
#ifndef WORLD_H
#define WORLD_h
#include<iostream>

using namespace std;


const int WORLDSIZE=10;

//Forward Declration
class Buldozer;
class Humanic;
class Optimusprime;
class Roamba;
class Robocop;
class Robot;

/**
*The World class represents the virtual world where the robots live in.
*The class allows you to place and get a robot from a specified position in the world, simulate one step of the world, and display the world.
*/
class World
{
    
    friend class Buldozer;
    friend class Humanic;
    friend class Optimusprime;
    friend class Roamba;
    friend class Robocop;
    friend class Robot;
    public: 
        /**
        * Get a pointer to the robot at the specified position.
        * @param x The x-coordinate of the position.
        * @param y The y-coordinate of the position.
        * @return A pointer to the robot at the specified position.
        */
        Robot* getAt(int x, int y);

        /**
         * Set the robot at the specified position in the world.
         * @param x The x-coordinate of the position.
         * @param y The y-coordinate of the position.
         * @param robot A pointer to the robot to be set in the world.
         */
        void setAt(int x, int y, Robot *robot);

        /**
        *The 2D array of Robot pointers representing the grid of the world.
        *The first dimension represents the x-coordinate and the second dimension
        *represents the y-coordinate of each element in the grid.
        */

        Robot* grid[WORLDSIZE][WORLDSIZE];

        /**
         * Display the world in the console.
         */
        void SimulateOneStep();

        /**
         * Display the world in the console.
         */
        void display();

        /**
         * Default constructor for the World class.
         */
        World();

        /**
         * Destructor for the World class.
         */
        ~World();

};



#endif