
#include <stdio.h>
long long power(long long a, long long b, long long p) {
    long long result = 1;
    a = a % p;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % p;
        a = (a * a) % p;
        b = b / 2;
    }
    return result;
}

int main() {
    long long a, p;
    printf("Enter value of a: ");
    scanf("%lld", &a);
    printf("Enter prime number p: ");
    scanf("%lld", &p);
    if (power(a, p - 1, p) == 1)
        printf("Fermat's Little Theorem is satisfied.\n");
    else
        printf("Fermat's Little Theorem is NOT satisfied.\n");
    return 0;
}
