#include <stdio.h>

int main() {
    int n, result, i;
    printf("Enter a number: ");
    scanf("%d", &n);
    result = n;

    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n = n / i;
            result = result - result / i;
        }
    }

    if (n > 1)
        result = result - result / n;
    printf("Euler's Totient Function value = %d\n", result);
    return 0;
}
