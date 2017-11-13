#include <stdio.h>
#include <algorithm>

using namespace std;

void insertionSort(int* input, int inputSize)
{
    for (int index = 1; index < inputSize; ++index)
    {
        int value = input[index];
        int position = index - 1;
        while (position >= 0 && input[position] > value)
        {
            input[position + 1] = input[position];
            --position;
        }
        input[position + 1] = value;
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
    insertionSort(arr, arrSize);
    printArray(arr, arrSize);
	return 0;
}
