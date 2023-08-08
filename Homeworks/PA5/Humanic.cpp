#include<iostream>
#include"Humanic.h"
#include"Robot.h"

using namespace std;

Humanic::Humanic() :Robot()
{

}

Humanic::Humanic(World *world, int x, int y, string robotname,int strenght, int hitpoints): Robot(world,x,y,robotname,strenght,hitpoints)
{
    
}

int Humanic::getDamage()
{
    int damage = 0;
    const int change = 10;
    int probility = rand() % change; // I calculated change of %10 possibility, 
    if(probility==1)
        damage += 50;
    damage += (rand() % strenght) + 1;
    return damage;
}
