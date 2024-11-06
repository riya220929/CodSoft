#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int main() {
    // Seed the random number generator
    std::srand(std::time(0));
    
    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;
    int guess;

    std::cout << "Guess the number between 1 and 100:\n";

    // Loop until the correct guess
    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess > randomNumber) {
            std::cout << "Too high! Try again.\n";
        } else if (guess < randomNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number.\n";
            break;
        }
    }

    return 0;
}
