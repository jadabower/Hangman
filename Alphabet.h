//
// Created by jadabower on 11/4/2023.
//

#ifndef HANGMAN_ALPHABET_H
#define HANGMAN_ALPHABET_H
#include <iostream>

using namespace std;

class Alphabet {
public:
    // Member variables
    string letterPool;
    string displayedLineOne;
    string displayedLineTwo;
    string displayedLineThree;
    string displayedLineFour;
    // Constructor
    Alphabet();
    // Methods
    void UpdateDisplayedAlphabetLines();
    string GetDisplayableDisplayedLine(string lineToDisplay);
    bool TryToUpdateAlphabet(char letterToTry);
};


#endif //HANGMAN_ALPHABET_H
