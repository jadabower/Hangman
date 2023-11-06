//
// Created by jadabower on 11/2/2023.
//

#ifndef HANGMAN_SECRETWORD_H
#define HANGMAN_SECRETWORD_H
#include <iostream>

using namespace std;

class SecretWord {
public:
    // Member variables
    string finalWord;
    string displayedWord;
    bool wordIsGuessed = false;
    // Methods
    void GenerateDisplayedWord();
    void UpdateDisplayedWord(char letterToGuess);
    string GetDisplayedWordAsDisplayable();
    string GetFinalWordAsDisplayable();
    void UpdateWordIsGuessed();
    bool TryGuessingLetter(char letterToGuess);
};


#endif //HANGMAN_SECRETWORD_H
