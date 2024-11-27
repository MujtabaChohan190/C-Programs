// Write a recursive function that takes an array and its size as input and prints all the
// elements.

#include <stdio.h>

void printArray(int arr[], int size) { // we can also write *arr only to get the address of array . for eg address of arr[1] . we are receiving the address of array in parameters.

    if (size == 0) {
        return;
    }
    printf("%d ", arr[0]);  
    // Recursive call for the rest of the array
    printArray(arr + 1, size - 1); // arr + 1 moves the pointer to the next element, so in the first call, it refers to arr[1], in the second call it refers to arr[2]
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};  
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the number of elements or size of the array
    
    printf("Array elements: ");
    printArray(arr, size);
    
    return 0;
}
