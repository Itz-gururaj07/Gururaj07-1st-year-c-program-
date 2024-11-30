#include <stdio.h>

float celsius_to_fahrenheit(float celsius) {

    return (celsius * 9 / 5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {

    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    int choice;
    float temp, converted_temp;

    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temp);
        converted_temp = celsius_to_fahrenheit(temp);
        printf("%.2f°C is equal to %.2f°F\n", temp, converted_temp);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temp);
        converted_temp = fahrenheit_to_celsius(temp);
        printf("%.2f°F is equal to %.2f°C\n", temp, converted_temp);
    } else {
        printf("Invalid option. Please choose 1 or 2.\n");
    }

    return 0;
}
