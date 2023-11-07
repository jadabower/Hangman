#include <iostream>
#include <regex>
#include "GameManager.h"

using namespace std;

int main() {
    string playersChoice;
    do {
        // Ask the user for playersChoice
        cout << "Enter a secret word, 'random', or 'quit'." << endl;
        getline(cin, playersChoice);
        regex regexp("[A-Za-z]+");

        GameManager game;
        if (!regex_match(playersChoice, regexp)) {
            cout << "Please enter one word with no numbers, spaces, or special characters." << endl;
        } else {
            for (int i = 0; i < playersChoice.length(); i++) {
                playersChoice[i] = tolower(playersChoice[i]);
            }
            if (playersChoice == "quit") {
                cout << "Thanks for playing!";
            } else if (playersChoice != "random") {
                // Creates a game with a secret word
                game = GameManager(playersChoice);
                // Plays the game while it still should be running
                while (game.isPlaying) {
                    game.NextTurn();
                }
            } else {
                // Otherwise create a game with a random word
                game = GameManager();
                // Plays the game while it still should be running
                while (game.isPlaying) {
                    game.NextTurn();
                }
            }
        }
    } while (playersChoice != "quit");

    return 0;
}


//  _______      H _ N G M _ N
//  |     |
// \O/    |      A B C D E F -
//  |     |      - I J K L - -
// / \    |      O P Q R S T U
//_______/|\__   V W X Y Z

