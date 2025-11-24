#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *prev,*next;
    };
struct Node *head = NULL;

// Create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// a) Create DLL — insert at end
void createDLL() {
    int n, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        struct Node *newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
        } else {
            struct Node *temp = head;
            while (temp->next) temp = temp->next;

            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

// b) Insert LEFT of a node
void insertLeft() {
    int key, value;
    printf("Enter key (value of node): ");
    scanf("%d", &key);
    printf("Enter new value to insert: ");
    scanf("%d", &value);

    struct Node *temp = head;

    while (temp && temp->data != key)
        temp = temp->next;

    if (!temp) {
        printf("Key not found.\n");
        return;
    }

    struct Node *newNode = createNode(value);

    if (temp == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
}

// c) Delete a node by value
void deleteValue() {
    int key;
    printf("Enter value to delete: ");
    scanf("%d", &key);

    struct Node *temp = head;

    while (temp && temp->data != key)
        temp = temp->next;

    if (!temp) {
        printf("Value not found.\n");
        return;
    }

    if (temp == head)
        head = head->next;

    if (temp->next)
        temp->next->prev = temp->prev;

    if (temp->prev)
        temp->prev->next = temp->next;

    free(temp);
    printf("Node deleted.\n");
}

// d) Display DLL
void display() {
    struct Node *temp = head;

    if (!head) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Insert Left of Node\n");
        printf("3. Delete Node by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createDLL(); break;
            case 2: insertLeft(); break;
            case 3: deleteValue(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
