#include <stdio.h>
#include <algorithm>

using namespace std;

void bubbleSort(int* input, int inputSize)
{
    for (int iteration = 0; iteration < inputSize - 1; ++iteration)
        for (int index = 0; index < inputSize - 1 - iteration; ++index)
            if (input[index] > input[index + 1])
                swap(input[index], input[index + 1]);
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
    int arr[arrSize] = {3, -453, 0, 543, 342626, -2, 42, 8, 10, 9, 15};
    bubbleSort(arr, arrSize);
    printArray(arr, arrSize);
	return 0;
}
