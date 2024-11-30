#include <stdio.h>

void meters_to_kilometers() {
    float meters;
    printf("Enter distance in meters: ");
    scanf("%f", &meters);
    printf("%.2f meters is equal to %.2f kilometers\n", meters, meters / 1000);
}

void grams_to_kilograms() {
    float grams;
    printf("Enter weight in grams: ");
    scanf("%f", &grams);
    printf("%.2f grams is equal to %.2f kilograms\n", grams, grams / 1000);
}

int main() {
    int choice;

    printf("Unit Converter\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Grams to Kilograms\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            meters_to_kilometers();
            break;
        case 2:
            grams_to_kilograms();
            break;
        default:
            printf("Invalid option. Please choose 1 or 2.\n");
    }

    return 0;
}
