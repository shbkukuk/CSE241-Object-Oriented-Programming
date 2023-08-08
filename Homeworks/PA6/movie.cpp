#include"movie.h"
#include <iostream>
#include<vector>
using namespace std;

Movie::Movie(string title,string director,string year,string genre, string starring) : Content(title,year)
{

    this->director = director;
    this->genre = genre;
    this->starring = starring;
}

Movie::Movie(string line)  : Content(line)
{
    vector<string> fields = splitLine(line,'"');
    if(fields.size()<5)
    {
        throw(Exception("Exception: missing field",line));
    }

    else if (fields.size()==5)
    {
        bool check;
        for(int i=0;i<5;i++)
        {
            check = isStringWhiteSpace(fields[i]);
            if(check)
            {   
                throw(Exception("Exception: missing field",line));
            }
        }
    }
    
    this->title = fields[0];
    this->director = fields[1];
    this->year = fields[2];
    this->genre = fields[3];
    this->starring = fields[4];
    
}

string Movie::getDirector()
{
    return director;
}

string Movie::getGenre()
{
    return genre;
}
 
string Movie::getStarring()
{
    return starring;
}

void Movie::setDirector(string newDirector)
{
    this->director = newDirector;
}

void Movie::setGenre(string newGenre)
{
    this->genre = newGenre;
}

void Movie::setStarring(string newStarring)
{
    this->starring = newStarring;
}

string Movie::getType()
{
    return "movie";
}

string Movie::printInfo()
{
    return  "\""+ title + "\"" + this->director + "\"" +this->year + "\""+this->genre + "\""
    +this-> starring + "\"";
}

bool Movie::operator==(const Movie &otherMovie) 
{
    
    if(this->director == otherMovie.director || this->genre==otherMovie.genre || this->starring==otherMovie.starring)
        return true;
    return false;
}
