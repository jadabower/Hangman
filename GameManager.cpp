//
// Created by jadabower on 11/4/2023.
//

#include "GameManager.h"

#include <iostream>
#include <utility>
#include <vector>

GameManager::GameManager() {
    secretWord = GetRandomWord();
    displayedWord = GenerateDisplayedWord(secretWord);

}

GameManager::GameManager(string inputtedWord) {
    secretWord = std::move(inputtedWord);
    displayedWord = GenerateDisplayedWord(secretWord);
}

string GameManager::GenerateDisplayedWord(const string& givenWord) {
    // Creates an empty result string
    string resultString;
    for (int i = 0; i < givenWord.length(); i++) {
        // Adds underscores for each character in the givenWord
        if (i == givenWord.length() - 1)
            resultString += "_";
        else
            resultString += "_ ";
    }
    // Returns the result
    return resultString;
}

string GameManager::GetRandomWord() {
    // Creates a vector with a bunch of pre-defined random words
    std::vector<string> words{ "social", "random", "quit", "medicine", "lose", "honor", "measure", "thick", "map", "straight", "accent", "roof", "purpose", "thank", "arrange", "endorse", "context", "mall", "drawing", "pizza", "church", "product", "priority", "movie", "menu", "week", "leader", "people", "thing", "vehicle" };
    // Gets a random index of the vector
    int randomIndex = ( std::rand() % ( words.size() + 1 ) );
    // Returns the word at the random index
    string randomWord = words[randomIndex];
    return randomWord;
}
