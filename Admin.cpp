
/* 
 * File:   Admin.cpp
 * Author: sxmue
 * 
 * Created on April 21, 2023, 1:08 AM
 */

#include <cctype>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>

#include "Admin.h"
#include "Survey.h"
#include "Question.h"

Admin::Admin () {}

Admin::Admin (string name) 
{
    this->name = name;
    char choice;
    
    if  (name == "Stan")
        cout << "Logging as marsh@gmail.com" << endl;
    else if  (name == "Kyle")
        cout << "Logging as broflovski@gmail.com" << endl;
    else if  (name == "Eric")
        cout << "Logging as cartman@gmail.com" << endl;
    else if  (name == "Kenny")
        cout << "Logging as mccormick@gmail.com" << endl;
    else if  (name == "Butters")
        cout << "Logging as scotch@gmail.com" << endl;
    
    cout << "Hello, " << name << endl;
    
    do
    {
        cout << "__________________________________"   << endl;
        cout << "|   What would you like to do?   |"   << endl;
        cout << "|     Create New Survey - C      |"   << endl;
        cout << "|    Export Survey & Quit - E    |"   << endl;
        cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"    << endl;
        
        cin >> choice;
        choice = toupper (choice);
        
        switch (choice)
        {
            case 'C':
                createEditSurvey ();
                break;
        }
    } while (choice != 'E');
    
    exportSurvey ();
}

void Admin::printSurvey ()
{
    if (sur.is_empty ())
    {
        cout << "Nothing in survey!" << endl;
    }
    else
    {
        int i = 1;
        for (auto var : sur.being_asked)
        {
            
            cout << "Question " << (i) << ":" << endl;
            (var).to_string ();
            i++;
        }
    }
}

void Admin::createEditSurvey ()
{
    string title;
    
    cout << "| Enter in some title for this survey - end with tab then enter |" << endl;
    getline (cin, title, '\t');
    
    sur = Survey (title);
}

void Admin::exportSurvey ()
{
    fstream admin_file;
    Question sendq;
    
    admin_file.open ("SurveyRecords.dat", ios::out | ios::binary);
    
    for (int i = 0; i < sur.being_asked.size (); i++)
    {
        sendq = sur.being_asked.at (i);
        cout << "ADDING: Question " << (i + 1) << " TO FILE" << endl;
        
        admin_file.write (reinterpret_cast<char *> (&sendq), sizeof (sendq));
    }
    
    cout << "Survey records have been exported to SurveyRecords.dat" << endl;
}

Admin::Admin (const Admin& orig) { }

Admin::~Admin () { }

