#include "book.h"
#include<iostream>
using namespace std;


Book::Book(string title,string author,string year,string tags) : Content(title,year)
{
    this->author = author;
    this->tags = tags;
}


Book::Book(string line)  : Content(line)
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
    this->author = fields[1];
    this->year = fields[2];
    this->tags = fields[3];

    
}
string Book::getAuthor()
{
    return author;
}

string Book::getTags()
{
    return tags;
}
 
void Book::setAuthor(string newAuthor)
{
    this->author = newAuthor;
}

void Book::setTags(string newTags)
{
    this->tags = newTags;
}

string Book::getType()
{
    return "Book";
}

string Book::printInfo()
{
    return  "\""+ title + "\"" + this->author + "\"" +this->year + "\""+this->tags + "\"";
}

bool Book::operator==(const Book &otherBook) 
{
    
    if(this->author == otherBook.author || this->tags==otherBook.tags)
        return true;
    return false;
}
