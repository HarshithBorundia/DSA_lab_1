#include <stdio.h>
#include <gmp.h>

int main() {
    mpz_t num1, num2, result;
    mpz_init(num1);
    mpz_init(num2);
    mpz_init(result);
    char a[1000];
    char b[1000];
    scanf("%s", a);
    scanf("%s", b);
    mpz_set_str(num1, a, 10);
    mpz_set_str(num2, b, 10);
    mpz_mul(result, num1, num2);

    // Now you can print the result or use it as needed
    gmp_printf("Result: %Zd\n", result);

    // Clear the allocated memory
    mpz_clear(num1);
    mpz_clear(num2);
    mpz_clear(result);

    return 0;
}

