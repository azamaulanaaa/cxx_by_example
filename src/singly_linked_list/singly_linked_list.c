#include <stdlib.h>
#include "singly_linked_list.h"

int push_node(struct Node **head, struct Data data) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        
        return 1;
    }

    struct Node *current_node = *head;

    while(current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_node;

    return 1;
}

int delete_node(struct Node **head, int key) {
    struct Node *last_node = NULL;
    struct Node *current_node = *head;

    while(current_node != NULL) {
        if (current_node->data.key != key) {
            last_node = current_node;
            current_node = current_node->next;
            continue;
        } 

        struct Node *tmp = current_node;
        current_node = current_node->next;
        free(tmp);

        if (last_node == NULL) {
            *head = current_node;
        } else {
            last_node->next = current_node;
        }
    }

    return 1;
}
