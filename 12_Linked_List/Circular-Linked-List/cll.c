#include "cll.h"
#include <stdlib.h>
#include <assert.h>

Node *create_node(DATATYPE data) {
    Node *new_node = (Node *) malloc(sizeof(Node));

    assert(new_node != NULL);

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void destroy_node(Node **node_ref) {
    assert(node_ref != NULL);

    if(*node_ref != NULL) free(*node_ref);
}