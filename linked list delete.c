#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertEnd(struct Node **head, int value)
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
        return;
    }

    struct Node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newnode;
}

void deleteFirst(struct Node **head)
{
    struct Node *temp;

    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;
    printf("Deleted first element: %d\n", temp->data);
    free(temp);
}

void deleteEnd(struct Node **head)
{
    struct Node *temp, *prev;

    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

   \
    if ((*head)->next == NULL)
    {
        printf("Deleted last element: %d\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    temp = *head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted last element: %d\n", temp->data);
    prev->next = NULL;
    free(temp);
}

void deleteValue(struct Node **head, int value)
{
    struct Node *temp, *prev;

    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }


    if ((*head)->data == value)
    {
        temp = *head;
        *head = (*head)->next;
        printf("Deleted value %d from list\n", value);
        free(temp);
        return;
    }

    temp = *head;
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value %d not found in list\n", value);
        return;
    }

    printf("Deleted value %d from list\n", value);
    prev->next = temp->next;
    free(temp);
}


void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, val;


    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    while (1) {
        printf(" DELETION MENU ");
        printf("1. Delete First\n");
        printf("2. Delete Last \n");
        printf("3. Delete Specified Element\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteFirst(&head);
                break;
            case 2:
                deleteEnd(&head);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteValue(&head, val);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting deletion program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
