#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold student information
typedef struct {
    int rollNumber;
    char name[50];
    float marks;
} Student;

// Function prototypes
void addStudent();
void viewStudents();
void editStudent();
void deleteStudent();

int main() {
    int choice;

    do {
        printf("\n--- Student Record Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Edit Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                editStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new student
void addStudent() {
    FILE *file = fopen("students.dat", "ab");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    Student student;
    printf("Enter roll number: ");
    scanf("%d", &student.rollNumber);
    printf("Enter name: ");
    getchar(); // Consume the newline left by scanf
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; // Remove newline
    printf("Enter marks: ");
    scanf("%f", &student.marks);

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);
    printf("Student added successfully!\n");
}

// Function to view all students
void viewStudents() {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    Student student;
    printf("\n--- Student Records ---\n");
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("Roll Number: %d\n", student.rollNumber);
        printf("Name: %s\n", student.name);
        printf("Marks: %.2f\n", student.marks);
        printf("--------------------------\n");
    }
    fclose(file);
}

// Function to edit a student's information
void editStudent() {
    FILE *file = fopen("students.dat", "rb+");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int rollNumber, found = 0;
    Student student;

    printf("Enter roll number of student to edit: ");
    scanf("%d", &rollNumber);

    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.rollNumber == rollNumber) {
            found = 1;
            printf("Enter new name: ");
            getchar(); // Consume the newline left by scanf
            fgets(student.name, sizeof(student.name), stdin);
            student.name[strcspn(student.name, "\n")] = '\0'; // Remove newline
            printf("Enter new marks: ");
            scanf("%f", &student.marks);

            fseek(file, -sizeof(Student), SEEK_CUR);
            fwrite(&student, sizeof(Student), 1, file);
            printf("Student record updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }

    fclose(file);
}

// Function to delete a student's record
void deleteStudent() {
    FILE *file = fopen("students.dat", "rb");
    FILE *tempFile = fopen("temp.dat", "wb");
    if (file == NULL || tempFile == NULL) {
        perror("Error opening file");
        return;
    }

    int rollNumber, found = 0;
    Student student;

    printf("Enter roll number of student to delete: ");
    scanf("%d", &rollNumber);

    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.rollNumber == rollNumber) {
            found = 1;
            printf("Student record deleted successfully!\n");
            continue;
        }
        fwrite(&student, sizeof(Student), 1, tempFile);
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }

    fclose(file);
    fclose(tempFile);

    remove("students.dat");
    rename("temp.dat", "students.dat");
}
