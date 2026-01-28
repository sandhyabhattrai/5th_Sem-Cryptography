#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5] = {
    {'C','R','Y','P','T'},
    {'O','A','B','D','E'},
    {'F','G','H','I','K'},
    {'L','M','N','Q','S'},
    {'U','V','W','X','Z'}
};

void findPosition(char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
            }
}

int main() {
    char text[] = "WELCOMETONEPAL";
    int r1, c1, r2, c2;

    printf("Plain Text : %s\n", text);
    printf("Cipher Text: ");

    for (int i = 0; i < strlen(text); i += 2) {
        findPosition(text[i], &r1, &c1);
        findPosition(text[i + 1], &r2, &c2);

        if (r1 == r2) {
            printf("%c%c", matrix[r1][(c1 + 1) % 5],
                            matrix[r2][(c2 + 1) % 5]);
        }
        else if (c1 == c2) {
            printf("%c%c", matrix[(r1 + 1) % 5][c1],
                            matrix[(r2 + 1) % 5][c2]);
        }
        else {
            printf("%c%c", matrix[r1][c2],
                            matrix[r2][c1]);
        }
    }

    return 0;
}
