#include "Dictionary.h"
#include "word.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<conio.h>
using namespace std;

Dictionary::Dictionary() {}//Constructor
int Dictionary::dict_size()
{
    return dict.size();
}
void Dictionary::load_dictionary() {
    cout << "Enter the dictionary filename which you want to load.  (Ex:- dict.txt)" << endl;
    string file_name;//Enter the file name which you want to load.
    getline(cin, file_name);
    //Ignore the new line character to avoid interferance in with the getline function.
    cout << "You have entered " << (file_name.empty() ? "Nothing" : "\"" + file_name + "\"") << " as your file name." << endl;
    ifstream reader;

    if (!file_name.empty())
    {
        reader.open(file_name);
        if (!reader.is_open())
        {
            cout << "Selected file not found in the directory. The Program will terminate now" << endl;
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        cout << "As you havent entered any file name the programing will open \"dictionary_2024S1.txt\" file by default." << endl;
        reader.open("dictionary_2024S1.txt");
        if (!reader.is_open())
        {
            cout << "Unexpected error while opening the default Dictionary file. The program will terminate now." << endl;
            exit(EXIT_FAILURE);
        }
    }


    while (!reader.eof())
    {
        string name_temp;
        string type_temp;
        string defination_temp;
        getline(reader, type_temp);//Reading string of each line from the text file
        getline(reader, defination_temp);//Reading string of each line from the text file
        getline(reader, name_temp);//Reading string of each line from the text file
        if (name_temp.size() > 6)
        {
            name_temp = name_temp.substr(6, name_temp.size() - 6);
        }
        string extra_line;
        getline(reader, extra_line);//Eliminate the new line of the ifstream.
        if (name_temp != "")
        {
            Word unit; //Creating unit of class to store each line and push to vector.
            unit.set_word(name_temp, type_temp, defination_temp);//using setter method to store inside the object for word class.
            dict.push_back(unit);// Pushing the unit to the vector which is storing the dictionary.

        }
    }
    if (reader.is_open())reader.close();//Closing the file after performing the file read operation.
    cout << "\n........Finished loading the dictionary file\n " << endl;


}

string Dictionary::search_method(string searchWord) {

    ///This function will return the matching string which it finds with the searched word.
    //If such word is not found. Then it will return empty string.
    static int counter = 0;// For performing search continously, I am using recursion calls. Using a static variable to keep track of number of recursion calls.
    //will be needed in future.
    ///if this is not the first function call then the program will ask user if we want to stop searching or not?
    if (counter != 0)
    {
        cout << "Would you like to stop searching? (Y/N)" << endl;
        char ch;
        cin >> ch;
        cin.ignore();//The avoid interferance of getline function in future.
        if (ch == 'Y' || ch == 'y')
        {
            counter = 0;
            return "";//Returning Empty string  as the function expects a return value.
        }
    }

    bool flag_str = false;
    //If the function was called with a empty string then it was called from menu function.(it is represented by flag==false)
    // else it was called from append function it means the parameter of function was not empty so the flag value is set to true;

    if (searchWord == "")
    {
        cout << "Enter the word you want to search: ";
        getline(cin, searchWord);//Enter the search Word.
    }
    else
    {
        ///Havent called from improved class so flag_str==true
        flag_str |= true;
    }


    // A lambda function to convert each charecter of the search word to lower case
    [&]()
        {
            for (auto& i : searchWord)
            {
                i = i >= 97 ? i : tolower(i);// converting upper case letters to lowercase.
            }

        }();

        string name;//Some string variables which will be needed to unpack the word objects inside the dictionary vector(STL) inside the dictionary class.
        string type;
        string defination;

        auto it = dict.begin();
        for (; it != dict.end(); it++)// A for loop for iterating over the vector where the dictionery is stored.
        {
            name = it->get_word().first;// get_word function retruns pair<string,pair<string,string>>
            type = it->get_word().second.first;//......as follows
            defination = it->get_word().second.second;//......as follows
            // A lambda function to convert each charecter of the search word to lower case
            [&]()
                {
                    for (auto& i : name)
                    {
                        i = i >= 97 ? i : tolower(i);// converting upper case letters to lowercase.
                    }

                }();
                if (name == searchWord)break;// The word which we are searching has matched with a word inside the dictionary.
                //So we are going to break the loop as no more futher iteration needed.
        }


        if (it == dict.end())
        {
            cout << "word not found." << endl;
            counter++;

            if (!flag_str)///Wasnt called from improved class.append function so search untill the user enters 'Y'.
            {
                counter++;
                return search_method("");
            }
            else
                return "";

        }
        else
        {
            //The word is found.
            if (flag_str) {
                ///As it was called from improved class append function ,we dont need to print.
                return searchWord;//tai further search dorker nai ejonno return.
            }
            else {
                cout << "\n\n::::Here is the complete description of the found word:::: \n\n";
                cout << "Searched word: " << name << endl;
                cout << type << endl;
                cout << defination << endl;// dereferancing pointer to print the units.
                cout << "\n";
                counter++;
                search_method("");
                return searchWord;
            }
        }
}

void Dictionary::menu() {

    bool flag = true;
    while (flag) {
        cout << "What operation would you like to perform now? \n" << endl;
        cout << "--Here is the list of available options--" << endl;
        cout << "1. Load a Dictionary(txt) file." << endl;
        cout << "2. Search a word from the loaded dictionary file" << endl;
        cout << "3. Exit" << endl;
        cout << "--------Enter your prefered operation number(1 or 2 or 3) as input---------" << endl;
        char choice;
        cin >> choice;
        cin.ignore();//To avoid giving getline function a unexpected input.

        switch (choice) {

        case '1':
            cout << "You have decided to load a dictionary file." << endl;
            load_dictionary();
            break;

        case '2':
            cout << "You have decided to search a word from the dictionary file." << endl;
            search_method("");
            break;
        case '3':
            cout << "You have decided to exit." << endl;
            flag = false;
            break;
        default:
            cout << "You have entered an invalid choice , if you want to exit then enter '3'." << endl;
            break;
        }
    }
}



Dictionary::~Dictionary()
{
    //dtor
}
