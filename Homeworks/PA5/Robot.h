#pragma once
#ifndef ROBOT_H
#define ROBOT_H
#include<iostream>
#include"World.h"

extern int Totalrobot;
using namespace std;

/**
 * The Robot class represents a robot in a virtual world. Each robot has a name, position, strength, and hit points.
 * Robots can move around the world, fight other robots, and take damage. The Robot class is an abstract class,
 * so you cannot create instances of it directly. Instead, you must create subclasses that implement the getType method.
 */
class Robot
{
    friend class World;
    public:

        /**
         * Creates a new Robot instance with default values.
         */
        Robot();

        /**
         * Creates a new Robot instance with the given name, position, strength, and hit points.
         *
         * @param world A pointer to the world the robot is in.
         * @param x The x-coordinate of the robot's starting position.
         * @param y The y-coordinate of the robot's starting position.
         * @param robotname The name of the robot.
         * @param strenght The strength of the robot.
         * @param hitpoints The hit points of the robot.
         */
        Robot(World *world, int x, int y,string robotname,int strenght,int hitpoints);

        /**
         * Destroys the Robot instance.
         */
        ~Robot();

        /**
         * Moves the robot in a random direction.
         */
        void move();

        /**
         * Gets the name of the robot.
         *
         * @return The name of the robot.
         */
        string getName();

        /**
         * Sets the name of the robot.
         *
         * @param name The new name of the robot.
         */
        void setName(string name);

        /**
         * Gets the x-coordinate of the robot's current position.
         *
         * @return The x-coordinate of the robot's current position.
         */
        int getX();

        /**
         * Gets the y-coordinate of the robot's current position.
         *
         * @return The y-coordinate of the robot's current position.
         */
        int getY();

        /**
         * Gets the current health of the robot.
         *
         * @return The current health of the robot.
         */
        int getHealth();

         /**
         * Gets the hit points of the robot.
         *
         * @return The hit points of the robot.
         */
        int getHit();

        /**
         * Initiates a fight between this robot and another robot.
         *
         * @param survivor The other robot to fight.
         */ 
        void getFight(Robot *Survivor);

        /**
         * Decreases the health of the robot by the given amount.
         *
         * @param damage The amount of damage to take.
         * @return The new health of the robot.
         */
        int decHealt(int damage);

        /**
         * Prints a message indicating that the robot hit the other robot and how much damage was dealt.
         *
         * @param survivor The other robot that was hit.
         * @param damage The amount of damage that was dealt.
         */
        void hitMessage(Robot *Survivor , int damage);

        /**
         * Checks if the robot is dead.
         *
         * @return True if the robot is dead, false otherwise.
         */
        bool die();

         /**
         * Gets whether the robot has moved during the current turn.
         *
         * @return True if the robot has moved, false otherwise.
         */
        bool getMoved();

        /**
         * Gets whether the robot has fought during the current turn.
         *
         * @return True if the robot has fought, false otherwise.
         */
        bool getFighted();

        /**
        * @brief Calculates the damage that the robot can deal to another robot.
        * This method calculates the damage that the robot can deal to another robot based on its
        * strength value.
        * @return The amount of damage that the robot can deal.
        */
        int  getDamage();

        /**
        * @brief Returns the type of the robot.
        * This is a pure virtual method that returns a string representing the type of the robot.
        * Every subclass of Robot must implement this method.
        * @return A string representing the type of the robot.
        */
        virtual string getType() = 0;

        /**

        * @brief Compares whether two robot objects are equal.
        * This method compares whether two robot objects are equal based on their memory location.
        * @param robot1 A pointer to the robot object to compare.
        * @return True if the memory location of the two robot objects is the same, false otherwise.
        */
        bool operator ==(Robot* robot1);

    protected:
        int x,y; // The x and y-coordinate of the robot's current location.
        int strenght; // The strength of the robot, which determines the damage it can deal.
        int hitpoints; // The hit points of the robot, which represent the amount of damage it can take.
        bool fight; // A boolean flag that indicates whether the robot has engaged in a fight during the current turn.
        bool moved; // A boolean flag that indicates whether the robot has already moved during the current turn.
        string RobotName; // The name of the robot.
        World *world; // A pointer to the world object that the robot is part of.

};

#endif 