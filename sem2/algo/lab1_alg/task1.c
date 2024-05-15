#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *create_node(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new node at the beginning of the list
void add_begin(struct Node **head, int data) {
    struct Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to add a new node at any position in the list
void add_any(struct Node **head, int data, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 0) {
        add_begin(head, data);
        return;
    }

    struct Node *new_node = create_node(data);
    struct Node *temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to remove a node from any position in the list
void remove_any(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node *next_node = temp->next->next;
    free(temp->next);
    temp->next = next_node;
}

void print_list(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node *head = NULL;

    for (int i = 15; i >= 1; i--) {
        add_begin(&head, i);
    }

    printf("Initial list:\n");
    print_list(head);

    add_any(&head, 100, 3);
    add_any(&head, 200, 7);

    printf("\nList after adding elements at specific positions:\n");
    print_list(head);

    remove_any(&head, 2);
    remove_any(&head, 6);

    printf("\nList after removing elements from specific positions:\n");
    print_list(head);

    return 0;
}
