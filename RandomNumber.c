#include <stdio.h>
#include <stdlib.h> // Required for rand() and srand()
#include <time.h>	// Required for time()

int main()
{
	// Use the current time as the seed for the random number generator
	srand(time(0));

	// Generate a random number between 1 and 100
	int random_number = (rand() % 100) + 1;
	int no_of_guesses = 0;
	int guessed;

	// printf("Random number between 1 and 100: %d\n", random_number); we do not need this right now
	do
	{
		printf("Guess the Number: ");
		scanf("%d", &guessed);
		if (guessed > random_number)
		{
			printf("Lower Number please.\n");
		}
		else
		{
			printf("Higher Number Please.\n");
		}
		no_of_guesses++; // its equivlent to count = count + 1 or count +=1

	} while (guessed != random_number);
	printf("You guessed the number in %d guesses.\n", no_of_guesses);

	return 0;
}
