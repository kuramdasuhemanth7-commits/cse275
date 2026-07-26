#include <stdio.h>
#include <limits.h>

int maxCrossingSum(int arr[], int l, int m, int r) {
    int sum = 0;
    int leftSum = INT_MIN;
    int i;
    
    for (i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }
    
    sum = 0;
    int rightSum = INT_MIN;
    for (i = m + 1; i <= r; i++) {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }
    
    return leftSum + rightSum;
}

int maxSubarraySum(int arr[], int l, int r) {
    if (l == r)
        return arr[l];
    
    int m = (l + r) / 2;
    int leftMax = maxSubarraySum(arr, l, m);
    int rightMax = maxSubarraySum(arr, m + 1, r);
    int crossMax = maxCrossingSum(arr, l, m, r);
    
    if (leftMax > rightMax && leftMax > crossMax)
        return leftMax;
    else if (rightMax > leftMax && rightMax > crossMax)
        return rightMax;
    else
        return crossMax;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", maxSubarraySum(arr, 0, n - 1));
    return 0;
}
