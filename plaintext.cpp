#include <stdio.h>
#include <string.h>

// Function to prepare the key for the Playfair cipher
void prepareKey(char key[], char keyMatrix[5][5]) {
    int i, j, k, flag = 0;
    int len = strlen(key);
    int uniqueChars[26] = {0}; // Initialize an array to check for unique characters

    // Initialize the matrix with zeros
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            keyMatrix[i][j] = 0;
        }
    }

    i = 0;
    j = 0;

    // Fill the matrix with the unique characters from the key
    for (k = 0; k < len; k++) {
        if (uniqueChars[key[k] - 'A'] == 0) {
            keyMatrix[i][j] = key[k];
            uniqueChars[key[k] - 'A'] = 1;
            j++;
            if (j == 5) {
                j = 0;
                i++;
            }
        }
    }

    // Fill the remaining matrix cells with unused characters (skipping 'J')
    for (k = 0; k < 26; k++) {
        if (uniqueChars[k] == 0) {
            keyMatrix[i][j] = 'A' + k;
            j++;
            if (j == 5) {
                j = 0;
                i++;
            }
        }
    }
}

// Function to find the positions of two letters in the key matrix
void findPosition(char keyMatrix[5][5], char ch, int *row, int *col) {
    if (ch == 'J') // 'J' and 'I' are treated the same in Playfair
        ch = 'I';

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (keyMatrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt a pair of letters using Playfair
void encryptPair(char keyMatrix[5][5], char a, char b) {
    int row1, col1, row2, col2;
    findPosition(keyMatrix, a, &row1, &col1);
    findPosition(keyMatrix, b, &row2, &col2);

    if (row1 == row2) {
        col1 = (col1 + 1) % 5;
        col2 = (col2 + 1) % 5;
    } else if (col1 == col2) {
        row1 = (row1 + 1) % 5;
        row2 = (row2 + 1) % 5;
    } else {
        int temp = col1;
        col1 = col2;
        col2 = temp;
    }

    printf("%c%c", keyMatrix[row1][col1], keyMatrix[row2][col2]);
}

int main() {
    char key[25], plaintext[100], keyMatrix[5][5];

    // Input the key and plaintext
    printf("Enter the key (uppercase letters, no spaces or duplicates): ");
    scanf("%s", key);
    printf("Enter the plaintext (uppercase letters): ");
    scanf("%s", plaintext);

    prepareKey(key, keyMatrix);

    printf("Ciphertext: ");
    int len = strlen(plaintext);
    for (int i = 0; i < len; i += 2) {
        char a = plaintext[i];
        char b = (i + 1 < len) ? plaintext[i + 1] : 'X'; // Pad with 'X' if necessary
        encryptPair(keyMatrix, a, b);
    }

    printf("\n");

    return 0;
}

