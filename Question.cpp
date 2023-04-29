
/* 
 * File:   Question.cpp
 * Author: sxmue
 * 
 * Created on April 21, 2023, 1:10 AM
 */

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>

#include "Question.h"

Question::Question () { }

Question::Question (int choice) 
{
    switch (choice)
    {
        case 1:
            type = 1;
            makePromptQ ();
            break;
        case 2:
            type = 2;
            makeNumberChoiceQ ();
            break;
        case 3:
            type = 3;
            makeStringChoiceQ ();
            break;
        default:
            cout << "Not available option";
            break;
    }
}

void Question::makeNumberChoiceQ ()
{
    cout << "|--> Enter your question - with an ending tab" << endl;
    getline (cin, question, '\t');
    
    cout << "\t|--> Enter your number choices and quit with Q" << endl;

    int number_choice;
    char continue_choice;
    do
    {
        cin >> number_choice;
        num_opts.push_back (number_choice);
        
        cout << "  Continue - with C?" << endl;
        cin >> continue_choice;
        
        continue_choice = toupper (continue_choice);
        
    } while (continue_choice != 'Q');
}

void Question::makeStringChoiceQ ()
{
    cout << "|--> Enter your question - with an ending tab" << endl;
    getline (cin, question, '\t');
    
    cout << "\t|--> Enter your string choices - with ending tab - and quit with Q" << endl;

    string string_choice;
    char continue_choice;
    do
    {
        getline (cin, string_choice, '\t');
        str_opts.push_back (string_choice);
        
        cout << "  Continue - with C?" << endl;
        cin >> continue_choice;
        
        continue_choice = toupper (continue_choice);
    } while (continue_choice != 'Q');
}

void Question::makePromptQ ()
{
    cout << "|--> Enter your question - with an ending tab" << endl;
    getline (cin, question, '\t');
}

void Question::to_string ()
{
    cout << "*****";
    cout << this->question << "\n";
    
    if (type == 1)
    {
        cout << "Full Prompt Question\n";
    }
    else if (type == 2)
    {
        cout << "Multiple choice - numeric\n";
        
        for (int a = 0; a < this->num_opts.size (); a++)
            cout << "\t" <<  this->num_opts.at (a) << "\n";
    }
    else if (type == 3)
    {
        cout << "Multiple choice - written\n";
        
        for (int a = 0; a < this->str_opts.size (); a++)
            cout << "\t" << this->str_opts.at (a) << "\n";
    }
    else
    {
        cout << "here" << type << endl;
    }
}


Question::Question (const Question& orig) { }

Question::~Question() { }

