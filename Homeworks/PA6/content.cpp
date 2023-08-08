#include"content.h"
#include <iostream>
#include <sstream>
#include<vector>
using namespace std;

Exception::Exception(string error,string line)
{
    this->line = line;
    this->error = error;
}
string Exception::getError(){
    return error;
}

string Exception::getLine()
{
    return line;
}
// MissingField::MissingField(string error,string line) : Exception(error,line)
// {
    
// }

// DuplicateEntry::DuplicateEntry(string error,string line): Exception(error,line)
// {
    
// }

// WrongCommend::WrongCommend(string error,string line): Exception(error,line)
// {
    
// }

Content::Content(string title,string year) : title(title), year(year)
{
    //blank
}

Content::Content(string line)
{
    // vector<string> fields = splitLine(line,'"');
    // this->title = fields[0];
    // this->title = fields[2];
}


string Content::getTitle()
{
    return this->title;
}

string Content::getYear()
{
    return this->year;
}

void Content::setTitle(string newTitle)
{
    this->title = newTitle;
}

void Content::setYear(string newYear)
{
    this->title = newYear;
}

vector<string> Content::splitLine(string line,char delimeter)
{
    vector<string> fields;
    string token;
    stringstream ss(line);

    while(getline(ss,token,delimeter))
    {
        if(!isStringWhiteSpace(token))
        {
            fields.push_back(token);
        }
        
    }

    return fields;
}


bool Content::isStringWhiteSpace(const std::string& str) {
    for (char c : str) {
        if (!std::isspace(c)) {
            return false;  // Found a non-whitespace character
        }
    }
    return true;  // All characters are whitespace
}


