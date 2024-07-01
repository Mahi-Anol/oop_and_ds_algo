#include "ImprovedDictionary.h"
#include "Dictionary.h"
#include "Word.h"
#include "Word2024.h"
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include <ctime>


using namespace std;
ImprovedDictionary::ImprovedDictionary()
{
    //ctor
}
void ImprovedDictionary::append_new_word() {

    string name;
    string type;
    string defination;
    cout << "-----write everything in lower-case letter to maintain dictionary format-----" << endl << endl;
    cout << "Enter word name: ";
    getline(cin, name);
    cout << "Enter type: ";
    getline(cin, type);
    cout << "Enter defination: ";
    getline(cin, defination);
    cout << endl;


    if (search_method(name) == name)
    {
        cout << "error: word exists, elevated privileges required to edit existing words." << endl;

    }
    else {

        if ((type == "v" || "n" || "adv" || "adj" || "prep" || "pn" || "n_and_v" || "misc") && name != "")
        {
            cout << "The Word is of a valid type. Now the program will try to append this word in the dictionary" << endl;

            string temp = "Type: ";//Is we ignore these parts previous.....We are adding these again to
            //save the dictionary in correct format.
            type = temp + type;
            temp = "Defination: ";
            defination = temp + defination;

            Word unit;
            unit.set_word(name, type, defination);
            dict.push_back(unit);

            ///after adding the word we have to maintain the lexiographical order.
            //Thats why we are going to sort the dictionary vector.
            sort(dict.begin(), dict.end(), [](const Word& a, const Word& b) {return a.get_word().first < b.get_word().first; });

            char decission;
            cout << "Do you want to append the word in the original Dictionary? (Y/N): ";
            cin >> decission;
            cout << endl;
            string fn;
            if (decission == 'N')
            {
                cout << "Enter the file name in which you want to save the details" << endl;
                cin >> fn;
            }

            ofstream file((decission == 'N' ? fn : "dictionary_2024S1.txt"));//Orginal_file

            for (auto it : dict)
            {

                string name = "Word: " + it.get_word().first;
                string type = it.get_word().second.first;
                string defination = it.get_word().second.second;
                file << type;
                file << endl;
                file << defination;
                file << endl;
                file << name;
                file << endl;
                file << endl;
            }

        }
        else {
            cout << "INVALID type for a word" << endl;
        }
    }


}

void ImprovedDictionary::guess_the_fouth__word()
{
    cout << "\nWelcome to \"guess the fourth word game\".\n" << endl;
    int dict_size = dict.size();//THe size is needed for dynamic allocation.
    if (dict_size == 0) {
        cout << "If havent loaded any Dicionary file yet. Please load a dictionary file first." << endl;
        return;
    }

    bool* random_flag = new bool[dict_size] {false};//Dynamic Allocation for keeping track of selected words.(It will work like a hashmap to cheak if current word was selected before or not.)

    srand(time(0));//Tie random seed with current time.

    int div = ((dict_size + RAND_MAX) / RAND_MAX); // Finding quotient to genarate which will be useful later.
    int r_div = ((dict_size + RAND_MAX) % RAND_MAX); // Keeping the track of reminder.(will be needing this too.

    int score = 0;
    int hscore = 0;
    ifstream highscore("highscore.txt");

    if (!highscore.is_open())
    {
        hscore = 0;
    }
    else {
        highscore >> hscore;
        highscore.close();
    }
    while (1)
    {
        int num = RAND_MAX > dict_size ? rand() % dict_size : ((rand() * div) + r_div) % dict_size; //Genarating random number between (RAND_MAX to RAND_MAX+dict_size) and after
        //that normalizaing with respect to dict_size to make the number between 0 to dict_size;
        if (random_flag[num])continue;
        else {
            random_flag[num] = true;

            string target_word_def = dict[num].get_word().second.second;//Selected random words defination.
            int sz_of_str = target_word_def.size();//size of the defination string.

            int number_of_white_space = 0;//for calculating number of white space and finding the fourth word.

            int fourth_words_f_index = -1;//Foruth words first index.//setting to -1 for reassurance during cheaking.
            int fourth_words_l_index = -1;//Fourth words last index.//setting to -1 for reassurance during cheaking.

            bool idx_flag = true;
            bool idx_flag2 = true;

            for (int i = 12; i < sz_of_str; i++)//staring from index 12 because thats where the first white space is.
            {
                if (number_of_white_space == 3 && idx_flag)
                {
                    fourth_words_f_index = i;
                    idx_flag = false;
                }
                if (number_of_white_space == 3 && (target_word_def[i + 1] == ' ' || target_word_def[i + 1] == ';' || target_word_def[i + 1] == '.') && idx_flag2)
                {
                    fourth_words_l_index = i;
                    idx_flag2 = false;
                }
                if (target_word_def[i] == ' ')
                {
                    number_of_white_space++;

                }
            }
            if (number_of_white_space < 4)continue;//There are less than 4 words in the defination so we have to ignore.
            else {

                string name, type, defination, fourth_word;
                name = dict[num].get_word().first;
                type = dict[num].get_word().second.first;
                defination = dict[num].get_word().second.second;
                //Storing fourth word.........

                fourth_word = defination.substr(fourth_words_f_index, fourth_words_l_index - fourth_words_f_index + 1);

                cout << "Now You have to guess the fourth word of the defination.(fill the blanks)." << endl;
                cout << "-------------------Start----------------" << endl;
                cout << "your score: " << score << "                                  " << "High Score: " << hscore << endl;
                cout << endl;
                cout << "Word: " << name << endl;
                cout << type << endl;
                for (int i = 0; i < sz_of_str; i++)
                {
                    if (i<fourth_words_f_index || i>fourth_words_l_index)
                    {
                        cout << defination[i];
                    }
                    else cout << "_";
                }

                cout << "\nNow enter your guess for the missing word: ";
                string guess;
                cin >> guess;

                if (guess == fourth_word)
                {
                    cout << "\n**********Congratulations**************" << endl;
                    cout << "\nYou are absolutely correct." << endl;
                    score += 10;
                    continue;
                }
                else
                {

                    cout << "\nOops.....Wrong prediction" << endl;
                    cout << "\nCorrect ans is: " << fourth_word << endl;
                    cout << endl;
                    cout << "Your final score is: " << score << endl;
                    if (score > hscore)
                    {
                        cout << "Congratz~! You have a new highscore." << endl;
                        ofstream savescore("highscore.txt");
                        savescore << score;
                        savescore.close();
                    }
                    break;

                }
            }
        }
    }


    delete[] random_flag;//Deallocation of the flag array.


}

