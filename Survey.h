
/* 
 * File:   Survey.h
 * Author: sxmue
 *
 * Created on April 1, 2023, 1:09 AM
 */

#include <ctime>
#include <string>

#include "Question.h"

using namespace std; 

#ifndef SURVEY_H
#define SURVEY_H

class Survey 
{
    public:
        Survey ();
        Survey (string);
        Survey (const Survey& orig);
        virtual ~Survey ();
        bool is_empty ();
        vector <Question> being_asked;
        string label;
};

#endif /* TIMERECORD_H */

