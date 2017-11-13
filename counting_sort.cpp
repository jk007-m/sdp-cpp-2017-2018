#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxPossibleElement = 9;

void countingSort(int* input, int inputSize) /// For non-negative integers.
{
    int elementCount[maxPossibleElement + 1] = {};
    for (int index = 0; index < inputSize; ++index)
        ++elementCount[input[index]];
    int position = 0;
    for (int index = 0; index <= maxPossibleElement; ++index)
        while (elementCount[index]--)
            input[position++] = index;
}

void printArray(int* input, int inputSize)
{
    if (inputSize > 0) printf("%d", input[0]);
    for (int index = 1; index < inputSize; ++index)
        printf(" %d", input[index]);
    printf("\n");
}

int main()
{
    const int arrSize = 11;
    int arr[arrSize] = {3, 8, 0, 9, 4, 2, 4, 8, 0, 9, 7};
    countingSort(arr, arrSize);
    printArray(arr, arrSize);
	return 0;
}

