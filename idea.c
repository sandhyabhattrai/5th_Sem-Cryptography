#include <stdio.h>
#include <stdint.h>
#define MOD_ADD 65536
#define MOD_MUL 65537

uint16_t mul(uint16_t a, uint16_t b)
{
    uint32_t x, y, result;
    x = (a == 0) ? 65536 : a;
    y = (b == 0) ? 65536 : b;
    result = (x * y) % MOD_MUL;
    if (result == 65536)
        return 0;
    else
        return (uint16_t)result;
}

int main()
{
    uint16_t X1, X2, X3, X4;
    uint16_t K1, K2, K3, K4, K5, K6;
    uint16_t A, B, C, D, E, F;

    printf("Enter X1 X2 X3 X4: ");
    scanf("%hu %hu %hu %hu", &X1, &X2, &X3, &X4);
    printf("Enter K1 K2 K3 K4 K5 K6: ");
    scanf("%hu %hu %hu %hu %hu %hu", &K1, &K2, &K3, &K4, &K5, &K6);

    A = mul(X1, K1);
    B = (X2 + K2) % MOD_ADD;
    C = (X3 + K3) % MOD_ADD;
    D = mul(X4, K4);

    E = A ^ C;
    F = B ^ D;
    E = mul(E, K5);
    F = (F + E) % MOD_ADD;
    F = mul(F, K6);
    E = (E + F) % MOD_ADD;

    X1 = A ^ F;
    X2 = C ^ F;
    X3 = B ^ E;
    X4 = D ^ E;

    printf("\nOutput after one IDEA round:\n");
    printf("%hu %hu %hu %hu\n", X1, X2, X3, X4);
    return 0;
}
