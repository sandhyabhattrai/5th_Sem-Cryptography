#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int rails, len, i, j;

    printf("Enter the plain text: ");
    fgets(text, sizeof(text), stdin);


    printf("Enter number of rails: ");
    scanf("%d", &rails);

    len = strlen(text);

    printf("Encrypted text: ");

    for (i = 0; i < rails; i++) {
        j = i;
        int down = 1;

        while (j < len) {
            printf("%c", text[j]);

            if (i == 0 || i == rails - 1)
                j += 2 * (rails - 1);
            else {
                if (down) {
                    j += 2 * (rails - i - 1);
                    down = 0;
                } else {
                    j += 2 * i;
                    down = 1;
                }
            }
        }
    }

    return 0;
}
