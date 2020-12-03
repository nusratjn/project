#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*To truly have a random number, we use srand and seed the function with time (a number that changes every time).*/
#include <math.h>
int main(void)
{
	int totalscore=0, loop;
	char decide;

	srand(time(NULL));

	printf("*********************\n");
	printf("Welcome to Dice Game\n");
	printf("*********************\n");

	do{
	   printf("Input P to play the game, S to display the total score, Q to Quit: ");
	   scanf(" %c", &decide);
	   printf("\n");
	  }while(decide != 'Q' && decide != 'S' && decide != 'P' );


	//Assuring when 'Q' is entered, program will exit.
	while (decide != 'Q')
	{
		//Each time an instruction ends, reset of values is needed.
		  int  dienr = 0, scorep1 = 0, scorep2 = 0;
		  //Dices are initialized arbitrarily
		  int	die1 = 1, die2 = 2, die3 = 3, die4 = 4;
		//Assuring when 'P' is entered, game will start.
		if (decide == 'P')
		{
			//Assuring when player1 has twice the dice sum, game will end.
			while ((die1+die2) != (2 * (die3+die4)))
			{
				//Assigning true random values between 1 & 6 to simulate dice throw.
				die1 = (rand() % 6) + 1;
				die2 = (rand() % 6) + 1;
				dienr += 1;
				printf("Throw the dice for player1: %d %d\n", die1, die2);
				//(1)If thrown dices are 3-3 or 6-6
				if ((die1==3 && die2==3) || (die1 == 6 && die2 == 6))
				{
					//(1)Throw 3 times
					for (loop = 0; loop < 3; loop++)
					{
						die1 = (rand() % 6) + 1;
						die2 = (rand() % 6) + 1;
						//(1)And don't add points if same dice values occur
						if(die1 != die2)
							scorep1 += (die1 + die2) / 2;
						//DO count throw whether it brings point or not
						dienr += 1;
						printf("Throw the dice for player1: %d %d\n", die1, die2);
					}

				}
				//(2)If difference between dices is 4
				else if (abs(die1 - die2) == 4)
				{
					//(2)Throw again 'till their sum is greater than 8
					while ((die1 + die2) <= 8)
					{
						die1 = (rand() % 6) + 1;
						die2 = (rand() % 6) + 1;
						dienr += 1;
						printf("Throw the dice for player1: %d %d\n", die1, die2);
					}

					scorep1 += (die1 + die2) / 2;
				}
				//(3)If no special situation occurs..
				else
				{
			    	scorep1 += (die1 + die2) / 2;
				}

				//----------------SAME RULES APPLY FOR PLAYER2..--------------------//

				die3 = (rand() % 6) + 1;
				die4 = (rand() % 6) + 1;
				dienr += 1;
				printf("Throw the dice for player2: %d %d\n", die3, die4);
				//(1)If thrown dices are 3-3 or 6-6
				if ((die3 == 3 && die4 == 3) || (die3 == 6 && die4 == 6))
				{
					//(1)Throw 3 times
					for (loop = 0; loop < 3; loop++)
					{
						die3 = (rand() % 6) + 1;
						die4 = (rand() % 6) + 1;
						//(1)And don't add points if same dice values occur
						if (die3 != die4)
							scorep2 += (die3 + die4) / 2;
						//DO count throw whether it brings point or not
						dienr += 1;
						printf("Throw the dice for player2: %d %d\n", die3, die4);
					}

				}
				//(2)If difference between dices is 4
				else if (abs(die3 - die4) == 4)
				{
					//(2)Throw again 'till their sum is greater than 8
					while ((die3 + die4) <= 8)
					{
						die3 = (rand() % 6) + 1;
						die4 = (rand() % 6) + 1;
                        dienr += 1;
						printf("Throw the dice for player1: %d %d\n", die3, die4);
					}

					scorep2 += (die3 + die4) / 2;

				}
				//(3)If no special situation occurs..
				else
				{
					scorep2 += (die3 + die4) / 2;
				}

			}
			//Display points obtained.
			printf("Player 1: %d points\n", scorep1);
			printf("Player 2: %d points\n", scorep2);
			//Display throws performed.
			printf("Total of %d throws are performed.\n", dienr);
			//Display winner based on points obtained.
			if (scorep1 > scorep2)
				printf("Winner is: Player 1\n");
			else if (scorep2 > scorep1)
				printf("Winner is: Player 2\n");
			else
				printf("It is a tie\n");

			//Aim is to display total score with all previous games.
			totalscore += scorep1 + scorep2;

		}
		//Assuring when 'S' is entered, total score is displayed.
		else if (decide == 'S')
		{
	      printf("Total score is: %d\n", totalscore);
		}
		//Other than Do-While this is also a safeguard against user entering non-valid characters..
		printf("Input P to play the game, S to display the total score, Q to Quit: ");
		scanf(" %c", &decide);
	}

	printf("Bye!\n");

	return 0;
}
