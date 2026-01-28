#include <stdio.h>
#include <string.h>

int main() {
    char text[] = "Greeting Cryptography";
    printf("Plain Text : %s\n", text);
    printf("Key (k)    : 3\n");
    int shift = 3;
    int i;

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
        }
    }
    
    printf("Encrypted text: %s", text);
    return 0;
}