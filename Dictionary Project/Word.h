#pragma once
#ifndef WORD_H
#define WORD_H

#include<iostream>
#include<string>
#include<utility>

using namespace std;
class Word
{
public:

    Word() {}//Constructor
    Word(const Word& obj) {//copy constructor for word class
        this->name = obj.name;
        this->type = obj.type;
        this->defination = obj.defination;
    }

    void set_word(const string name, const string type, const string defination) { //setter method
        this->name = name;
        this->type = type;
        this->defination = defination;
    }
    pair<string, pair<string, string>> get_word() const { //getter method
        return { name,{type,defination} };//return name,type,defination in pair of pair format
    }
    virtual ~Word() {};//Destructor;

protected:

private:
    string name;//For string name.
    string type;//For string type.
    string defination;//For storing defination.
};

#endif // WORD_H
