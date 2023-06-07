#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
    printf("Node with data %d inserted at the beginning.\n", data);
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
    printf("Node with data %d inserted at the end.\n", data);
}

// Function to delete a node from the list
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("The list is empty. Cannot delete node.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prevNode = NULL;

    // Check if the node to be deleted is the first node
    if (current->data == data && current->next == *head) {
        *head = NULL;
        free(current);
        printf("Node with data %d deleted from the list.\n", data);
        return;
    }

    struct Node* lastNode = *head;
    while (lastNode->next != *head) {
        lastNode = lastNode->next;
    }

    // Check if the node to be deleted is the first node
    if (current->data == data) {
        lastNode->next = current->next;
        *head = current->next;
        free(current);
        printf("Node with data %d deleted from the list.\n", data);
        return;
    }

    // Find the node to be deleted
    while (current->next != *head) {
        prevNode = current;
        current = current->next;
        if (current->data == data) {
            prevNode->next = current->next;
            free(current);
            printf("Node with data %d deleted from the list.\n", data);
            return;
        }
    }

    printf("Node with data %d not found in the list.\n", data);
}

// Function to perform linear search in the list
struct Node* linearSearch(struct Node* head, int key) {
    if (head == NULL) {
        return NULL;  // List is empty
    }

    struct Node* current = head;
    do {
        if (current->data == key) {
            return current;  // Node found
        }
        current = current->next;
    } while (current != head);

    return NULL;  // Node not found
}

// Function to display the contents of the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Function to free the memory allocated for the list
void freeList(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    struct Node* current = *head;
    struct Node* nextNode;
    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != *head);

    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete a node\n");
        printf("4. Search for a node\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be inserted at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter the data to be inserted at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the data of the node to be deleted: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                printf("Enter the data to be searched: ");
                scanf("%d", &key);
                struct Node* foundNode = linearSearch(head, key);
                if (foundNode != NULL) {
                    printf("Node with data %d found.\n", key);
                } else {
                    printf("Node with data %d not found.\n", key);
                }
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                freeList(&head);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }

        printf("\n");
    }

    return 0;
}
