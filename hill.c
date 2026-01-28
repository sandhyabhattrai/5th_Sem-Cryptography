#include <stdio.h>
#include <string.h>

int key[2][2] = {
    {12, 0},   // M A
    {19, 7}    // T H
};

int main() {
    char text[] = "CALCULATOR";
    int i;
    
    printf("Plain Text : %s\n", text);
    printf("Cipher Text: ");

    for (i = 0; i < strlen(text); i += 2) {
        int p1 = text[i] - 'A';
        int p2 = text[i + 1] - 'A';

        int c1 = (key[0][0] * p1 + key[0][1] * p2) % 26;
        int c2 = (key[1][0] * p1 + key[1][1] * p2) % 26;

        printf("%c%c", c1 + 'A', c2 + 'A');
    }

    return 0;
}
