#include <iostream>
#include <limits>
#include <ctime>

class Game {
public:
    void play() {
        srand(time(0));
        bool isWinner = false;
        int compSecret = rand() % 100;

        std::cout << "Enter your secret number between 0 and 99: ";
        std::cin >> userSecret;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter your secret number between 0 and 99: ";
            std::cin >> userSecret;
        }

        while (!isWinner) {
            int guess = (compLow + compHigh) / 2;
            std::cout << "Computer's guess = " << guess << "\n";

            if (guess == userSecret) {
                std::cout << "Computer Won !\n"
                          << "Sorry you lost\n"
                          << "Computer's guess was " << compSecret << "\n";
                isWinner = true;
            } else {
                if (guess > userSecret) {
                    std::cout << "Guess is too high\n";
                    compHigh = guess - 1;
                } else {
                    std::cout << "Guess is too low\n";
                    compLow = guess + 1;
                }
                isWinner = playerTurn(compSecret);
            }
        }

        playAgain();
    }

private:
    bool playerTurn(int compSecret) {
        int guess;
        std::cout << "Enter your guess = ";
        std::cin >> guess;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter your guess: ";
            std::cin >> guess;
        }

        if (guess > compSecret) {
            std::cout << "Your guess is too high\n";
            return false;
        }
        if (guess < compSecret) {
            std::cout << "Your guess is too low\n";
            return false;
        }
        std::cout << "Congratulations you won";
        return true;
    }

    void playAgain() {
        char ch;
        std::cout << "\nEnter 'Y' to play again :- ";
        std::cin >> ch;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter 'Y' to play again :- ";
            std::cin >> ch;
        }

        if (ch == 'y' || ch == 'Y') {
            play();
        }
    }

    int userSecret;
    int compLow = 0;
    int compHigh = 100;
};

int main() {
    Game game;
    game.play();

    return 0;
}