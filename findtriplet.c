#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void findTriplet(int arr[], int n) {
    if (n < 3) {
        printf("No triplet found\n");
        return;
    }
    
    int *sorted = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }
    
    qsort(sorted, n, sizeof(int), compare);
    
    long long maxProduct = LLONG_MIN;
    int triplet[3] = {0};
    int found = 0;
    
    long long prod1 = (long long)sorted[n-1] * sorted[n-2] * sorted[n-3];
    if (prod1 > maxProduct) {
        maxProduct = prod1;
        triplet[0] = sorted[n-3];
        triplet[1] = sorted[n-2];
        triplet[2] = sorted[n-1];
        found = 1;
    }
    
    long long prod2 = (long long)sorted[0] * sorted[1] * sorted[n-1];
    if (prod2 > maxProduct) {
        maxProduct = prod2;
        triplet[0] = sorted[0];
        triplet[1] = sorted[1];
        triplet[2] = sorted[n-1];
        found = 1;
    }
    
    long long prod3 = (long long)sorted[0] * sorted[1] * sorted[2];
    if (prod3 > maxProduct) {
        maxProduct = prod3;
        triplet[0] = sorted[0];
        triplet[1] = sorted[1];
        triplet[2] = sorted[2];
        found = 1;
    }
    
    if (found)
        printf("Triplet with max product: %d, %d, %d (Product: %lld)\n", 
               triplet[0], triplet[1], triplet[2], maxProduct);
    else
        printf("No triplet found\n");
    
    free(sorted);
}

int main() {
    int arr[] = {1, 5, 7, -1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    findTriplet(arr, n);
    
    printf("\nTest case 2: ");
    int arr2[] = {-10, -3, -2, 1, 5, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    findTriplet(arr2, n2);
    
    printf("\nTest case 3: ");
    int arr3[] = {-100, -50, -40, -30, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    findTriplet(arr3, n3);
    
    return 0;
}
