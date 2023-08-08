#include<iostream>
#include"Roomba.h"
#include"Robot.h"

using namespace std;

Roomba::Roomba() :Robot()
{
    strenght=3;
    hitpoints=10;
}

Roomba::Roomba(World *world, int x, int y, string robotname): Robot(world,x,y,robotname,3,10)
{
    
}

string Roomba::getType()
{
    return "Roomba";
}

int Roomba::getDamage()
{
    int damage;
    for(int i=0;i<2;i++) // Roomba robot is fast,so they can attack two times. I calculate in for loop. 
    //I called two times getDamage function. The function create two times randomly damage.
    //And addition both generate damage and return.
    {
        damage += Robot::getDamage();
    }
    return damage;
}
