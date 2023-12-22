/////////////////////////////////////////////////////////////////////
//              Singly Linked List in C Language
/////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int data;
    struct Node *next;
};

//-------------------------------------------------------------------
__attribute__((unused)) int check_pointer_validity(Node *pVar);
int check_double_pointer_validity(Node **ppVar);
//-------------------------------------------------------------------
Node *CREATE_NODE(int data);
void DESTROY_NODE(Node **node_ref);
//-------------------------------------------------------------------
void insert_at_head(Node** head_ref, int data);
void insert_at_posi(Node** head_ref, int data, int pos);
void insert_at_tail(Node** head_ref, int data);
void delete_at_head(Node** head_ref);
void delete_at_posi(Node** head_ref, int pos);
void delete_at_tail(Node** head_ref);
//-------------------------------------------------------------------
int count_nodes(Node** head_ref);
// void reverse_list(Node** head_ref); TODO:
int clear_list(Node** head_ref);
int display_list(Node** head_ref);
//-------------------------------------------------------------------
//int main() {
//    // code here
//    Node* head = NULL;
//    insert_at_head(&head, 10);
//    insert_at_head(&head, 5);
//    printf("Count Nodes : %d\n", count_nodes(&head));
//    insert_at_posi(&head, 20, 3);
//    printf("Count Nodes : %d\n", count_nodes(&head));
//    insert_at_tail(&head, 30);
//    display_list(&head);
//    delete_at_posi(&head, 4);
//    display_list(&head);
//    delete_at_tail(&head);
//    delete_at_posi(&head, 1);
//    display_list(&head);
////    delete_at_head(&head);
////    display_list(&head);
////    delete_at_tail(&head);
////    display_list(&head);
////    delete_at_posi(&head, );
////    display_list(&head);
//
//    clear_list(&head);
//    if(display_list(&head)) printf("Empty List.\n");
//    return 0;
//}

int display_list(Node** head_ref) {
    if (check_double_pointer_validity(head_ref)) return 1;

    Node* temp = *head_ref; // temp is pointing to the head node
    while (temp != NULL) {
        printf("\033[38;5;198m%d\033[0m \033[38;5;39m->\033[38;5;117m \033[0m", temp->data);
        temp = temp->next; // travel to the next node
    }
    printf("\033[38;5;34mNULL\033[0m\n");
    return 0;
}

int clear_list(Node **head_ref) {
    if (check_double_pointer_validity(head_ref)) return 1;

    Node *curr = *head_ref;
    while (curr != NULL) {
        Node *temp = curr;
        curr = curr->next;

        // Destroy Node
        DESTROY_NODE(&temp);
    }

    // Set the head pointer to NULL after clearing the list
    *head_ref = NULL;
    return 0; // Indicate SUCCESS
}

//void reverse_list(Node **head_ref) {
//    // TODO: Implement this function
//}

int count_nodes(Node** head_ref) {
    if(check_double_pointer_validity(head_ref)) return 0;

    int count = 0;
    Node *curr = *head_ref;
    while(curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

void insert_at_head(Node** head_ref, int data) {
    Node* new_node = CREATE_NODE(data);

    // transferring the head to new node
    new_node->next = *head_ref;
    *head_ref = new_node; 
}

void insert_at_posi(Node** head_ref, int data, int pos) {
    if(pos < 0) return;
    if(pos == 0 || pos == 1) {
        insert_at_head(head_ref, data);
        return;
    }
    if(pos > count_nodes(head_ref)) {
        insert_at_tail(head_ref, data);
        return;
    }

    // here 1 < pos <= total_nodes
    Node* new_node = CREATE_NODE(data);
    int prev = 1;
    Node* prev_node = *head_ref;
    while(prev != pos - 1) {
        prev_node = prev_node->next;
        prev++;
    }
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insert_at_tail(Node** head_ref, int data) {
    if(count_nodes(head_ref) == 0) {
        insert_at_head(head_ref, data);
        return;
    }
    Node *curr = *head_ref;
    while(curr->next != NULL) curr = curr->next;

    curr->next = CREATE_NODE(data);
    curr->next->next = NULL;
}

void delete_at_head(Node** head_ref) {
    // TODO: Implement this function
    if(count_nodes(head_ref) == 0) return;

    Node *temp = *head_ref;
    (*head_ref) = (*head_ref)->next;
    DESTROY_NODE(&temp);
}

void delete_at_posi(Node** head_ref, int pos) {
    int total_nodes = count_nodes(head_ref);
    if(pos <= 0 || pos > total_nodes) return;

    // here 1 <= pos <= total_nodes
    if(pos == 1) {
        delete_at_head(head_ref);
        return;
    }
    if(pos == total_nodes) {
        delete_at_tail(head_ref);
        return;
    }

    // here 2 <= pos < total_nodes
    int prev = 1;
    Node* prev_node = *head_ref;
    while(prev != pos - 1) {
        prev_node = (Node *) prev_node->next;
        prev++;
    }
    Node *temp = prev_node->next;
    prev_node->next = temp->next;
    temp->next = NULL;
    DESTROY_NODE(&temp);
}

void delete_at_tail(Node** head_ref) {
    // TODO: Implement this function
    if(count_nodes(head_ref) == 0) return;
    if(count_nodes(head_ref) == 1) {
        delete_at_head(head_ref);
        return;
    }

    // here at least two elements are existing
    Node *prev = *head_ref;
    // traverse to second-to-last node
    while(prev->next->next != NULL) {
        prev = prev->next;
    }
    Node *temp = prev->next;
    prev->next = NULL;
    DESTROY_NODE(&temp);
}

Node *CREATE_NODE(int data) {
    Node* newNode = (Node *) malloc(sizeof(Node));
    if(newNode == NULL) return NULL;

    // Memory allocation success
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void DESTROY_NODE(Node **node_ref) {
    if (check_double_pointer_validity(node_ref)) return;

    // Set the next pointer to NULL before freeing the memory
    (*node_ref)->next = NULL;

    // Free the memory of the Node structure
    free(*node_ref);

    // Set the double pointer to NULL to avoid a dangling pointer
    *node_ref = NULL;
}

int check_double_pointer_validity(struct Node **ppVar) {
    if(ppVar == NULL) return 1;
    return (*ppVar == NULL) ? 1 : 0;
} 

__attribute__((unused)) int check_pointer_validity(Node *pVar) {
    /**
     * Here pVar is a pointer to a stack located object.
     * And it can't be void.
     */
    if(pVar == NULL) return 1; // indicate failure
    return 0; // indicate success
}
