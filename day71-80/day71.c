/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/
#include <stdio.h>

#define MAX 100

int table[MAX];

// Initialize hash table
void init(int m) {
    for (int i = 0; i < m; i++) {
        table[i] = -1;  // -1 means empty
    }
}

// Hash function
int hash(int key, int m) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
    }

    printf("Hash table is full\n");
}

// Search using quadratic probing
int search(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == -1) {
            return 0; // NOT FOUND
        }

        if (table[idx] == key) {
            return 1; // FOUND
        }
    }

    return 0;
}

int main() {
    int m, q;
    char op[10];
    int key;

    // Input
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    init(m);

    while (q--) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I') { // INSERT
            insert(key, m);
        } else if (op[0] == 'S') { // SEARCH
            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}