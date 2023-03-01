#include <bits/stdc++.h>
#include <ctime>

using namespace std;

int main() {
  srand(time(nullptr)); // initialize random seed

  // Options for the game
  string options[] = {"rock", "paper", "scissors"};
  int numOptions = sizeof(options) / sizeof(options[0]);

  while (true) {
    // Get user's choice
    string userChoice;
    cout << "Enter your choice (rock, paper, scissors): ";
    cin >> userChoice;

    for (char &c : userChoice){  //Making it case insensitive.
        c = tolower(c);  
    }
    
    // Check if user's choice is valid
    bool validChoice = false;
    for (int i = 0; i < numOptions; i++) {
      if (userChoice == options[i]) {
        validChoice = true;
        break;
      }
    }

    if (!validChoice) {
      cout << "Invalid choice, please try again." << endl;
      continue;
    }

    // Generate computer's choice
    int computerChoiceIndex = rand() % numOptions;
    string computerChoice = options[computerChoiceIndex];

    // Print choices
    cout << "You chose " << userChoice << "." << endl;
    cout << "The computer chose " << computerChoice << "." << endl;

    // Determine winner
    if (userChoice == computerChoice) {
      cout << "It's a tie!" << endl;
    } else if ((userChoice == "rock" && computerChoice == "scissors") ||
               (userChoice == "paper" && computerChoice == "rock") ||
               (userChoice == "scissors" && computerChoice == "paper")) {
      cout << "You win!" << endl;
    } else {
      cout << "The computer wins!" << endl;
    }

    // Ask if user wants to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    playAgain = tolower(playAgain);
    if (playAgain != 'y' && playAgain != 'Y') {
      break;
    }
    system("cls");
  }

  return 0;
}
