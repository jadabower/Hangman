//
// Created by jadabower on 11/4/2023.
//

#include "GameManager.h"
#include <stdlib.h>
#include <regex>
#include <iostream>
#include <utility>
#include <vector>

// Creates a new game with a random secret word
GameManager::GameManager() {
    secretWord.finalWord = GetRandomWord();
    secretWord.GenerateDisplayedWord();
}

// Creates a new game with the word they gave
GameManager::GameManager(string inputtedWord) {
    secretWord.finalWord = std::move(inputtedWord);
    secretWord.GenerateDisplayedWord();
}

// Gets a random word from a pre-defined list of words
string GameManager::GetRandomWord() {
    // Creates a vector with a bunch of pre-defined random words
    std::vector<string> words{ "social", "random", "quit", "medicine", "lose", "honor", "measure", "thick", "map", "straight", "accent", "roof", "purpose", "thank", "arrange", "endorse", "context", "mall", "drawing", "pizza", "church", "product", "priority", "movie", "menu", "week", "leader", "people", "thing", "vehicle" };
    // Gets a random index of the vector
    static bool first = true;
    if (first)
    {
        // Seeding for the first time only
        srand( time(NULL) );
        first = false;
    }
    int randomIndex = std::rand() % (( words.size() + 1 ));
    // Returns the word at the random index
    string randomWord = words[randomIndex];
    return randomWord;
}

// Plays the next turn (ends if they are out of lives or have guessed the word correctly)
void GameManager::NextTurn() {
    // End the game if they are out of lives or have guessed the word
    if (lives < 1) {
        DisplayGame();
        isPlaying = false;
    } else if (secretWord.wordIsGuessed) {
        DisplayGame();
        cout << "Congratulations! You won!" << endl;
        isPlaying = false;
    }
    // Otherwise, continue playing
    else {
        DisplayGame();
        string letterToTryAsString;
        bool letterIsValid;
        char letterToTry;
        do {
            // Ask the user for letterToTryAsString
            cout << "Enter a single letter from the displayed alphabet (no spaces or special characters)" << endl;
            getline(cin, letterToTryAsString);
            // Make the guessed letter a char
            letterToTry = tolower(letterToTryAsString[0]);
            // Checks that they didn't put '-'
            if (letterToTry == '-') {
                letterIsValid = false;
            } else {
                // See if that is a valid char (if it is, delete it from the alphabet and move on)
                letterIsValid = alphabet.TryToUpdateAlphabet(letterToTry);
            }
        } while (!letterIsValid);
        bool inSecretWord = secretWord.TryGuessingLetter(letterToTry);
        if (!inSecretWord) {
            lives -= 1;
        }
    }
}

// Displays the gallows, word, and word bank (changes depending on how many lives they have and
// what they have guessed already)
void GameManager::DisplayGame() {
    if (lives >= 6) {
        cout << "  _______      ";
        // Displays the secret word in all caps and spaced out, depending on what letters they have guessed
        cout << secretWord.GetDisplayedWordAsDisplayable() << endl;
        cout << "  |     |" << endl;
        cout << "        |      ";
        // Displays the first line of the alphabet (word bank)
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineOne) << endl;
        cout << "        |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineTwo) << endl;
        cout << "        |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineThree) << endl;
        cout << "_______/|\\__   ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineFour) << endl;
        cout << endl;
    } else if (lives == 5) {
        cout << "  _______      ";
        cout << secretWord.GetDisplayedWordAsDisplayable() << endl;
        cout << "  |     |" << endl;
        // Adds a head
        cout << "  O     |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineOne) << endl;
        cout << "        |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineTwo) << endl;
        cout << "        |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineThree) << endl;
        cout << "_______/|\\__   ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineFour) << endl;
        cout << endl;
    } else if (lives == 4) {
        cout << "  _______      ";
        cout << secretWord.GetDisplayedWordAsDisplayable() << endl;
        cout << "  |     |" << endl;
        // Adds an arm
        cout << " \\O     |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineOne) << endl;
        cout << "        |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineTwo) << endl;
        cout << "        |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineThree) << endl;
        cout << "_______/|\\__   ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineFour) << endl;
        cout << endl;
    } else if (lives == 3) {
        cout << "  _______      ";
        cout << secretWord.GetDisplayedWordAsDisplayable() << endl;
        cout << "  |     |" << endl;
        // Adds an arm
        cout << " \\O/    |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineOne) << endl;
        cout << "        |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineTwo) << endl;
        cout << "        |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineThree) << endl;
        cout << "_______/|\\__   ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineFour) << endl;
        cout << endl;
    } else if (lives == 2) {
        cout << "  _______      ";
        cout << secretWord.GetDisplayedWordAsDisplayable() << endl;
        cout << "  |     |" << endl;
        cout << " \\O/    |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineOne) << endl;
        // Adds a body
        cout << "  |     |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineTwo) << endl;
        cout << "        |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineThree) << endl;
        cout << "_______/|\\__   ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineFour) << endl;
        cout << endl;
    } else if (lives > 0) {
        cout << "  _______      ";
        cout << secretWord.GetDisplayedWordAsDisplayable() << endl;
        cout << "  |     |" << endl;
        cout << " \\O/    |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineOne) << endl;
        cout << "  |     |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineTwo) << endl;
        // Adds a leg
        cout << " /      |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineThree) << endl;
        cout << "_______/|\\__   ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineFour) << endl;
        cout << endl;
    } else {
        cout << "  _______      ";
        cout << secretWord.GetFinalWordAsDisplayable() << endl;
        cout << "  |     |" << endl;
        cout << " \\O/    |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineOne) << endl;
        cout << "  |     |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineTwo) << endl;
        // Adds a leg
        cout << " / \\    |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineThree) << endl;
        cout << "_______/|\\__   ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineFour) << endl;
        cout << endl;
        cout << "Game over, better luck next time!" << endl;
    }
}
