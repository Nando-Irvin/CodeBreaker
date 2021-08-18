#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include <iomanip>
#include <fcntl.h>



int main() {

	srand(time(0));
	std::vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
	std::random_shuffle(vec.begin(), vec.end());
	vec.resize(4);

	int randNumber = 0;
	for (auto i = vec.begin(); i != vec.end(); ++i) {
		randNumber = 10 * randNumber + (*i);
	}
	
	int* ref = &randNumber;
	int guess = 0;
	int guessCount = 0;
	int guessLimit = 8;
	int fDigit = 0;
	int sDigit = 0;
	std::string playAgain;

	std::cout << "\tWelcome to the awesome Code Breaking Game!! \n\n" << std::endl;
	std::cout << "Try to break the code by guessing a number of four digits, the digits cannot be repeated\nand for a clue, whenever you get the last digit correct you will get a message" << std::endl;
	std::cout << "you have 8 attempts. Good luck!! you can do it!!\n" << std::endl;
	std::cout << "Guess the code:" << std::endl;
	while (randNumber != guess) {
		
		while (!(std::cin >> guess))
		{
			std::cout << "Error: Opps!! thats not a valid number, try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(123, '\n');
		}
		if (guess > randNumber) {
				fDigit = guess % 10;	
				sDigit = randNumber % 10;
			
				if (fDigit == sDigit)
					{
						printf(" %d This last digit is correct\n", fDigit);
					}
			guessCount++;
			std::cout << "That guess is too high, try again:\n"  << std::endl;
		}
		if (guess < randNumber) {

			fDigit = guess % 10;
			sDigit = randNumber % 10;

			if (fDigit == sDigit)
			{
				printf("%d  This last digit is correct\n", fDigit);
			}
			guessCount++;
			std::cout << "That guess is too low, try again:\n"  << std::endl;
			
		}
		if (guess == randNumber) {
			std::cout << "\nCONGRATULATION!!!, YOU DID IT!! Number of turns you have used: " << guessCount + 1 << std::endl;
			std::cout << "Would you like to play again? (Yes or no) " << std::endl;
			std::cin >> playAgain;
			if (playAgain == "yes") {
				std::cout << "\nTry to break the code, guess the number:" << std::endl;
				guessCount = 0;
				*ref = 0;
				std::vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
				std::random_shuffle(vec.begin(), vec.end());
				vec.resize(4);

				for (auto i = vec.begin(); i != vec.end(); ++i) {
					*ref = 10 * *ref + (*i);
				}
			}
			else if (playAgain == "no") {
				std::cout << "\nThanks for playing. see you soon!!" << std::endl;
				std::cin.get();
			}

		}
		if (guessCount == guessLimit) {
			std::cout << "\nSorry your out of turns. The right number was:" << *ref << std::endl;
			std::cout << "try again you can do it!!(Yes or No)" << std::endl;
			std::cin >> playAgain;
			if (playAgain == "yes") {
				std::cout << "\nTry to break the code, guess the number:" << std::endl;
				guessCount = 0;
				*ref = 0;
				std::vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
				std::random_shuffle(vec.begin(), vec.end());
				vec.resize(4);

				for (auto i = vec.begin(); i != vec.end(); ++i) {
					*ref = 10 * *ref + (*i);
				}
			}
			else if (playAgain == "no") {
				std::cout << "\nThanks for playing. see you soon!!" << std::endl;
				std::cin.get();
			}
		}
	}
}