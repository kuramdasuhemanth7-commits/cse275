#include <stdio.h>
#include <limits.h>

void findTriplet(int arr[], int n) {
    int maxProduct = INT_MIN;
    int triplet[3] = {0};
    int found = 0;
    int i, j, k;
    
    for (i = 0; i < n - 2; i++) {
        for (j = i + 1; j < n - 1; j++) {
            for (k = j + 1; k < n; k++) {
                int product = arr[i] * arr[j] * arr[k];
                if (product > maxProduct) {
                    maxProduct = product;
                    triplet[0] = arr[i];
                    triplet[1] = arr[j];
                    triplet[2] = arr[k];
                    found = 1;
                }
            }
        }
    }
    
    if (found)
        printf("Triplet with max product: %d, %d, %d (Product: %d)\n", 
               triplet[0], triplet[1], triplet[2], maxProduct);
    else
        printf("No triplet found\n");
}

int main() {
    int arr[] = {1, 5, 7, -1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    findTriplet(arr, n);
    
    return 0;
}
