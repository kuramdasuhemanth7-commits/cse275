#include <stdio.h>

void findTriplet(int arr[], int n, int sum) {
    int found = 0;
    int i, j, k;
    
    for (i = 0; i < n - 2; i++) {
        for (j = i + 1; j < n - 1; j++) {
            for (k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == sum) {
                    printf("Triplet found: %d, %d, %d\n", arr[i], arr[j], arr[k]);
                    found = 1;
                }
            }
        }
    }
    
    if (!found)
        printf("No triplet found\n");
}

int main() {
    int arr[] = {1, 5, 7, -1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 11;
    
    findTriplet(arr, n, sum);
    
    return 0;
}
