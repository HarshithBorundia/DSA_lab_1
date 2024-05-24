#include <stdio.h>
#include <gmp.h>

// Function to count the number of set bits (1s) in the binary representation of a number
int countSetBits(mpz_t num) {
    int count = 0;

    while (mpz_cmp_ui(num, 0) > 0) {
        if (mpz_tstbit(num, 0)) {
            count++;
        }
        mpz_fdiv_q_2exp(num, num, 1); // Right shift by 1
    }

    return count;
}

int main() {
    mpz_t number;
    mpz_init(number);

    // Input the number
    printf("Enter a number: ");
    gmp_scanf("%Zd", number);

    // Count the number of set bits
    int result = countSetBits(number);

    // Output the result
    printf("Number of set bits in the binary representation: %d\n", result);

    mpz_clear(number);

    return 0;
}