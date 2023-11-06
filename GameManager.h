//
// Created by jadabower on 11/4/2023.
//

#ifndef HANGMAN_GAMEMANAGER_H
#define HANGMAN_GAMEMANAGER_H
#include <iostream>
#include <stdlib.h>
#include "SecretWord.h"
#include "Alphabet.h"

using namespace std;

class GameManager {
    public:
        // Member variables
        int lives = 6;
        bool isPlaying = true;
        SecretWord secretWord;
        Alphabet alphabet;
        // Constructors
        GameManager();
        explicit GameManager(string inputtedWord);
        // Methods
        string GetRandomWord();
        void NextTurn();
        void DisplayGame();
};


#endif //HANGMAN_GAMEMANAGER_H
