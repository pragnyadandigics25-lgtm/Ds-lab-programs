#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertFirst(struct Node **head, int val) {
    struct Node *nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = val;
    nn->next = *head;
    *head = nn;
    printf("Inserted %d at first", val);
}

void insertEnd(struct Node **head, int val)
{
    struct Node *nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = val;
    nn->next = NULL;
    if (!*head) { *head = nn; printf("Inserted %d at end.\n", val); return; }
    struct Node *temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = nn;
    printf("Inserted %d at end.\n", val);
}

void insertPosition(struct Node **head, int val, int pos)
 {
    if (pos == 1) { insertFirst(head, val); return; }
    struct Node *temp = *head;
    for (int i = 1; i < pos - 1 && temp; i++) temp = temp->next;
    if (!temp) { printf("Invalid position!\n"); return; }
    struct Node *nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = val;
    nn->next = temp->next;
    temp->next = nn;
    printf("Inserted %d at position %d.\n", val, pos);
}

void display(struct Node *head) {
    if (!head) { printf("List is empty!\n"); return; }
    printf("Linked List: ");
    for (; head; head = head->next) printf("%d -> ", head->data);
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, val, pos;

    while (1) {
        printf("INSERTION MENU");
        printf("1. Insert first\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertFirst(&head, val);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertEnd(&head, val);
                break;
            case 3:
                printf("Enter value and position (e.g., 20 3): ");
                scanf("%d %d", &val, &pos);
                insertPosition(&head, val, pos);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting insertion program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
