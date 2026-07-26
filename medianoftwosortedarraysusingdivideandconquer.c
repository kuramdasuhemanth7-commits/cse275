#include <stdio.h>
#include <limits.h>

double findMedianSortedArrays(int arr1[], int n1, int arr2[], int n2) {
    int i = 0, j = 0;
    int count = 0;
    int m1 = -1, m2 = -1;
    int n = n1 + n2;
    
    while (count < n / 2) {
        if (i < n1 && j < n2) {
            if (arr1[i] <= arr2[j]) {
                m2 = m1;
                m1 = arr1[i];
                i++;
            } else {
                m2 = m1;
                m1 = arr2[j];
                j++;
            }
        } else if (i < n1) {
            m2 = m1;
            m1 = arr1[i];
            i++;
        } else {
            m2 = m1;
            m1 = arr2[j];
            j++;
        }
        count++;
    }
    
    if (n % 2 == 1) {
        if (i < n1 && j < n2) {
            if (arr1[i] <= arr2[j])
                return arr1[i];
            else
                return arr2[j];
        } else if (i < n1)
            return arr1[i];
        else
            return arr2[j];
    } else {
        if (i < n1 && j < n2) {
            return (m1 + (arr1[i] <= arr2[j] ? arr1[i] : arr2[j])) / 2.0;
        } else if (i < n1) {
            return (m1 + arr1[i]) / 2.0;
        } else {
            return (m1 + arr2[j]) / 2.0;
        }
    }
}

int main() {
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    printf("%.1f\n", findMedianSortedArrays(arr1, 3, arr2, 3));
    return 0;
}
