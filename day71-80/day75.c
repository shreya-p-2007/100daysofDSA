/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray. code n dsa*/


#include <stdio.h>

#define MAX 1000

int maxLenZeroSum(int arr[], int n) {
    int sum = 0, max_len = 0;

    // Hash map using arrays (since constraints are small)
    // Initialize all values to -1
    int hash[2 * MAX + 1];
    for (int i = 0; i < 2 * MAX + 1; i++)
        hash[i] = -1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // If sum is zero, update max_len
        if (sum == 0) {
            max_len = i + 1;
        }

        // Offset index to handle negative sums
        int index = sum + MAX;

        // If sum seen before
        if (hash[index] != -1) {
            int len = i - hash[index];
            if (len > max_len)
                max_len = len;
        } else {
            // Store first occurrence
            hash[index] = i;
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLenZeroSum(arr, n));

    return 0;
}