#include <stdio.h>
#include <string.h>
void railFenceEncrypt(char plaintext[], int rails) {
    int len = strlen(plaintext);
    char encryptedText[len];
    int index = 0;

    for (int i = 0; i < rails; i++) {
        int j = i;
        int step = (i == 0 || i == rails - 1) ? (rails - 1) * 2 : i * 2;
        int alternate = 1;

        while (j < len) {
            encryptedText[index++] = plaintext[j];
            if (step == 0)
                step = (rails - 1) * 2;

            j += alternate ? step : (rails - 1 - i) * 2;
            alternate = !alternate;
        }
    }

    encryptedText[index] = '\0';
    printf("Encrypted Text: %s\n", encryptedText);
}
void railFenceDecrypt(char ciphertext[], int rails) {
    int len = strlen(ciphertext);
    char decryptedText[len];
    int index = 0;

    for (int i = 0; i < rails; i++) {
        int j = i;
        int step = (i == 0 || i == rails - 1) ? (rails - 1) * 2 : i * 2;
        int alternate = 1;

        while (j < len) {
            decryptedText[j] = ciphertext[index++];
            if (step == 0)
                step = (rails - 1) * 2;

            j += alternate ? step : (rails - 1 - i) * 2;
            alternate = !alternate;
        }
    }

    decryptedText[index] = '\0';
    printf("Decrypted Text: %s\n", decryptedText);
}

int main() {
    char text[1000];
    int rails;

    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter the number of rails: ");
    scanf("%d", &rails);
    strtok(text, "\n");

    railFenceEncrypt(text, rails);
    railFenceDecrypt(text, rails);

    return 0;
}
