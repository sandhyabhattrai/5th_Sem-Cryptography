#include <stdio.h>

int main() {
    char plaintext[] = "A QUICK BROWN FOX JUMPS OVER A LAZY DOG";
    char plainKey[]  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cipherKey[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char cipherText[100];
    int i, j;

    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            for (j = 0; j < 26; j++) {
                if (plaintext[i] == plainKey[j]) {
                    cipherText[i] = cipherKey[j];
                    break;
                }
            }
        } else {
            cipherText[i] = plaintext[i]; // space
        }
    }
    cipherText[i] = '\0';

    printf("Plain Text : %s\n", plaintext);
    printf("Plain Key : %s\n", plainKey);
    printf("Cipher Key : %s\n", cipherKey);
    printf("Cipher Text : %s\n", cipherText);

    return 0;
}
