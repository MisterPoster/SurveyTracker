
/* 
 * File:   Survey.cpp
 * Author: sxmue
 * 
 * Created on April 21, 2023, 1:08 AM
 */

#include <ctime>
#include <utility>

#include "Survey.h"
#include "Admin.h"
#include "Question.h"

using namespace std;

Survey::Survey () {}

Survey::Survey (string label)
{
    this->label = label;
    
    char question_choice;
   
    do
    {
        cout << "\tPlease add as much questions as you need!" << endl;
        cout << "\tNew Question - N" << endl;
        cout << "\tQuit - Q" << endl;
        
        cin >> question_choice;
        question_choice = toupper (question_choice);
        
        int question_type;
        Question* nq;
        if (question_choice == 'N')
        {
            cout << "\t|--> 1. Prompt-Type Question" << endl;
            cout << "\t|--> 2. Number-Choice Question" << endl;
            cout << "\t|--> 3. Prompt-Choice Question" << endl;
            cout << "\tChoose your question to add." << endl;
            
            cin >> question_type;
            
            nq = new Question (question_type);
            
            being_asked.push_back (*nq);
           
            cout << "Add more survey questions (1-3) or 0 to quit?" << endl;
            cin >> question_choice;
            question_choice = toupper (question_choice);
            
//            delete [] nq;
        }
    } while (question_choice != 'Q');
}

bool Survey::is_empty ()
{
    return being_asked.empty ();
}


Survey::Survey (const Survey& orig) { }

Survey::~Survey () { }

