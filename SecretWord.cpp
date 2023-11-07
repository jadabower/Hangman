//
// Created by jadabower on 11/2/2023.
//

#include "SecretWord.h"
#include <regex>

// Generates the displayedWord varible to be a string of underscores the length of finalWord
void SecretWord::GenerateDisplayedWord() {
    for (int i = 0; i < finalWord.length(); i++) {
        // Adds underscores to the displayedWord for each character in the finalWord
        displayedWord += "_";
    }
}

// Updates the displayedWord variable to replace the underscore with the letter in the correct spot
void SecretWord::UpdateDisplayedWord(char letterToGuess) {
    for (int i = 0; i < finalWord.length(); i++) {
        // Adds the guessed character in the correct positions
        if (finalWord[i] == letterToGuess) {
            displayedWord[i] = toupper(letterToGuess);
        }
    }
}

// Returns a string of the displayedWord with spaces between the letters
string SecretWord::GetDisplayedWordAsDisplayable() {
    string result;
    for (int i = 0; i < finalWord.length(); i++) {
        if (i == finalWord.length() - 1)
            result += displayedWord[i];
        else
            result += displayedWord[i] + string(" ");
    }
    return result;
}

// Returns a string of the finalWord with spaces between the letters
string SecretWord::GetFinalWordAsDisplayable() {
    string result;
    for (int i = 0; i < finalWord.length(); i++) {
        if (i == finalWord.length() - 1)
            result += (char)toupper(finalWord[i]);
        else
            result += (char)toupper(finalWord[i]) + string(" ");
    }
    return result;
}

// Updates wordIsGuessed based on whether the displayedWord has any underscores or not
void SecretWord::UpdateWordIsGuessed() {
    regex regexp("[A-Za-z]+");
    wordIsGuessed = regex_match(displayedWord, regexp);
}

// If the finalWord contains the letter they guessed, update displayedWord and wordIsGuessed and return true
// Otherwise, return false
bool SecretWord::TryGuessingLetter(char letterToGuess) {
    bool contains = false;
    for (int i = 0; i < finalWord.length(); i++) {
        // Checks if the letterToGuess is in the SecretWord
        if (finalWord[i] == letterToGuess) {
            contains = true;
        }
    }
    if (!contains) {
        // If the word does not contain the letter guessed, return false
        return false;
    }
    // Otherwise, call the functions to guess the letter and return true
    UpdateDisplayedWord(letterToGuess);
    UpdateWordIsGuessed();
    return true;
}