#include "music.h"
#include<iostream>
using namespace std;


Music::Music(string title,string artist,string year,string genre) : Content(title,year)
{
    this->artist = artist;
    this->genre = genre;
}

Music::Music(string line)  : Content(line)
{
    vector<string> fields = splitLine(line,'"');
    if(fields.size()<4)
    {
        throw(Exception("Exception: missing field",line));
    }

    else if (fields.size()==4)
    {
        bool check;
        for(int i=0;i<4;i++)
        {
            check = isStringWhiteSpace(fields[i]);
            if(check)
            {   
                throw(Exception("Exception: missing field",line));
            }
        }
    }
    
    this->title = fields[0];
    this->artist= fields[1];
    this->year = fields[2];
    this->genre = fields[3];
    
}

string Music::getArtist()
{
    return artist;
}

string Music::getGenre()
{
    return genre;
}
 
void Music::setArtist(string newArtist)
{
    this->artist = newArtist;
}

void Music::setGenre(string newGenre)
{
    this->genre = newGenre;
}

string Music::getType()
{
    return "music";
}

string Music::printInfo()
{
    return  "\""+ title + "\"" + this->artist + "\"" +this->year + "\""+this->genre + "\"";
}

bool Music::operator==(const Music &otherMovie) 
{
    
    if(this->artist == otherMovie.artist || this->genre==otherMovie.genre)
        return true;
    return false;
}