#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 12
#define MAX_LEN 1000

//Function that finds the six month average that takes in the start and the end months and iterates through the values finding the average.
void SixMonthAvg(float vals[12], char *months[12], int start, int end){
	float sixAvg = 0;
	for (int i = start; i <= end; i++){
		sixAvg = sixAvg + vals[i];
	}
	sixAvg = sixAvg / 6;
	printf("%s - %s $%.2f\n", months[start], months[end], sixAvg);
}

//Function used to order the months in highest to lowest order.
void bubble_sort(float arr[], int size, char *months[]) {
    float ogArr[12];
    for (int i = 0; i < size; i++){
    	ogArr[i] = arr[i];
    }

    //Nested for loop that creates a new ordered array.
	float temp;
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    int monthInd = 0;
    printf("\nSales Report (Highest to Lowest):\n\nMonth Sales\n");
    for (int i = 11; i >= 0; i--){
    	for (int j = 0; j < size; j++){
    		if (arr[i] == ogArr[j]){
    			monthInd = j;
    			break;
    		}
    	}
    	printf("%s $%.2f\n", months[monthInd], arr[i]);
    }
}

//Main function to call.
int main(void)
{
    //Opens the input file and puts the lines into a string array.
	char data[MAX_LINES][MAX_LEN];
    FILE *file;
    file = fopen("sampleinput.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    int line = 0;
    while (!feof(file) && !ferror(file))
        if (fgets(data[line], MAX_LEN, file) != NULL)
            line++;
    fclose(file);

    //Converts the string array into a float array for future functions.
    int size = sizeof(data) / sizeof(data[0]);
    float float_array[size];

    for (int i = 0; i < size; i++) {
    	float_array[i] = atof(data[i]);
    }

    //An array of months to easily print out results.
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    //Monthly report of in order of month.
    printf("Monthly sales report for 2022:\n\n");
    printf("Month Sales\n");
    printf("%s $%.2f\n", months[0], float_array[0]);
    printf("%s $%.2f\n", months[1], float_array[1]);
    printf("%s $%.2f\n", months[2], float_array[2]);
    printf("%s $%.2f\n", months[3], float_array[3]);
    printf("%s $%.2f\n", months[4], float_array[4]);
    printf("%s $%.2f\n", months[5], float_array[5]);
    printf("%s $%.2f\n", months[6], float_array[6]);
    printf("%s $%.2f\n", months[7], float_array[7]);
    printf("%s $%.2f\n", months[8], float_array[8]);
    printf("%s $%.2f\n", months[9], float_array[9]);
    printf("%s $%.2f\n", months[10], float_array[10]);
    printf("%s $%.2f\n\n", months[11], float_array[11]);

    printf("Sales summary:\n\n");

    //Finds the month with the least amount of sales by looping and storing the lowest value.
    int monthInd = 0;

    float minVal = float_array[0];
    for (int i = 0; i < size; i++){
    	if (float_array[i] < minVal){
    		minVal = float_array[i];
    		monthInd = i;
    	}
    }
    printf("Minimum sales: $%.2f (%s)\n", minVal, months[monthInd]);

    //The same as the minimum sales but max sales.
    float maxVal = float_array[0];
    for (int i = 0; i < size; i++){
    	if (float_array[i] > maxVal){
    		maxVal = float_array[i];
    		monthInd = i;
    	}
    }
    printf("Maximum sales: $%.2f (%s)\n", maxVal, months[monthInd]);

    //Finds the average sales by looping, adding, then dividing by 12.
    float avgSales = 0;
    for (int i = 0; i < size; i++){
    	avgSales = avgSales + float_array[i];
    }
    avgSales = avgSales / 12;
    printf("Average Sales: $%.2f\n\n", avgSales);

    //Calls the six month average function for each instance.
    printf("Six-Month Moving Average Report:\n\n");
    SixMonthAvg(float_array, months, 0, 5);
    SixMonthAvg(float_array, months, 1, 6);
    SixMonthAvg(float_array, months, 2, 7);
    SixMonthAvg(float_array, months, 3, 8);
    SixMonthAvg(float_array, months, 4, 9);
    SixMonthAvg(float_array, months, 5, 10);
    SixMonthAvg(float_array, months, 6, 11);

    //Organizes the months by highest to lowest grossing.
    bubble_sort(float_array, size, months);
}
