#pragma once
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include<vector>
#include "word.h"

using namespace std;

class Dictionary
{
public:
    Dictionary();
    void load_dictionary();//used for loading the dictionary file into vector class
    int dict_size();//Returns the size of the current dictory (aka number of words)
    string search_method(string);//For searching a word in the dictionary
    virtual void menu();//Menu which shows the functionalities.
    virtual ~Dictionary();//Destructor for dictionary class

protected:
    vector<Word> dict;//A vector to store the Word objects..
    ///Its protected because this will be inherited to the ImprovedDictionary child class in future.
private:

};

#endif // DICTIONARY_H
