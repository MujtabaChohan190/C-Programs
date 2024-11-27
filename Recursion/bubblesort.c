// Write a recursive function bubbleSort that takes an array and its size. It performs the
// bubble sort algorithm by repeatedly comparing adjacent elements and swapping them if
// they are in the wrong order.

#include <stdio.h>
void bubblesort(int arr[], int len)
{
    int temp = 0;
    if (len == 1)
    {
        return;
    }
    for (int i = 0; i < len - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    bubblesort(arr, len - 1);
}
int main()
{
    int Arr[] = {2, 3, 4, 1, 7, 6};
    int len = sizeof(Arr) / sizeof(Arr[0]);
    bubblesort(Arr, len);

    printf("Sorted array : ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", Arr[i]);
    }
    return 0;
}
