#include <stdio.h>
#include <algorithm>

using namespace std;

void bubbleSort(int* input, int inputSize)
{
    bool swapped = true;
    for (int iteration = 0; swapped && (iteration < inputSize - 1); ++iteration)
    {
        swapped = false;
        for (int index = 0; index < inputSize - 1 - iteration; ++index)
            if (input[index] > input[index + 1])
            {
                swap(input[index], input[index + 1]);
                swapped = true;
            }
    }
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
    const int arrSize = 5;
    int arr[arrSize] = {15, 0, 1, 2, 3};
    bubbleSort(arr, arrSize);
    printArray(arr, arrSize);
	return 0;
}
