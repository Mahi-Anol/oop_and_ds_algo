#include "Word.h"
#include "Dictionary.h"
#include "ImprovedDictionary.h"
#include "Dictionary.cpp"
#include "ImprovedDictionary.cpp"
#include<iostream>
#include<utility>
#include<string>
using namespace std;

signed main(void)
{
    cout << "Welcome to Saima Dictionary LTD." << endl;
    //    Dictionary saima;//Creating a object of dictionary class.
    //    saima.menu();//calling the menu method of the dictionary class.

    ImprovedDictionary saima2;//Object of child class.(sub class)

    Dictionary* ptr; //Pointer of base class /super class;
    ptr = &saima2; //assigning base class pointer with subclass object.
    ptr->menu();//Performing runtime binding(method override) for menu method using base class pointer.
    /// Here the menu function base class has been overridden with child class menu function. 

    return 0;
}
// functionality:  Creating a vector of template class to store the dictionary file as unit
    // and Importing dictoionary file to the vector class and function to search specific word
    // Name: Saima Eva
    // Date: 16/05/24
// Program Name: Saima Dictionary LTD.
//Description: This program demonstrates the functionality of Saima Dictionary LTD., a fictional dictionary application.
//The code uses the principles of inheritance and polymorphism to demonstrate a base class (Dictionary)
// and its derived class (ImprovedDictionary).The primary function initialises the dictionary and presents a menu for interacting with the dictionary's features.

//Prologue :
    //-Includes necessary header files for the program.
    //- Defines the main function.
    //- Instantiates objects of Dictionary and ImprovedDictionary classes.
    //- Utilizes a pointer to the base class to demonstrate runtime polymorphism by invoking overridden methods.

