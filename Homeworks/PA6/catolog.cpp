#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
#include "catolog.h"
using namespace std;



template<class T>
Catalog<T>::Catalog()
{
    //this->productions = new vector<T>;
}


template<class T>
Catalog<T>::Catalog(queue<string> content)
{
    
}


template<class T>
void Catalog<T>::push(T* type)
{
    if(!productions.empty())
    {
        for(int i=0; i<productions.size();i++)
        {

            if((productions[i]->getTitle()==type->getTitle()))
            {
                throw(Exception("Exception: duplicate entry",type->printInfo()));
            }
                
        }
    }
    productions.push_back(type);
}

template<class T>
void Catalog<T>::toString()
{
    
    for(int i=0;i<keys.size();i++)
    {
        cout<<keys[i]<<endl;
    }
}

template<class T>
void Catalog<T>::writeOutput(string line)
{
    //cout<<line<<endl;
    this->output.push(line);
}

template<class T>
void Catalog<T>::creatKeys(string field)
{   
    
    for(int i=0;i<productions.size();i++)
    {
        T* it = productions[i];
        string type = it->getType();
        if(field=="title")
        {
            string key = it->getTitle();
            keys.push_back(key);
        }

        else if(field=="authors" && type=="book")
        {
            string key = it->getAuthor();
            keys.push_back(key);
        }

        else if(field=="year")
        {
            string key = it->getYear();
            keys.push_back(key);
        }

        else if(field=="tags" &&type=="book")
        {
            string key = it->getTags();
            keys.push_back(key);
        }

        else if(field=="artists" && type=="music")
        {
            string key = it->getArtist();
            keys.push_back(key);
        }
        else if(field=="genre"&& type=="book")
        {
            string key = it->getGenre();
            keys.push_back(key);
        }
        else if(field=="director" && type=="movie")
        {
            string key = it->getDirector();
            keys.push_back(key);
        }
        else if(field=="starring"&& type=="movie")
        {
            string key = it->getStarring();
            keys.push_back(key);
        }
    }
    
}

template<class T>
vector<size_t> Catalog<T>::search(string target,string field,bool main)
{
    //set<string> fields = {"title","starring","director","genre","artists" ,"tags", "year","authors"};
    fields = {"title","starring","director","genre","artists" ,"tags", "year","authors"};
    auto it = fields.find(field);
    string command = "search "+target+" in "+field;
    if(it==fields.end())
    {
        
        throw(Exception("Exception: Command is Wrong ",command));
    }
    if(!keys.empty())
    {   for (int i = 0; i < keys.size(); ++i) {
        //cout<<keys[i]<<endl;
        }
         keys.clear();
    }
    this->creatKeys(field);
    vector<size_t> findPositions ;// In the books,movies or music it can be consits more than one so this is
                                // i added in vector
    
    //cout<<keys.size()<<endl;
    for (size_t i = 0; i < keys.size(); ++i) {

        if (keys[i].find(target) != string::npos) {

            findPositions.push_back(i);  // Store the position (index )
        }
    }

    if(main)
    {
        this->writeOutput(command);
        for(size_t i =0;i<findPositions.size();i++)
        {
            int ind = findPositions[i];
            T* temp = productions[ind];
            string line = temp->printInfo();
            this->writeOutput(line);
        }
    }
    return findPositions;
                    
}

template<class T>
void Catalog<T>::sort(string field)
{
    fields = {"title","starring","director","genre","artists" ,"tags", "year","authors"};
    auto it = fields.find(field);
    string command = "sort in "+field;
    if(it==fields.end())
    {
        
        throw(Exception("Exception: Command is Wrong ",command));
    }
    if(keys.empty())
    {
        this->creatKeys(field);
    }
    
    std::sort(keys.begin(),keys.end()); 

    for(int i=0;i<keys.size();i++)
    {
        string tmp = keys[i];
        sortedKeys.push_back(tmp);
    }
    
    this->writeOutput(command);
    //cout<<sortedKeys.size()<<endl;
    for(string sortedkey:sortedKeys)
    {
        vector<size_t> findedPositions = search(sortedkey,field);
        for(size_t i =0;i<findedPositions.size();i++)
        {
            int ind = findedPositions[i];
            T* temp = productions[ind];
            string line = temp->printInfo();
            this->writeOutput(line);
        }
        
    }
}


template<class T>
void Catalog<T>::createOutput()
{
    ofstream outputFile("output.txt");

    if(outputFile.is_open())
    {   
        while(!output.empty())
        {
            string line = output.front();
            outputFile<<line<<endl;
            output.pop();
        }
        outputFile.close();
    }

}

template<class T>
void Catalog<T>::uniqueSize()
{
    int size = productions.size();
    string line = "unique size : " +to_string(size); 
    this->writeOutput(line);
}
