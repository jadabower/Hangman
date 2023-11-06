//
// Created by jadabower on 11/4/2023.
//

#include "Alphabet.h"

Alphabet::Alphabet() {
    letterPool = "abcdefghijklmnopqrstuvwxyz";
    UpdateDisplayedAlphabetLines();
}

void Alphabet::UpdateDisplayedAlphabetLines() {
    for (int i = 0; i < 7; i++) {
        displayedLineOne[i] = letterPool[i];
    }
    for (int i = 7; i < 14; i++) {
        displayedLineTwo[i - 7] = letterPool[i];
    }
    for (int i = 14; i < 21; i++) {
        displayedLineThree[i - 14] = letterPool[i];
    }
    for (int i = 21; i < 26; i++) {
        displayedLineFour[i - 21] = letterPool[i];
    }
}

string Alphabet::GetDisplayableDisplayedLine(string lineToDisplay) {
    string result;
    for (int i = 0; i < lineToDisplay.length(); i++) {
        // Returns the displayed line with spaces between the letters
        if (i == lineToDisplay.length() - 1)
            result += toupper(lineToDisplay[i]);
        else
            result += toupper(lineToDisplay[i]) + ' ';
    }
    return result;
}

bool Alphabet::TryToUpdateAlphabet(char letterToTry) {
    bool contains = false;
    for (int i = 0; i < letterPool.length(); i++) {
        // Checks if the letterToTry is in the letterPool
        if (letterPool[i] == letterToTry) {
            // If it does, set contains to true and change the letter in the pool to a dash
            contains = true;
            letterPool[i] = '-';
        }
    }
    // Return whether the letter was a valid input or not;
    return contains;
}