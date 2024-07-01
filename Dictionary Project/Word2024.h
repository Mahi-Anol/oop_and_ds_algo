#include<iostream>
#include<string>
#include<utility>
#include "Word.h"
using namespace std;

class Word2024:public Word
{
public:

    Word2024() {}//Constructor
    Word2024(const Word2024& obj) {//copy constructor for word class
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
    virtual ~Word2024() {};//Destructor;

protected:

private:
    string name;//For string name.
    string type;//For string type.
    string defination;//For storing defination.
};
