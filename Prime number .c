#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void find_and_save_primes(int start, int end, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int num = start; num <= end; num++) {
        if (is_prime(num)) {
            fprintf(file, "%d\n", num);
        }
    }

    fclose(file);
    printf("Prime numbers between %d and %d have been saved to %s.\n", start, end, filename);
}

int main() {
    int start, end;
    char filename[] = "primes.txt";
    
    printf("Enter the start of the range: ");
    scanf("%d", &start);
    printf("Enter the end of the range: ");
    scanf("%d", &end);

    find_and_save_primes(start, end, filename);

    return 0;
}
