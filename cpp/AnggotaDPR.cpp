#pragma once
#include <iostream>
#include <string>

using namespace std;

class AnggotaDPR
{
    private:
        string id;
        string name;
        string field;
        string party;

    
    public:
        string getId()
        {
            return this->id;
        }

    
        void setId(string id)
        {
            this->id = id;
        }

    
        string getName()
        {
            return this->name;
        }

    
        void setName(string name)
        {
            this->name = name;
        }

    
        string getField()
        {
            return this->field;
        }

    
        void setField(string field)
        {
            this->field = field;
        }

    
        string getParty()
        {
            return this->party;
        }

    
        void setParty(string party)
        {
            this->party = party;
        }

\};