#include<iostream>
#include"Robocop.h"
#include"Humanic.h"

using namespace std;

Robocop::Robocop() :Humanic()
{
    strenght=30;
    hitpoints=40;
}

Robocop::Robocop(World *world, int x, int y, string Humanicname): Humanic(world,x,y,Humanicname,30,40)
{
    
}

string Robocop::getType()
{
    return "Robocop";
}
