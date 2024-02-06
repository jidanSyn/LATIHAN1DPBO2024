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
        string electoral_district; // dapil
        string position; // jabatan
        string party;

    
    public:

        // 'empty/default' constructor
        AnggotaDPR()
        {
            this->id = "";
            this->name = "";
            this->field = "";
            this->electoral_district = "";
            this->position = "";
            this->party = "";
        }

        // constructor with given values for attributes
        AnggotaDPR(string id, string name, string field, string electoral_district, string position, string party)
        {
            this->id = id;
            this->name = name;
            this->field = field;
            this->electoral_district = electoral_district;
            this->position = position;
            this->party = party;
        }

        // getters and setters for each attribute

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

        string getElectoralDistrict()
        {
            return this->electoral_district;
        }

    
        void setElectoralDistrict(string electoral_district)
        {
            this->electoral_district = electoral_district;
        }

        string getPosition()
        {
            return this->position;
        }
        

        void setPosition(string position)
        {
            this->position = position;
        }

    
        string getParty()
        {
            return this->party;
        }

    
        void setParty(string party)
        {
            this->party = party;
        }

        // destructor
        ~AnggotaDPR(){

        }

};