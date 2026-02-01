#include <stdio.h>

void generateMonomial(int coeff, int exp, int field)
{
    coeff = coeff % field;
    printf("Monomial: %dx^%d (mod %d)\n", coeff, exp, field);
}

void generateBinomial(int c1, int e1, int c2, int e2, int field)
{
    c1 = c1 % field;
    c2 = c2 % field;
    printf("Binomial: %dx^%d + %dx^%d (mod %d)\n", c1, e1, c2, e2, field);
}

void generateIdentical(int coeff, int exp, int field)
{
    coeff = coeff % field;
    printf("Identical Equation: %dx^%d = %dx^%d (mod %d)\n",
           coeff, exp, coeff, exp, field);
}

int main()
{
    int p = 997;
    int a = 1500, b = 450;
    int n = 2, m = 1;

    printf("--- Finite Field Equation Generator (GF(%d)) ---\n\n", p);

    generateIdentical(a, n, p);
    generateMonomial(a, n, p);
    generateBinomial(a, n, b, m, p);

    return 0;
}
