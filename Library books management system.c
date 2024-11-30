#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

// Structure to represent a book
typedef struct Book {
    int id;                     // Unique ID for each book
    char title[MAX_TITLE_LENGTH];  // Book title
    char author[MAX_AUTHOR_LENGTH]; // Author name
    struct Book* next;           // Pointer to the next book (for linked list)
} Book;

// Function prototypes
void addBook(Book** head, int id, const char* title, const char* author);
void deleteBook(Book** head, int id);
void searchBookById(Book* head, int id);
void listBooks(Book* head);
Book* createBook(int id, const char* title, const char* author);

int main() {
    Book* bookList = NULL;  // Head of the linked list (initially empty)
    int choice, id;
    char title[MAX_TITLE_LENGTH], author[MAX_AUTHOR_LENGTH];

    while (1) {
        printf("\nBook Management System\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Search Book by ID\n");
        printf("4. List All Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                getchar();  // Consume the newline
                printf("Enter Book Title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove the newline at the end
                printf("Enter Book Author: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = '\0'; // Remove the newline at the end
                addBook(&bookList, id, title, author);
                break;

            case 2:
                printf("Enter Book ID to Delete: ");
                scanf("%d", &id);
                deleteBook(&bookList, id);
                break;

            case 3:
                printf("Enter Book ID to Search: ");
                scanf("%d", &id);
                searchBookById(bookList, id);
                break;

            case 4:
                listBooks(bookList);
                break;

            case 5:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new book
Book* createBook(int id, const char* title, const char* author) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    if (!newBook) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->next = NULL;
    return newBook;
}

// Function to add a book to the list
void addBook(Book** head, int id, const char* title, const char* author) {
    Book* newBook = createBook(id, title, author);
    newBook->next = *head;
    *head = newBook;
    printf("Book added successfully.\n");
}

// Function to delete a book by ID
void deleteBook(Book** head, int id) {
    Book* temp = *head;
    Book* prev = NULL;

    // If the book to delete is the head of the list
    if (temp != NULL && temp->id == id) {
        *head = temp->next;  // Move head to next node
        free(temp);
        printf("Book with ID %d deleted successfully.\n", id);
        return;
    }

    // Search for the book to delete
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    // If book not found
    if (temp == NULL) {
        printf("Book with ID %d not found.\n", id);
        return;
    }

    // Unlink the book from the list
    prev->next = temp->next;
    free(temp);
    printf("Book with ID %d deleted successfully.\n", id);
}

// Function to search for a book by ID
void searchBookById(Book* head, int id) {
    Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Book found: ID = %d, Title = %s, Author = %s\n", temp->id, temp->title, temp->author);
            return;
        }
        temp = temp->next;
    }
    printf("Book with ID %d not found.\n", id);
}

// Function to list all books
void listBooks(Book* head) {
    if (head == NULL) {
        printf("No books in the system.\n");
        return;
    }

    Book* temp = head;
    printf("\nList of Books:\n");
    while (temp != NULL) {
        printf("ID = %d, Title = %s, Author = %s\n", temp->id, temp->title, temp->author);
        temp = temp->next;
    }
}
