#include <stdio.h>
#include <string.h>

void encrypt(char text[], int key)
{
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        }
        else if(text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
        }
    }
}

void decrypt(char text[], int key)
{
    encrypt(text, 26 - key);
}

int main()
{
    char message[100];
    int key;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key (0-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted text: %s\n", message);

    decrypt(message, key);
    printf("Decrypted text: %s\n", message);

    return 0;
}
