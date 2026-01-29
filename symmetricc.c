#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void encrypt(char text[], int key)
{
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        else if(text[i] >= 'a' && text[i] <= 'z')
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
    }
}

void decrypt(char text[], int key)
{
    encrypt(text, 26 - key);
}

int main()
{
    char message[100];
    int maxkey, randomkey;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter maximum number for key: ");
    scanf("%d", &maxkey);

    srand(time(0));
    randomkey = (rand() % maxkey) % 26;

    printf("System selected key: %d\n", randomkey);

    encrypt(message, randomkey);
    printf("Encrypted text: %s\n", message);

    decrypt(message, randomkey);
    printf("Decrypted text: %s\n", message);

    return 0;
}
