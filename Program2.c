#include <stdio.h>

//Function used to find all the possible combination of scoring plays.
void possible_combination(int total, int scoringPlays[], int playSize, int play, int runningTotal, int counts[])
{
    if (runningTotal == total) {
        //Prints the current count of each scoring play by looping through the array.
        for (int i = 0; i < playSize; i++) {
            if (i == 0) {
                printf("%d TD + 2pt, ", counts[i]);
            }
            else if (i == 1) {
                printf("%d TD + FG, ", counts[i]);
            }
            else if (i == 2) {
                printf("%d TD, ", counts[i]);
            }
            else if (i == 3) {
                printf("%d 3pt FG, ", counts[i]);
            }
            else if (i == 4) {
                printf("%d Safety", counts[i]);
            }
        }
        printf("\n");
    }
    else if (runningTotal < total) {
        //Tries to add a play to the combination. Also includes the recursion required.
        for (int i = play; i < playSize; i++) {
            counts[i]++;
            possible_combination(total, scoringPlays, playSize, i, runningTotal + scoringPlays[i], counts);
            counts[i]--;
        }
    }
}

//Main function of the program.
int main()
{
    //All variable initializations.
	int loop, total, scoringPlays[] = {8, 7, 6, 3, 2}, playSize = 5, counts[] = {0, 0, 0, 0, 0};

	//First check for the loop.
	printf("Enter 0 or 1 to STOP ");
    scanf("%d", &loop);

    while (loop > 1) {

    	//Collects score total and calls the possible combination function.
    	printf("Enter the NFL score: ");
        scanf("%d", &total);
        printf("\npossible combinations of scoring plays:\n");
        possible_combination(total, scoringPlays, playSize, 0, 0, counts);

        //Looped attempt to break out if wanted.
        printf("Enter 0 or 1 to STOP ");
        scanf("%d", &loop);
    }
    return 0;
}
