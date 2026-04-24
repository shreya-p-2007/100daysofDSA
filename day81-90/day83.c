/*Problem: Implement Selection Sort - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64 */
#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;

        // Find the minimum element in unsorted part
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with first element
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int n, i;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    selectionSort(arr, n);

    // Print sorted array
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}