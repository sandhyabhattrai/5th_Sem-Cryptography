#include <stdio.h>
#include <string.h>

// Convert binary string to decimal
int binaryToDecimal(char key[]) {
    int i, value = 0;
    for (i = 0; key[i] != '\0'; i++) {
        value = value * 2 + (key[i] - '0');
    }
    return value;
}

// Simple Feistel round using XOR
void feistel(char text[], int key) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] ^ key;
    }
}

int main() {
    char text[100];
    char binKey[20];
    int key;

    printf("Enter plain text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter key in binary: ");
    scanf("%s", binKey);

    key = binaryToDecimal(binKey);

    feistel(text, key);
    printf("\nEncrypted text: %s", text);
    feistel(text, key);
    printf("\nDecrypted text: %s", text);

    return 0;
}
