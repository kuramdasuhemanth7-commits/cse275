#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_VALUE 1000

void countingSort(int arr[], int n, int maxVal) {
    int count[MAX_VALUE + 1] = {0};
    int output[MAX_ELEMENTS];
    
   
    
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    

    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }
    
    
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
  
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[MAX_ELEMENTS];
    int n, maxVal;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX_ELEMENTS) {
        printf("Invalid number of elements!\n");
        return 1;
    }
    
    printf("Enter the maximum value in array: ");
    scanf("%d", &maxVal);
    
    if (maxVal <= 0 || maxVal > MAX_VALUE) {
        printf("Invalid maximum value!\n");
        return 1;
    }
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    countingSort(arr, n, maxVal);
    
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}