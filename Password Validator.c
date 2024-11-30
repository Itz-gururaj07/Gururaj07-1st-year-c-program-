#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_password(const char *password) {
    int length = strlen(password);
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i]))
            has_upper = 1;
        else if (islower(password[i]))
            has_lower = 1;
        else if (isdigit(password[i]))
            has_digit = 1;
        else if (strchr("@#$%^&*()-+=!", password[i]))
            has_special = 1;
    }

    if (length >= 8 && has_upper && has_lower && has_digit && has_special) {
        return 1; 
    }
    return 0; 
}

int main() {
    char password[100];

    printf("Enter a password to validate: ");
    scanf("%s", password);

    if (is_valid_password(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is invalid. Ensure it:\n");
        printf("- Is at least 8 characters long\n");
        printf("- Contains at least one uppercase letter\n");
        printf("- Contains at least one lowercase letter\n");
        printf("- Contains at least one digit\n");
        printf("- Contains at least one special character (@, #, $, etc.)\n");
    }

    return 0;
}
