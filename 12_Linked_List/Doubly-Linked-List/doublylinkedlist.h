
#ifndef DLL_DOUBLY_LINKED_LIST_H_
#define DLL_DOUBLY_LINKED_LIST_H_

typedef struct Node Node;
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

int check_pointer_validity(Node *pNode);
int check_double_pointer_validity(Node **ppNode);

Node *CREATE_NODE(int data);
void DESTROY_NODE(Node **node_ref);

void insert_at_head(Node** head_ref, int data);
void insert_at_posi(Node** head_ref, int data, int pos);
void insert_at_tail(Node** head_ref, int data);
void delete_at_head(Node** head_ref);
void delete_at_posi(Node** head_ref, int pos);
void delete_at_tail(Node** head_ref);

void reverse_list(Node** head_ref);
int clear_list(Node** head_ref);
int display_list(Node** head_ref);

#endif // DLL_DOUBLY_LINKED_LIST_H_