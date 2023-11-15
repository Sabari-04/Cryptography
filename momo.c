#include <stdio.h>
#include <ctype.h>
#include <string.h>
void monoalphabeticSubstitution(char *plaintext, char *ciphertext, char *message) {
    int i;
    for (i = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            char originalChar = tolower(message[i]);
            int index = originalChar - 'a';
            if (isupper(message[i])) {
                ciphertext[i] = toupper(plaintext[index]);
            } else {
                ciphertext[i] = plaintext[index];
            }
        } else {
            ciphertext[i] = message[i];
        }
    }
    ciphertext[i] = '\0';
}

int main() {
    char plaintextAlphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char substitutionAlphabet[] = "qwertyuiopasdfghjklzxcvbnm"; 

    char message[1000];
    char ciphertext[1000];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';  

    monoalphabeticSubstitution(substitutionAlphabet, ciphertext, message);

    printf("Plaintext: %s\n", message);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
