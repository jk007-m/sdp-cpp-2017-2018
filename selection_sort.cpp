#include <stdio.h>
#include <algorithm>

using namespace std;

void selectionSort(int* input, int inputSize)
{
    for (int numberOfSorted = 0; numberOfSorted < inputSize - 1; ++numberOfSorted)
    {
        int minIndex = numberOfSorted;
        for (int index = numberOfSorted + 1; index < inputSize; ++index)
            if (input[index] < input[minIndex])
                minIndex = index;
        swap(input[numberOfSorted], input[minIndex]);
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
    const int arrSize = 11;
    int arr[arrSize] = {3, -453, 0, 543, 342626, -2, 42, 8, 10, 9, 15};
    selectionSort(arr, arrSize);
    printArray(arr, arrSize);
	return 0;
}
