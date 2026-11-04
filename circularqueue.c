#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int cqueue[MAX];
int front = -1, rear = -1;


void insert() {
    int item;

    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("\nQueue Overflow!.\n");
    } else {
        printf("Enter the integer to insert: ");
        scanf("%d", &item);


        if (front == -1) {
            front = 0;
            rear = 0;
        } else {

            rear = (rear + 1) % MAX;
        }

        cqueue[rear] = item;
        printf("Inserted %d into the circular queue.\n", item);
    }
}


void deleted_eleement() {

    if (front == -1) {
        printf("\nQueue Empty (Underflow)! .\n");
    } else {
        printf("Deleted %d from the circular queue.\n", cqueue[front]);

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {

            front = (front + 1) % MAX;
        }
    }
}

void display() {
    if (front == -1) {
        printf("\nQueue is Empty!\n");
        return;
    }

    printf("\nCircular Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: deleted_eleement(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
