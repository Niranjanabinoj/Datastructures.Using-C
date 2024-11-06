#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// Define the node structure
typedef struct node {
    int value;
    int size;
    struct node* prev;
    struct node* next;
} node;

// Function to create a new node
node* create() {
    node* t = malloc(sizeof(node));
    printf("Enter the value: ");
    scanf("%d", &(t->value));
    printf("Enter the size: ");
    scanf("%d", &(t->size));
    t->next = NULL;
    t->prev = NULL;
    return t;
}

// Function to insert a node at the end of the list
node* insert(node* t, node* H) {
    if (H == NULL) {
        H = t;
    } else {
        node* p = H;
        while (p->next) {
            p = p->next;
        }
        p->next = t;
        t->prev = p;
    }
    return H;
}

// Function to insert a "garbage" node at the end of the garbage list
node* insertGarbage(int p, node* HG) {
    node* t = malloc(sizeof(node));
    t->next = NULL;
    t->prev = NULL;
    t->size = p;
    t->value = INT_MIN;
    if (HG == NULL) {
        HG = t;
    } else {
        node* p = HG;
        while (p->next) {
            p = p->next;
        }
        p->next = t;
        t->prev = p;
    }
    return HG;
}

// Function to display the current list
void display(node* H) {
    printf("\nThe current list is: ");
    node* p = H;
    while (p) {
        if (p->value != INT_MIN) {
            printf("%d -> ", p->value);
        } else {
            printf("# -> ");
        }
        p = p->next;
    }
    printf("NULL\n");

    printf("The corresponding sizes are: ");
    p = H;
    while (p) {
        printf("%d -> ", p->size);
        p = p->next;
    }
    printf("NULL\n");
}

// Function to display the garbage collection list
void displayGarbage(node* HG) {
    printf("\nThe garbage values are: ");
    node* p = HG;
    while (p) {
        printf("%d -> ", p->size);
        p = p->next;
    }
    printf("NULL\n");
}

// Function to delete a node (mark as garbage) from the list
node* delete(node* H, node* HG) {
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    node* p = H;
    for (int i = 1; i < pos; i++) {
        if (p == NULL) {
            printf("Position out of bounds.\n");
            return HG;
        }
        p = p->next;
    }

    if (p && p->value != INT_MIN) {
        p->value = INT_MIN; // Mark as garbage
        HG = insertGarbage(p->size, HG); // Add to garbage collection list
    }

    display(H);
    return HG;
}

// Function to collect the garbage values
void garbageCollection(node* H, node* HG) {
    node* p = H;
    int garbage = 0;
    while (p) {
        if (p->value == INT_MIN) {
            garbage += p->size; // Add the size of the garbage node
        }
        p = p->next;
    }
    printf("The amount of garbage collected is: %d\n", garbage);
    displayGarbage(HG);
}

// Main function to drive the program
int main() {
    node* HL = NULL;  // Head of the list
    node* HG = NULL;  // Head of the garbage list
    int n, pos;

    while (1) {
        printf("\n=====================\n");
        printf("1. Display\n2. Insert\n3. Delete\n4. Collect Garbage\n5. Exit\n");
        printf("=====================\n");
        printf("Enter choice: ");
        scanf("%d", &n);
        node* t;

        switch (n) {
            case 1:
                display(HL); // Display the list
                break;
            case 2:
                t = create(); // Create and insert a new node
                HL = insert(t, HL);
                display(HL);
                break;
            case 3:
                HG = delete(HL, HG); // Delete (mark as garbage)
                break;
            case 4:
                garbageCollection(HL, HG); // Collect garbage
                break;
            case 5:
                exit(0); // Exit the program
            default:
                printf("Wrong option selected.\n");
        }
    }
}
