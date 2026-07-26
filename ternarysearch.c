#include <stdio.h>

int ternarySearch(int arr[], int left, int right, int x) {
    if (right < left)
        return -1;
    
    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;
    
    if (arr[mid1] == x)
        return mid1;
    
    if (arr[mid2] == x)
        return mid2;
    
    if (x < arr[mid1])
        return ternarySearch(arr, left, mid1 - 1, x);
    
    if (x > arr[mid2])
        return ternarySearch(arr, mid2 + 1, right, x);
    
    return ternarySearch(arr, mid1 + 1, mid2 - 1, x);
}

int main() {
    int arr[] = {1, 5, 7, 10, 12, 15, 18, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 15;
    
    int result = ternarySearch(arr, 0, n - 1, x);
    
    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", result);
    
    return 0;
}
