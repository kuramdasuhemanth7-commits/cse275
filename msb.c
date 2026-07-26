#include <stdio.h>
#include <limits.h>

int maxSubarraySumBruteForce(int arr[], int n) {
    int maxSum = INT_MIN;
    int i, j, k;
    
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            int sum = 0;
            for (k = i; k <= j; k++) {
                sum += arr[k];
            }
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", maxSubarraySumBruteForce(arr, n));
    return 0;
}
