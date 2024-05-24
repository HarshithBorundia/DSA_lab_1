#include <stdio.h>
#include <gmp.h>

int main() {
    mpz_t N, M, passcode;

    // Initialize mpz_t variables
    mpz_init(N);
    mpz_init(M);
    mpz_init(passcode);
    char a[10000];
    char b[10000];
    scanf("%s",a);
    scanf("%s",b);
    // Set the values for N and M (replace these with your actual values)
    mpz_set_str(N, a, 10);
    mpz_set_str(M, b, 10);

    // Calculate the passcode using mpz_invert
    if (mpz_invert(passcode, N, M) == 0) {
        // Inversion failed (passcode does not exist)
        printf("Passcode does not exist.\n");
    } else {
        // Print or use the calculated passcode
        gmp_printf("Passcode: %Zd\n", passcode);
    }

    // Clear the allocated memory
    mpz_clear(N);
    mpz_clear(M);
    mpz_clear(passcode);

    return 0;
}

