#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 9
int arr_1[ARRAY_SIZE] = {97,16,45,63,13,22,7,58,72};
int arr_2[ARRAY_SIZE] = {90,80,70,60,50,40,30,20,10};
int arr_3[ARRAY_SIZE] = {97,16,45,63,13,22,7,58,72};
int arr_4[ARRAY_SIZE] = {90,80,70,60,50,40,30,20,10};
int sortBubble(int arr[], int num_elem);
int sortSelection(int arr[], int num_elem);
void printarr(int arr[], int numE);
int main()
{
    int bubbleNum1;
    int bubbleNum2;
    int totSwaps;
    // printarr(arr_1, ARRAY_SIZE);
    // printarr(arr_2, ARRAY_SIZE);
    bubbleNum1 = sortBubble(arr_1, ARRAY_SIZE);
    bubbleNum2 = sortBubble(arr_2, ARRAY_SIZE);
    printf("%d: # of times %d is swapped\n", bubbleNum1, bubbleNum1);
    printf("%d: # of times %d is swapped\n", bubbleNum2, bubbleNum2);
    // printarr(arr_1, ARRAY_SIZE);
    // printarr(arr_2, ARRAY_SIZE);
    // printf("\n\n");
    // printarr(arr_3, ARRAY_SIZE);
    // printarr(arr_4, ARRAY_SIZE);
    totSwaps = bubbleNum1 + bubbleNum2;
    printf("Total Number of Swaps: %d\n", totSwaps);
    bubbleNum1 = sortSelection(arr_3, ARRAY_SIZE);
    bubbleNum2 = sortSelection(arr_4, ARRAY_SIZE);
    printf("%d: # of times %d is swapped\n", bubbleNum1, bubbleNum1);
    printf("%d: # of times %d is swapped\n", bubbleNum2, bubbleNum2);
    totSwaps = bubbleNum1 + bubbleNum2;
    printf("Total Number of Swaps: %d\n", totSwaps);
    // printarr(arr_3, ARRAY_SIZE);
    // printarr(arr_4, ARRAY_SIZE);
}
int sortBubble(int arr[], int num_elem)
{
    int sTmp = 0;
    int swaps = 0;
    for(int k = 0; k< num_elem-1; k++)
    {
        for(int j = k + 1; j< num_elem; j++)
        {
            if(arr[j]<arr[k])
            {
                swaps++;
                sTmp = arr[j];
                arr[j] = arr[k];
                arr[k] = sTmp;
            }
        }
    }
    return swaps;
}
int sortSelection(int arr[], int num_elem)
{
    int minIdx = 0;
    int swaps = 0;
    int sTmp = 0;
    for(int i = 0; i< num_elem-1; i++)
    {
        minIdx = i;
        for(int j = i +1; j< num_elem; j++)
        {
            if(arr[j]< arr[minIdx])
                minIdx = j;
            if(minIdx != i)
            {
                swaps++;
                sTmp = arr[minIdx];
                arr[minIdx] = arr[i];
                arr[i] = sTmp;
            }
        }
    }
    return swaps;
}
void printarr(int arr[],int numE)
{
    printf("[");
    for(int i = 0; i< numE; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("]\n");
}