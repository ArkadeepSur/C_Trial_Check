#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int available;
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }
    Book new_book;
    new_book.id = book_count + 1;
    printf("Enter title: ");
    getchar(); // To consume the newline character left by previous input
    fgets(new_book.title, MAX_TITLE_LENGTH, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = '\0'; // Remove trailing newline
    printf("Enter author: ");
    fgets(new_book.author, MAX_AUTHOR_LENGTH, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = '\0'; // Remove trailing newline
    new_book.available = 1;
    library[book_count++] = new_book;
    printf("Book added successfully.\n");
}

void list_books() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("ID\tTitle\t\tAuthor\t\tAvailable\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d\t%s\t\t%s\t\t%s\n", library[i].id, library[i].title, library[i].author, library[i].available ? "Yes" : "No");
    }
}

void search_book() {
    char query[MAX_TITLE_LENGTH];
    printf("Enter book title to search: ");
    getchar(); // To consume the newline character left by previous input
    fgets(query, MAX_TITLE_LENGTH, stdin);
    query[strcspn(query, "\n")] = '\0'; // Remove trailing newline
    for (int i = 0; i < book_count; i++) {
        if (strcasecmp(library[i].title, query) == 0) {
            printf("Book found: ID=%d, Title=%s, Author=%s, Available=%s\n", library[i].id, library[i].title, library[i].author, library[i].available ? "Yes" : "No");
            return;
        }
    }
    printf("Book not found.\n");
}

void delete_book() {
    int id;
    printf("Enter book ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            for (int j = i; j < book_count - 1; j++) {
                library[j] = library[j + 1];
            }
            book_count--;
            printf("Book deleted successfully.\n");
            return;
        }
    }
    printf("Book not found.\n");
}

void main_menu() {
    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                list_books();
                break;
            case 3:
                search_book();
                break;
            case 4:
                delete_book();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

int main() {
    main_menu();
    return 0;
}
