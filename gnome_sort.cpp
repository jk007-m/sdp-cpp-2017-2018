#include <stdio.h>
#include <algorithm>

using namespace std;

void gnomeSort(int* input, int inputSize)
{
    int position = 0;
    while (position < inputSize)
    {
        if (position == 0 || input[position] >= input[position - 1]) ++position;
        else
        {
            swap(input[position], input[position - 1]);
            --position;
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
    const int arrSize = 11;
    int arr[arrSize] = {3, -453, 0, 543, 342626, -2, 42, 8, 10, 9, 15};
    gnomeSort(arr, arrSize);
    printArray(arr, arrSize);
	return 0;
}
