#include <stdio.h>
#include <string.h>

int main() {
    char msg[] = "WELCOME";
    unsigned char key = 0b10010001;
    int n = strlen(msg);
    int half = n / 2;

    char L[10], R[10], L1[10], R1[10];

    strncpy(L, msg, half);
    L[half] = '\0';
    strcpy(R, msg + half);

    for (int i = 0; i < half; i++) {
        L1[i] = R[i];
        R1[i] = L[i] ^ (R[i] ^ key);
    }

    L1[half] = '\0';
    R1[half] = '\0';

    char cipher[20];
    strcpy(cipher, L1);
    strcat(cipher, R1);

    printf("Plaintext: %s\n", msg);
    printf("Ciphertext: %s\n", cipher);

    return 0;
}
