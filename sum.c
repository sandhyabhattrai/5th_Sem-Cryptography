#include <stdio.h>

int addTwoNumbers(int x, int y)
{
    return x + y;
}

int sumArray(int arr[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }
    return total;
}

int main()
{
    int a = 5, b = 10;
    int simpleSum = addTwoNumbers(a, b);

    printf("=== Part 1: Simple Addition ===\n");
    printf("Fixed sum (%d + %d) = %d\n\n", a, b, simpleSum);

    int numbers[10];
    printf("=== Part 2: Extended Field (10 Numbers) ===\n");
    printf("Enter 10 integers separated by spaces: ");

    for (int i = 0; i < 10; i++)
        scanf("%d", &numbers[i]);

    int extendedSum = sumArray(numbers, 10);

    printf("Values entered: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", numbers[i]);

    printf("\nTotal sum: %d\n", extendedSum);
    return 0;
}
