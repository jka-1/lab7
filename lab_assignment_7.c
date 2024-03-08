#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 9
int arr1[ARRAY_SIZE] = {97,16,45,63,13,22,7,58,72};
int arr2[ARRAY_SIZE] = {90,80,70,60,50,40,30,20,10};
int arr_1[ARRAY_SIZE] = {97,16,45,63,13,22,7,58,72};
int arr_2[ARRAY_SIZE] = {90,80,70,60,50,40,30,20,10};
int arr_3[ARRAY_SIZE] = {97,16,45,63,13,22,7,58,72};
int arr_4[ARRAY_SIZE] = {90,80,70,60,50,40,30,20,10};
int arr_bub1[ARRAY_SIZE];
int arr_bub2[ARRAY_SIZE];
int arr_sel1[ARRAY_SIZE];
int arr_sel2[ARRAY_SIZE];
int sortBubble(int arr[], int bub[], int num_elem);
int sortSelection(int arr[], int sel[], int num_elem);
void printarr(int arr[], int numE);
void printspc(int og[], int countarr[] , int numE);
int main()
{
    int bubbleNum1, bubbleNum2, bubbleNum3, bubbleNum4;
    int totSwaps1, totSwaps2;
    bubbleNum1 = sortBubble(arr_1, arr_bub1, ARRAY_SIZE);
    bubbleNum2 = sortBubble(arr_2, arr_bub2, ARRAY_SIZE);
    printf("%d: # of times %d is swapped\n", bubbleNum1, bubbleNum1);
    printf("%d: # of times %d is swapped\n", bubbleNum2, bubbleNum2);
    bubbleNum3 = sortSelection(arr_3, arr_sel1, ARRAY_SIZE);
    bubbleNum4 = sortSelection(arr_4, arr_sel2, ARRAY_SIZE);
    printf("%d: # of times %d is swapped\n", bubbleNum3, bubbleNum3);
    printf("%d: # of times %d is swapped\n", bubbleNum4, bubbleNum4);
    totSwaps1 = bubbleNum1 + bubbleNum3;
    totSwaps2 = bubbleNum2 + bubbleNum4;
    printspc(arr1, arr_bub1, ARRAY_SIZE);
    printspc(arr1, arr_bub2, ARRAY_SIZE);
    printspc(arr1, arr_sel1, ARRAY_SIZE);
    printspc(arr1, arr_sel2, ARRAY_SIZE);
    printf("Total Number of Swaps(bubble sort): %d\n", totSwaps1);
    printf("Total Number of Swaps(selection sort): %d\n", totSwaps2);
}
int sortBubble(int arr[], int bub[], int num_elem)
{
    int sTmp = 0;
    int swaps = 0;
    for(int k = 0; k< num_elem-1; k++)
    {
        for(int j = k + 1; j< num_elem; j++)
        {
            if(arr[j]<arr[k])
            {
                bub[j] += 1;
                sTmp = arr[j];
                arr[j] = arr[k];
                arr[k] = sTmp;
                swaps++;
            }
        }
    }
    return swaps;
}
int sortSelection(int arr[], int sel[], int num_elem)
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
                sel[i] += num_elem - minIdx;
                sTmp = arr[minIdx];
                arr[minIdx] = arr[i];
                arr[i] = sTmp;
                swaps++;
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
void printspc(int og[], int countarr[] , int numE)
{
    printf("\n\n");
    for(int i =0; i< numE; i++)
    {
        printf("%d: # of times %d is swapped\n", countarr[i], og[i]);
    }
    printf("\n\n");
}
