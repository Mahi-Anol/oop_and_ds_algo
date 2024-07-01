#pragma once
#ifndef IMPROVEDDICTIONARY_H
#define IMPROVEDDICTIONARY_H

#include "Dictionary.h"
#include "Word.h"
#include "Word2024.h"
#include "Dictionary.h"
#include "ImprovedDictionary.h"


class ImprovedDictionary :public Dictionary
{
public:
    ImprovedDictionary();
    void menu() override;
    void Palindrome_words();
    void guess_the_fouth__word();
    void append_new_word();
    void rhyming_words();
    virtual ~ImprovedDictionary();

protected:

private:
};

#endif // IMPROVEDDICTIONARY_H