void ImprovedDictionary::rhyming_words()
{
    cout << "Enter the word(atleast 3 character) with which you want to compare the rhyming words: ";
    string rhyme;
    cin >> rhyme;//Enter the word whith which you want to compare;
    cin.ignore();

    int len = rhyme.size();

    if (len < 3)
    {

        cout << "If have entered a word which is less than 3 charecter. So the progaming will going back to main menu." << endl;
        return;
    }

    rhyme = rhyme.substr(len - 3, 3);


    [&]()
        {
            for (auto& i : rhyme)
            {
                i = i >= 97 ? i : tolower(i);// converting upper case letters to lowercase.
            }

        }();

        auto it = dict.begin();

        int counter = 0;

        bool flag = true;
        for (; it != dict.end(); it++)
        {
            string name_temp = it->get_word().first;
            int ss = name_temp.size();//string size
            if (ss < 3)continue;
            name_temp = name_temp.substr(ss - 3, 3);
            if (name_temp == rhyme)
            {
                if (flag) {
                    cout << "\n----Founded Rhyming words are----\n" << endl;
                    flag = false;
                }
                cout << it->get_word().first << endl;
                counter++;
            }
        }

        if (counter == 0)cout << "No rhyming word found." << endl;

}

void ImprovedDictionary::Palindrome_words()
{
    auto it = dict.begin();

    for (; it != dict.end(); it++)
    {
        string name_temp = it->get_word().first;
        reverse(name_temp.begin(), name_temp.end());
        if (it->get_word().first == name_temp)
        {

            cout << it->get_word().first << endl;
        }
    }
}
void ImprovedDictionary::menu()
{

    bool flag = true;
    while (flag) {
        cout << "What operation would you like to perform now? \n" << endl;
        cout << "--Here is the list of available options--" << endl;
        cout << "1. Load a Dictionary(txt) file." << endl;
        cout << "2. Search a word from the loaded dictionary file" << endl;
        cout << "3. Print all the palindromes" << endl;
        cout << "4. Print rhyming words." << endl;
        cout << "5. Guess the fourth Word challange" << endl;
        cout << "6. Add new word to the dictionary" << endl;
        cout << "7. Exit" << endl;
        cout << "--------Enter your prefered operation number(1 or 2 or 3) as input---------" << endl;
        char choice;
        cin >> choice;
        //To avoid giving getline function a unexpected newline input from the stream.
        cin.ignore();
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
            cout << "You have decided to print all the palindrome words from the dictionary." << endl;
            Palindrome_words();
            break;

        case '4':
            cout << "You have decided to print rhyming words" << endl;
            rhyming_words();
            break;

        case '5':
            guess_the_fouth__word();
            break;
        case '6':
            cout << "Looks like you want to add a new file to the dictionary" << endl;
            append_new_word();
            break;

        case '7':
            cout << "You have decided to exit from the program" << endl;
            flag = false;
            break;

        default:
            cout << "You have entered an invalid choice , if you want to exit the enter '7' as choice" << endl;
            break;
        }
    }
}

ImprovedDictionary::~ImprovedDictionary()
{
    //dtor
}
//Prologue:
// //The ImprovedDictionary class contains the primary functionality of the programme and includes methods for the described activities.
// The programme employs several C++ technologies, including file management, text manipulation, dynamic memory allocation, 
// and lambda expressions.
//This C++ programme develops an enhanced dictionary application with several functionalities.
// The application enables users to import a dictionary from a text file, do word searches, and add new terms.
//Engage in a game where you attempt to determine the fourth word in a given definition,
//  identify words that rhyme with a given phrase, and produce a printed output.
// and print palindorme words 
// Author: Saima Eva 
// Date: 16/05/2024
