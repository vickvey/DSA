#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"

int check_pointer_validity(Node *pNode) {
    return (pNode == NULL) ? 1 : 0;
}

int check_double_pointer_validity(struct Node **ppNode) {
    if(ppVar == NULL) return 1;
    return (*ppVar == NULL) ? 1 : 0;
} 

Node *CREATE_NODE(int data) {
    Node* newNode = (Node *) malloc(sizeof(Node));
    if(newNode == NULL) return NULL;

    // Memory allocation success
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void DESTROY_NODE(Node **node_ref) {
    if (check_double_pointer_validity(node_ref)) return;

    // Set the prev and next pointers to NULL before freeing the memory
    (*node_ref)->prev = NULL;
    (*node_ref)->next = NULL;

    // Free the memory of the Node structure
    free(*node_ref);

    // Set the double pointer to NULL to avoid a dangling pointer
    *node_ref = NULL;
}

int count_nodes(Node** head_ref) {
    if(check_double_pointer_validity(head_ref)) return 0; 
    if((*head_ref)->next == NULL) return 1;
}

void insert_at_head(Node **head_ref, int data) {
    Node *temp = CREATE_NODE(data);
    if(temp == NULL) return;

    
}
