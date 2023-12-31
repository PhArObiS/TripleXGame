
#include <iostream>
#include <ctime>


// Function prototypes
void PrintIntroduction(int Difficulty) 
{
	// Print welcome messages to the terminal
	std::cout << "You are a secret agent breaking into a level " << Difficulty;
	std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

// Play game function
bool PlayGame(int Difficulty) 
{
	PrintIntroduction(Difficulty);

	// Declare 3 number code
	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	// Calculate sum and product
	const int CodeSum{ CodeA + CodeB + CodeC };
	const int CodeProduct{ CodeA * CodeB * CodeC };

	// Print sum and product to the terminal
	std::cout << std::endl;
	std::cout << "+ There are 3 numbers in the code" << std::endl;
	std::cout << "+ The codes add-up to: " << CodeSum << std::endl;
	std::cout << "+ The codes multiply to give: " << CodeProduct << std::endl;

	// Store player guess	
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;

	// Store player guess sum and product
	int GuessSum{ GuessA + GuessB + GuessC };
	int GuessProduct{ GuessA * GuessB * GuessC };

	// Check if the player's guess is correct
	if (GuessSum == CodeSum && GuessProduct == CodeProduct) 
	{
		std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***" << std::endl;
		return true;
	}
	else 
	{
		std::cout << "You entered the wrong code! Careful agent! Try again! ***orry" << std::endl;
		return false;
	}

}

 
int main() 
{ 
	srand(time(NULL)); // Create new random sequence based on time of day

	int LevelDifficulty{ 1 };
	int const MaxDifficulty{ 5 };


	// Loop the game until all levels are completed
	while (LevelDifficulty <= MaxDifficulty) 
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); // Clears any errors
		std::cin.ignore(); // Discards the buffer

		if (bLevelComplete) 
		{
			++LevelDifficulty;
		}
	
	}

	
	std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\m";
	return 0;

}
