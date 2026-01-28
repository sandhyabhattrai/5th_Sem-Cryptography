#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[100], key[50];
    int i, j = 0;
    printf("Enter plain text: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            int shift = tolower(key[j % strlen(key)]) - 'a';
            if (isupper(text[i]))
                text[i] = (text[i] - 'A' + shift) % 26 + 'A';
            else
                text[i] = (text[i] - 'a' + shift) % 26 + 'a';
            j++; 
        }
    }
    printf("Encrypted text: %s", text);
return 0;
}
