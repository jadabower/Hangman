//
// Created by jadabower on 11/4/2023.
//

#include "GameManager.h"
#include <regex>
#include <iostream>
#include <utility>
#include <vector>

GameManager::GameManager() {
    secretWord.finalWord = GetRandomWord();
    secretWord.GenerateDisplayedWord();
}

GameManager::GameManager(string inputtedWord) {
    secretWord.finalWord = std::move(inputtedWord);
    secretWord.GenerateDisplayedWord();
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

void GameManager::NextTurn() {
//    system("CLS");
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
            // See if that is a valid char (if it is, delete it from the alphabet and move on)
            letterIsValid = alphabet.TryToUpdateAlphabet(letterToTry);
        } while (!letterIsValid);
        bool inSecretWord = secretWord.TryGuessingLetter(letterToTry);
        if (!inSecretWord) {
            lives -= 1;
        }
    }
}

void GameManager::DisplayGame() {
    if (lives >= 6) {
        cout << "  _______      ";
        cout << secretWord.GetDisplayedWordAsDisplayable() << endl;
        cout << "  |     |" << endl;
        cout << "        |      ";
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
        cout << " / \\    |      ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineThree) << endl;
        cout << "_______/|\\__   ";
        cout << alphabet.GetDisplayableDisplayedLine(alphabet.displayedLineFour) << endl;
        cout << endl;
        cout << "Game over, better luck next time!" << endl;
    }
}
