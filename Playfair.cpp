#include <stdio.h>
#include <string.h>
#include <ctype.h>
void prepareKey(char key[], char *preparedKey) {
    int keyLen = strlen(key);
    int index = 0;
    for (int i = 0; i < keyLen; i++) {
        if (isalpha(key[i])) {
            char letter = toupper(key[i]);
            if (strchr(preparedKey, letter) == NULL) {
                preparedKey[index++] = letter;
            }
        }
    }
    preparedKey[index] = '\0';
}

void generateMatrix(char preparedKey[], char matrix[5][5]) {
    int index = 0;
    char alphabet[26] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (index < strlen(preparedKey)) {
                matrix[i][j] = preparedKey[index++];
            } else {
                for (int k = 0; k < 26; k++) {
                    char letter = alphabet[k];
                    if (strchr(preparedKey, letter) == NULL) {
                        matrix[i][j] = letter;
                        alphabet[k] = '0'; 
                        break;
                    }
                }
            }
        }
    }
}

void printMatrix(char matrix[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char key[100], preparedKey[30];
    char matrix[5][5];

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    prepareKey(key, preparedKey);
    generateMatrix(preparedKey, matrix);

    printf("Playfair Matrix:\n");
    printMatrix(matrix);

    return 0;
}

