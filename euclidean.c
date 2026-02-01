#include <stdio.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int x, y, result;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    result = gcd(x, y);

    printf("GCD is: %d\n", result);

    return 0;
}
