#include <stdio.h>

// Maximum size of the array
#define MAX_SIZE 100

// Function to display the elements of the array
void display(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a given position
int insert(int arr[], int size, int element, int position) {
    if (size >= MAX_SIZE) {
        printf("Array is full. Insertion failed.\n");
        return size;
    }

    if (position < 0 || position > size) {
        printf("Invalid position. Insertion failed.\n");
        return size;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    return size + 1;
}

// Function to delete an element at a given position
int deleteElement(int arr[], int size, int position) {
    if (size <= 0) {
        printf("Array is empty. Deletion failed.\n");
        return size;
    }

    if (position < 0 || position >= size) {
        printf("Invalid position. Deletion failed.\n");
        return size;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}

// Function to search for an element in the array
int search(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position;

    while (1) {
        printf("\nArray Operations Menu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search Element\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                size = insert(arr, size, element, position);
                break;

            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                size = deleteElement(arr, size, position);
                break;

            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                position = search(arr, size, element);
                if (position != -1) {
                    printf("Element found at position %d.\n", position);
                } else {
                    printf("Element not found in the array.\n");
                }
                break;

            case 4:
                display(arr, size);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
