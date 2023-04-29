
/* 
 * File:   Question.h
 * Author: sxmue
 *
 * Created on April 21, 2023, 1:10 AM
 */

#include <vector>
#include <string>

using namespace std;


#ifndef QUESTION_H
#define QUESTION_H

class Question 
{
    public:
        Question ();
        Question (int);
        Question (const Question& orig);
        virtual ~Question ();
        void makeNumberChoiceQ ();
        void makeStringChoiceQ ();
        void makePromptQ ();
        void to_string ();
    protected:
        string question;
        enum TYPE {prompt = 1, numeric_choice = 2, string_choice = 3};
        int type;
        vector <string> str_opts;
        vector <int>    num_opts;
};

#endif /* QUESTION_H */

