#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#ifndef DATATYPE
    #define DATATYPE int
#endif // DATATYPE

typedef struct Node Node;

struct Node {
    DATATYPE data;
    Node *prev;
    Node *next;
};


Node *create_node(DATATYPE data);
void *destroy_node(Node **node_ref);

// doubly-linked-list functions
void insert_at_beg(DATATYPE data, Node **head_ref);
void insert_at_end(DATATYPE data, Node **head_ref);
void insert_at_pos(DATATYPE data, int pos, Node **head_ref);

void delete_at_beg(Node **head_ref);
void delete_at_end(Node **head_ref);
void delete_at_pos(int pos, Node **head_ref);

int count_nodes(Node **head_ref);
void display_list(Node **head_ref);
void clear_list(Node **head_ref);

int main() {
    printf("Hello World!!\n");
    return 0;
}

Node *create_node(DATATYPE data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    assert(new_node != NULL);

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

void *destroy_node(Node **node_ref) {
    assert(node_ref != NULL);

    if(*node_ref != NULL) free(node_ref);
}

void insert_at_beg(DATATYPE data, Node **head_ref) {
    assert(head_ref != NULL);

    if(*head_ref == NULL) {
        *head_ref = create_node(data);
        return;
    }

    Node *head = *head_ref;
    head->prev = create_node(data);

    head->prev->next = head;
    head = head->prev;
}

void insert_at_end(DATATYPE data, Node **head_ref) {
    assert(head_ref != NULL);

    Node *head = *head_ref;
    if(head == NULL) {
        insert_at_beg(data, head_ref);
        return;
    }

    Node *curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    } 

    // now curr is at last node
    curr->next = create_node(data);
    curr->next->prev = curr;
}

// 1 based indexing
void insert_at_pos(DATATYPE data, int pos, Node **head_ref) {
    assert(head_ref != NULL);

    Node *head = *head_ref;

    assert(pos >= 0 && pos <= INT_MAX);

    if(pos <= 1) {
        insert_at_beg(data, head_ref);
        return;
    }

    if(pos > count_nodes(head_ref)) {
        insert_at_end(data, head_ref);
        return;
    }

    // here 2 <= pos <= total nodes in list
    int prev_counter = 1;
    Node *prev_to_target_node = head;

    while(prev_counter != pos-1) {
        prev_to_target_node = prev_to_target_node->next;
        prev_counter++;
    }

    prev_to_target_node->next->prev = create_node(data);
    prev_to_target_node->next->prev->next = prev_to_target_node->next;
    prev_to_target_node->next->prev->prev = prev_to_target_node;
    prev_to_target_node->next = prev_to_target_node->next->prev;
}

void delete_at_beg(Node **head_ref) {
    assert(head_ref != NULL);

    Node *head = *head_ref;
    
    if(head == NULL) return;
    if(head->next == NULL) {
        Node *temp = head;
        head = NULL;
        free(temp);
        return;
    }

    // here atleast 2 elements are present in linked list
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    free(temp);
}

void delete_at_end(Node **head_ref) {
    assert(head_ref != NULL);

    Node *head = *head_ref;

    if(head == NULL) return;
    if(head->next == NULL) {
        delete_at_beg(&head);
        return;
    }

    // here atleast 2 elements are present in linked list
    Node *curr = head;
    
    while(curr->next != NULL) {
        curr = curr->next;
    }

    curr->prev->next = NULL;
    curr->prev = NULL;

    free(curr);
}

// 1 based indexing
void delete_at_pos(int pos, Node **head_ref) {
    assert(head_ref != NULL);

    int total_nodes = count_nodes(head_ref);

    assert(1 <= pos && pos <= total_nodes);

    if(pos == 1) {
        delete_at_beg(head_ref);
        return;
    }

    if(pos == total_nodes) {
        delete_at_end(head_ref);
        return;
    }

    // case: when atleast three nodes are present in the list
    int prev_counter = 1;
    Node *prev_to_target_node = *head_ref;

    while(prev_counter != pos - 1) {
        prev_to_target_node = prev_to_target_node->next;
        prev_counter++;
    }

    Node *temp = prev_to_target_node->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->prev = NULL;
    temp->next = NULL;
    
    free(temp);
}

int count_nodes(Node **head_ref) {
    assert(head_ref != NULL);

    int count = 0;
    Node *curr = *head_ref;

    while(curr != NULL) {
        curr++;
        curr = curr->next;
    }

    return count;
}

// void display_list(Node **head_ref) {
//     assert(head_ref != NULL);


// }

void clear_list(Node **head_ref) {
    assert(head_ref != NULL);

    Node *head = *head_ref;

    int total_nodes = count_nodes(&head);
    
    if(total_nodes == 0) return;

    if(total_nodes == 1) {
        Node *temp = head;
        head = NULL;

        free(temp);
        return;
    }

    // case: at least 2 nodes are present here
    Node *traverser = head;
    head = NULL;
    
    while(traverser != NULL) {
        Node *temp = traverser;
        traverser = traverser->next;

        traverser->prev = NULL;
        temp->next = NULL;

        destroy_node(&temp);
    }
}