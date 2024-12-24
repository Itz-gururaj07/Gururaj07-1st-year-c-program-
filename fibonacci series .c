#include <stdio.h>

int main() {
    int n, t1 = 0, t2 = 1, nextTerm;

    // Prompt the user to enter the number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Handle the case when n is less than or equal to 0
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("Fibonacci Series: ");

        // Iterate through the number of terms
        for (int i = 1; i <= n; ++i) {
            // Print the current term
            printf("%d", t1);

            // Calculate the next term
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;

            // Print a comma and space after each term except the last one
            if (i < n) {
                printf(", ");
            }
        }
        printf("\n");
    }

    return 0;
}
