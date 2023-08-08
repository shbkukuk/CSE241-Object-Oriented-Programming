#include<iostream>
#include"Robot.h"
using namespace std;

int Totalrobot = 20;
Robot::Robot()
{
    world=NULL;
    x=0,y =0;
    fight=false;
    strenght=0;
    moved=false;
    hitpoints=0;

}

Robot::Robot(World *world,int x, int y,string robotname,int strenght,int hitpoints)
{
    this->world = world;
    this->x = x;
    this->y = y;
    this->strenght = strenght;
    this->hitpoints = hitpoints;
    this->RobotName = robotname;
    this->fight = false;
    this->moved = false;
    this->world->setAt(x,y,this); 
}

Robot::~Robot()
{
}
bool Robot::getFighted()
{
    return fight;
}
bool Robot::getMoved()
{
    return moved;
}
int Robot::getHealth()
{
    return strenght;
}

int Robot::getHit()
{
    return hitpoints;
}

string Robot::getName()
{
    return RobotName;
}

void Robot::setName(string name)
{
    this->RobotName = name;
}

int Robot::getX()
{
    return x;
}

int Robot::getY()
{
    return y;
}
int Robot::getDamage()
{
    int damage;
    damage = (rand() % strenght) + 1;
    return damage;
}

bool Robot::die()
{
    if (hitpoints<0)
        return true;
    return false;
}

int Robot::decHealt(int damage)
{
    return this->hitpoints-=damage;
}

void Robot::hitMessage(Robot *robot,int damage)
{
    cout<<this->getName()<<"("<<this->getHealth()<<")"<<" "<<"hits "
    <<robot->getName()<<"("<<robot->getHealth()<<")"<<" with "<<damage
    <<endl;
    cout<<"The new hitpoints of "<<robot->getName()<<" is "<<robot->decHealt(damage)
    <<endl;
}

void Robot::getFight(Robot *Survivor)
{
    while(true)//Untill Warrior or Survivor will be True, They fight 
    {
        int warriorDamage, survivorDamage;
        warriorDamage = this->getDamage();
        this->hitMessage(Survivor,warriorDamage);// Fist attack first Damage from Warriors
        if(Survivor->die()) //Check Survivor is dead, if it is true, exit the While loop
            break;
        survivorDamage = Survivor->getDamage();
        Survivor->hitMessage(this,survivorDamage);
        if(this->die()) //Check Warrior is dead, if it is true, exit the While loop
            break;
    }
}

void Robot::move()
{
    bool warrior = true;

    while (warrior)
    {
        int dir = rand() % 4;
        int target_x = x;
        int target_y = y;

        if (dir == 0 && y > 0)
            target_y--;
        else if (dir == 1 && y < WORLDSIZE - 1)
            target_y++;
        else if (dir == 2 && x > 0)
            target_x--;
        else if (dir == 3 && x < WORLDSIZE - 1)
            target_x++;

        Robot* target = world->getAt(target_x, target_y);

        if (target == nullptr)
        {
            world->setAt(target_x, target_y, world->getAt(x, y));
            world->setAt(x, y, nullptr);
            x = target_x;
            y = target_y;
        }
        else if(this==target)
        {
            warrior=false;
            break;
        }
        else
        {
            this->fight = true;
            while (this->fight)
            {
                this->getFight(target);

                if (target->die())
                {
                    cout<<target->getName()<<" is dead this war."<<endl;
                    world->grid[target_x][target_y] = this;
                    world->setAt(x, y, nullptr);
                    x = target_x;
                    y = target_y;
                    this->fight = false;
                    warrior = false;
                    Totalrobot--;
                    break;
                }

                if (this->die())
                {
                    cout<<this->getName()<<" is dead this war."<<endl;
                    world->setAt(x, y, nullptr);
                    warrior = false;
                    Totalrobot--;
                    break;
                }

                target->getFight(this);
            }
        }
    }
}


bool Robot::operator==(Robot* robot1)
{
    if((robot1->getX()==this->getX())&&(robot1->getY()==this->getY()))
        return true;
    return false;
}

