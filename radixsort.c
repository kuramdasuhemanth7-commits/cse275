#include <stdio.h>
#include <string.h>

void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10];
    int i;
    
    memset(count, 0, sizeof(count));
    
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = arr[0];
    int i;
    
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int arr[] = {170, 45, 75, 90, 2, 99, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    radixSort(arr, n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
