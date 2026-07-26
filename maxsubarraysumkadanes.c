#include <stdio.h>
#include <limits.h>

int maxSubarraySumKadane(int arr[], int n) {
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];
    int i;
    
    for (i = 1; i < n; i++) {
        if (maxEndingHere < 0)
            maxEndingHere = arr[i];
        else
            maxEndingHere += arr[i];
        
        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
    }
    return maxSoFar;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", maxSubarraySumKadane(arr, n));
    return 0;
}
