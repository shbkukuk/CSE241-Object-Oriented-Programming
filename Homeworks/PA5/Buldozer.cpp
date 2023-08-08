#include<iostream>
#include"Buldozer.h"
#include"Robot.h"

using namespace std;

Buldozer::Buldozer() :Robot()
{
    strenght=50;
    hitpoints=200;
}

Buldozer::Buldozer(World *world, int x, int y, string robotname): Robot(world,x,y,robotname,50,200)
{
    
}

string Buldozer::getType()
{
    return "buldozer";
}







