#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include "catolog.cpp"
#include "movie.h"
#include "music.h"
#include "book.h"
#include "content.h"

using namespace std;


/**
 * @brief Reads data from a file and returns it as a queue of strings.
 * @param filename The name of the file to read.
 * @param delimiter Flag indicating whether the data should be split based on delimiters.
 * @return A queue of strings containing the data read from the file.
 */
queue<string> readData(const std::string& filename, bool delimeter)
{
    ifstream file(filename);
    queue<string> data;
    if(file.is_open())
    {
        string line;
        
        while(getline(file,line))
        {
            stringstream ss(line);
            string word;
            if(delimeter)
            {
                /*I added for modified line for output.txt*/
                
                while(getline(ss,word,' '))
                {
                    data.push(word);
                }
                
            }
            else
                data.push(line);
        }
    }
    file.close();

    return data;
}


int main()
{
   queue<string> content = readData("data.txt",false);
   queue<string> commends = readData("comment.txt",true);
   while(!content.empty())
    {
        string line = content.front();
        cout<<line<<endl;
        if (line=="movie")
        {
            
            Catalog<Movie> movies;
            movies.writeOutput("Catalog Read : " + line);
            content.pop();
            while(!content.empty())
            {
                string line = content.front();
                try
                {
                    Movie *m = new Movie(line);
                    movies.push(m);
                }
                catch(Exception e)
                {
                    string line = e.getError() + "\n" + e.getLine();
                    movies.writeOutput(line);
                }
                content.pop();
            }
            movies.uniqueSize();
            while(!commends.empty())
            {
                if(commends.front()=="search")
                {
                    try{
                    commends.pop();
                    string key = commends.front();
                    commends.pop();
                    commends.pop();
                    string field = commends.front();
                    commends.pop();

                    key.erase(remove(key.begin(),key.end(),'"'),key.end());
                    field.erase(remove(field.begin(),field.end(),'"'),field.end());
                    vector<size_t> result = movies.search(key,field,true);

                    }
                    catch (Exception e)
                    {
                        string line = e.getError() + "\n" +"\""+ e.getLine() + "\"";
                        movies.writeOutput(line);
                    }
                    
                }
                else if(commends.front()=="sort")
                {
                    try
                    {
                        commends.pop();
                        string key = commends.front();
                        key.erase(remove(key.begin(),key.end(),'"'),key.end());
                        movies.sort(key);
                        commends.pop();
                    }
                    catch(Exception e)
                    {
                        commends.pop();
                        string line = e.getError() + "\n" + e.getLine();
                        movies.writeOutput(line);
                    }
                    
                }
            }
            movies.createOutput();
        }

        else if (line=="music")
        {
            //cout<<"girdi"<<endl;
            
            Catalog<Music> Musics;
            Musics.writeOutput("Catalog Read : " + line);
            content.pop();
            while(!content.empty())
            {
                string line = content.front();
                try
                {
                    Music *m = new Music(line);
                    Musics.push(m);
                }
                catch(Exception e)
                {
                    string line = e.getError() + "\n" + e.getLine();
                    Musics.writeOutput(line);
                }
                content.pop();
            }
            Musics.uniqueSize();
            while(!commends.empty())
            {
                if(commends.front()=="search")
                {
                    try{
                    commends.pop();
                    string key = commends.front();
                    commends.pop();
                    commends.pop();
                    string field = commends.front();
                    commends.pop();

                    key.erase(remove(key.begin(),key.end(),'"'),key.end());
                    field.erase(remove(field.begin(),field.end(),'"'),field.end());
                    vector<size_t> result = Musics.search(key,field,true);

                    }
                    catch (Exception e)
                    {
                        string line = e.getError() + "\n" + e.getLine();
                        Musics.writeOutput(line);
                    }
                    
                }
                else if(commends.front()=="sort")
                {
                    try
                    {
                        commends.pop();
                        string key = commends.front();
                        key.erase(remove(key.begin(),key.end(),'"'),key.end());
                        Musics.sort(key);
                        commends.pop();
                    }
                    catch(Exception e)
                    {
                        string line = e.getError() + "\n" + e.getLine();
                        Musics.writeOutput(line);
                    }
                    
                }
            }
            Musics.createOutput();
        }

         else if(line=="book")
         {
            cout<<"girdi"<<endl;
            Catalog<Book> Books;
            Books.writeOutput("Catalog Read : " + line);
            content.pop();
             while(!content.empty())
             {
                 string line = content.front();
                 try
                 {
                     Book *m = new Book(line);
                     Books.push(m);
                 }
                 catch(Exception e)
                 {
                     string line = e.getError() + "\n" + e.getLine();
                     Books.writeOutput(line);
                 }
                 content.pop();
             }
             while(!commends.empty())
             {
                 if(commends.front()=="search")
                 {
                     try{
                     commends.pop();
                     string key = commends.front();
                     commends.pop();
                     commends.pop();
                     string field = commends.front();
                     commends.pop();

                     key.erase(remove(key.begin(),key.end(),'"'),key.end());
                     field.erase(remove(field.begin(),field.end(),'"'),field.end());
                     vector<size_t> result = Books.search(key,field,true);

                     }
                     catch (Exception e)
                     {
                         string line = e.getError() + "\n" + e.getLine();
                         Books.writeOutput(line);
                     }
                    
                 }
                 else if(commends.front()=="sort")
                 {
                     try
                     {
                         commends.pop();
                         string key = commends.front();
                         key.erase(remove(key.begin(),key.end(),'"'),key.end());
                         Books.sort(key);
                         commends.pop();
                     }
                     catch(Exception e)
                     {
                         string line = e.getError() + "\n" + e.getLine();
                         Books.writeOutput(line);
                     }
                    
                 }
                 Books.createOutput();
             }
         }
        
    }
    return 0;
}