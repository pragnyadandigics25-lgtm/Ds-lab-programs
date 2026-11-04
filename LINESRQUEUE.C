#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! .\n");
    } else {
        if (front == -1) front = 0;
        printf("Enter the integer to insert: ");
        scanf("%d", &item);
        rear++;
        queue[rear] = item;
        printf("Inserted %d into the queue.\n", item);
    }
}

void delete_element() {
    if (front == -1 || front > rear) {
        printf("\nQueue Empty (Underflow)! .\n");
    } else {
        printf("Deleted %d from the queue.\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is Empty!\n");
    } else {
        printf("\nQueue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Linear Queue Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete_element(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
