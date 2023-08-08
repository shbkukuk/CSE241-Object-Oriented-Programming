#include<iostream>
#include"Optimusprime.h"
#include"Humanic.h"

using namespace std;

Optimusprime::Optimusprime() :Humanic()
{
    strenght=100;
    hitpoints=100;
}

Optimusprime::Optimusprime(World *world, int x, int y, string Humanicname): Humanic(world,x,y,Humanicname,100,100)
{
    
}

string Optimusprime::getType()
{
    return "Optimusprime";
}

int Optimusprime::getDamage()
{
    int damage;
    if (rand() % 100 + 1 <= 15)
    {
        damage = 2 * Humanic::getDamage();
    }

    damage = Humanic::getDamage();
    return damage;
}