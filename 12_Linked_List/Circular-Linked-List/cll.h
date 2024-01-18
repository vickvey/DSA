
#ifndef CIRCULAR_LINKED_LIST_H_
#define CIRCULAR_LINKED_LIST_H_

#ifndef DATATYPE 
    #define DATATYPE int 
#endif // DATATYPE

typedef struct Node Node;

struct Node {
    DATATYPE data;
    Node *next;
};

Node *create_node(DATATYPE data);
void destroy_node(Node **node_ref);



#endif //  CIRCULAR_LINKED_LIST_H_
