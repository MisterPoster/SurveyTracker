
/* 
 * File:   Admin.h
 * Author: sxmue
 *
 * Created on April 21, 2023, 1:09 AM
 */

#include <vector>
#include <ctime>
#include <string>
#include <iostream>

#include "Survey.h"

using namespace std;

#ifndef ADMIN_H
#define ADMIN_H

class Admin 
{
    public:
        Admin ();
        Admin (string name);
        Admin (const Admin& orig);
        virtual ~Admin ();
        void printSurvey ();
        void createEditSurvey ();
        void exportSurvey ();
    private:
        string name;
        Survey sur;
};

#endif /* ADMIN_H */

