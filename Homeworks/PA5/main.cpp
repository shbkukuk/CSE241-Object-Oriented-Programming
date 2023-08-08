#include<iostream>
#include"Robot.h"
#include"Buldozer.h"
#include "Humanic.h"
#include "Optimusprime.h"
#include"Roomba.h"
#include"Robocop.h"
#include "World.h"

using namespace std;

const int prime = 5;
const int buldozer = 5;
const int robocop = 5;
const int roomba = 5;

int main()
{
    World w;
    int newprime = 0;
    while(newprime<prime) // Create Prime
    {
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;

        if (w.getAt(x,y)==NULL)
        {
            
            string name ="optimusprime_"+to_string(newprime);
            Optimusprime *d1 = new Optimusprime(&w,x,y,name);
            newprime++;
        }
    }

    int newbuldozer = 0;
    while(newbuldozer<buldozer) // Create Buldozer 
    {
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;

        if (w.getAt(x,y)==NULL)
        {
            
            string name ="buldozer_"+to_string(newbuldozer);
            Buldozer *d2 = new Buldozer(&w,x,y,name);
            newbuldozer++;
        }
    }

    int newrobocop = 0;
    while(newrobocop<robocop) // Create Robocop
    {
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;

        if (w.getAt(x,y)==NULL)
        {
            
            string name ="robocop_"+to_string(newrobocop);
            Robocop *d3 = new Robocop(&w,x,y,name);
            newrobocop++;
        }
    }

    int newroomba = 0;
    while(newroomba<roomba) // Create Roomba
    {
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;

        if (w.getAt(x,y)==NULL)
        {
            
            string name ="roomba_"+to_string(newbuldozer);
            Roomba *d4 = new Roomba(&w,x,y,name);
            newroomba++;
        }
    }


    while(Totalrobot>1) // Until run at least one left robot.
    {
        w.SimulateOneStep();
    }

    return 0;
}