#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[200];
    int key;\
    printf("Enter plain text: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter shift key: ");
    scanf("%d", &key);
    key = key % 26;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i])) {
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        }
        else if (islower(text[i])) {
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
        }
    }

    printf("\nEncoded text: %s", text);

    return 0;
}
