#include <stdio.h>
#include <string.h>

int main() {
    char plaintext[] = "Good Morning Cryptography";
    char ciphertext[100];
    int k = 19;
    int i;

    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        // For uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ciphertext[i] = ((ch - 'A' + k) % 26) + 'A';
        }
        // For lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ciphertext[i] = ((ch - 'a' + k) % 26) + 'a';
        }
        // For spaces and other characters
        else {
            ciphertext[i] = ch;
        }
    }

    ciphertext[i] = '\0';

    printf("Plain Text : %s\n", plaintext);
    printf("Key (k)    : %d\n", k);
    printf("Cipher Text: %s\n", ciphertext);

    return 0;
}
