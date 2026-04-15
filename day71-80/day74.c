/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n;
    scanf("%d", &n);

    char votes[n][MAX];
    
    // Input votes
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    char unique[n][MAX];
    int count[n];
    int size = 0;

    // Initialize counts
    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if already counted
        for (int j = 0; j < size; j++) {
            if (strcmp(unique[j], votes[i]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        // New candidate
        if (!found) {
            strcpy(unique[size], votes[i]);
            count[size] = 1;
            size++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[MAX];

    for (int i = 0; i < size; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        } 
        else if (count[i] == maxVotes) {
            // Lexicographically smaller
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}