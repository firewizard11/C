#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));	

	int max = 100;
	int target = rand() % max;
	int guess;
	int score = 0;	

	printf("Number Guessing Game\n");

	while (1) {
		printf("Enter a Guess (0-%d): ", max);
		scanf("%d", &guess);
		
		score++;

		if (guess == target) {
			printf("YOU WIN!!!!\nAttempts: %d\n", score);
			break;
		} else if (guess > target) {
			printf("The target is lower\n");
		} else if (guess < target) {
			printf("The target is higher\n");
		}
	}

	return 0;
}
