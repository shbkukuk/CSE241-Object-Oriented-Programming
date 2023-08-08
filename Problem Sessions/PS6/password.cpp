#include <iostream>
#include <string>
using namespace std;
namespace
{   
    string password;
    bool isValid()
    {
        if(password.length()>=8)
        {
            for(int i=0;i<password.length();i++)
            {
                if(!isalpha(password[i]))
                    return true;
            }
        }
        return false;
    }
}
namespace Authenticate 
{
    void inputPassword()
    {
        do
        {
            cout << "Enter your password (8 letters only)" << endl;
            cin >> password;
        }while(!isValid());
    }
    string getPassword()
    {
        return password;
    }
}