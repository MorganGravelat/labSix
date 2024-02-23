#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) {
    if (high >= low) { //If the count of high value is currently greater than or equal to the lower value keep going until it is either found or not there
        int mid = low + (high - low) / 2; //Taking the middle value of the number array

        // If the element is in the middle already
        if (numbers[mid] == value) return mid;

        // Since the numbers are already assorted if the value is less than the numbers midway through you only search left
        if (numbers[mid] > value) return search(numbers, low, mid - 1, value);

        // Sasme concept as above but only search the right since it is higher.
        return search(numbers, mid + 1, high, value);
    }

    // The value was not found
    return -1;
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}
