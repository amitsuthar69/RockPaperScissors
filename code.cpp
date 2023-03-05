#include <bits/stdc++.h>
#include <ctime>

using namespace std;

void printFinalScore(int userscore, int computerscore)
{
    cout << "\nFinal Score - Your Score is: " << userscore << " " << " | " << "Computer Score is: " << computerscore << endl;
}

void printWinner(int userscore, int computerscore)
{
    if (userscore > computerscore)
    {
        cout << "\nYou Won!!" << endl;
    }
    else if (computerscore > userscore)
    {
        cout << "\nComputer Won!! Better Luck Next Time." << endl;
    }
    else
    {
        cout << "\nAhh, It's A Tie" << endl;
    }
}

int main() {
  srand(time(nullptr)); // initialize random seed

  // Options for the game
  string options[] = {"rock", "paper", "scissors"};
  int numOptions = sizeof(options) / sizeof(options[0]);
  int userscore = 0, computerscore = 0; // score tracking.
  
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
      userscore++;
      cout << "Your Score is: " << userscore << " " << "Computer Score is: " << computerscore << endl;
    } else {
      cout << "The computer wins!" << endl;
      computerscore++;
      cout << "Your Score is: " << userscore << " " << "Computer Score is: " << computerscore << endl;
    }

    // Ask if user wants to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    playAgain = tolower(playAgain);
    if (playAgain != 'y' && playAgain != 'Y') {
      break;
    }
    #ifdef __linux__
    system("clear");
    #elif _WIN32 || _WIN64
    system("cls");
    #endif
  }

  printFinalScore(userscore, computerscore);
  printWinner(userscore, computerscore);
  
  return 0;
}
