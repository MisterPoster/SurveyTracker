
/* 
 * File:   User.h
 * Author: sxmue
 *
 * Created on April 28, 2023, 1:54 PM
 */

#include <string>
#include <vector>

#ifndef USER_H
#define USER_H

using namespace std;

class User 
{
    public:
        User ();
        User (string, string, string, int);
        User (const User& orig);
        void to_str ();
        virtual ~User ();
    private:
        string name;
        string email;
        string password;
        int records;
};

#endif /* USER_H */


