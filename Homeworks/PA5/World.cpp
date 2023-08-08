#include<iostream>
#include"World.h"
#include"Robot.h"

using namespace std;

World::World()
{
    int i,j;
    for(i=0;i<WORLDSIZE;i++)
    {
        for(j=0;j<WORLDSIZE;j++)
        {
            grid[i][j] = NULL;
        }
    }
}

World::~World()
{
    int i,j;
    for(i=0; i<WORLDSIZE; i++)
    {
        for(j=0; j<WORLDSIZE; j++)
        {
            if(grid[i][j]!=NULL)
            {
                delete grid[i][j];
            }
        }
    }
}

Robot * World::getAt(int x, int y)
{
    if((x>=0)&&(x<WORLDSIZE)&&(y>=0)&&(y<WORLDSIZE))
    {
    
        return grid[x][y];
    }
    return NULL;
}

void World::setAt(int x, int y, Robot *robot)
{
    if((x>=0)&&(x<WORLDSIZE)&&(y>=0)&&(y<WORLDSIZE)){
        grid[x][y]=robot;
    }
}

void World::display(){
    int i,j;
    cout<<endl<<endl;
    for(j=0;j<WORLDSIZE;j++){

        for(i=0;i<WORLDSIZE;i++)
        {
            if(grid[i][j]==NULL)
                cout<<".";
            else if(grid[i][j]->getType()=="buldozer")
                cout<<"o";
       
        }
        cout<<endl;
    }
}


void World::SimulateOneStep()
{
    int i,j;


    for(i=0;i<WORLDSIZE;i++)
        for(j=0;j<WORLDSIZE;j++){
            if(grid[i][j]!=NULL) grid[i][j]->moved=false;
        }

    for(i=0;i<WORLDSIZE;i++)
        for(j=0;j<WORLDSIZE;j++){
            if(grid[i][j]!=NULL && grid[i][j]->moved==false){
                grid[i][j]->moved=true;
                grid[i][j]->move();
                //cout<<grid[i][j]->getMoved()<<endl;
                //cout<<grid[i][j]->getFighted()<<endl;

            }
        }   
}