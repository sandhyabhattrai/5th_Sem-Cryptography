#include <stdio.h>
#include <string.h>

void railFence2(char text[], char cipher[]) {
    int i, k = 0;

    for (i = 0; text[i] != '\0'; i += 2)
        cipher[k++] = text[i];

    for (i = 1; text[i] != '\0'; i += 2)
        cipher[k++] = text[i];

    cipher[k] = '\0';
}

void railFence3(char text[], char cipher[]) {
    char r1[100] = "", r2[100] = "", r3[100] = "";
    int row = 0, down = 1, i;

    for (i = 0; text[i] != '\0'; i++) {
        if (row == 0)
            down = 1;
        else if (row == 2)
            down = 0;
        if (row == 0)
            strncat(r1, &text[i], 1);
        else if (row == 1)
            strncat(r2, &text[i], 1);
        else
            strncat(r3, &text[i], 1);

        row = down ? row + 1 : row - 1;
    }
    strcpy(cipher, r1);
    strcat(cipher, r2);
    strcat(cipher, r3);
}

int main() {
    char text[100];
    char out2[100], out3[100];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    railFence2(text, out2);
    railFence3(text, out3);

    printf("\n2-Layer Output: %s", out2);
    printf("\n3-Layer Output: %s", out3);

    if (strcmp(out2, out3) == 0)
        printf("\n\nResult: Same Output");
    else
        printf("\n\nResult: Different Output");
    return 0;
}
