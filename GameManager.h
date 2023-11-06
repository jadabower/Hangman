//
// Created by jadabower on 11/4/2023.
//

#ifndef HANGMAN_GAMEMANAGER_H
#define HANGMAN_GAMEMANAGER_H
#include <iostream>
#include <stdlib.h>

using namespace std;

class GameManager {
    public:
        // declarations
        int livesLeft = 6;
        bool isPlaying = true;
        string secretWord;
        string displayedWord;
        GameManager();
        explicit GameManager(string inputtedWord);
        static string GenerateDisplayedWord(const string& givenWord);
        string GetRandomWord();
        void NextTurn();
};


#endif //HANGMAN_GAMEMANAGER_H
