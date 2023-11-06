#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;

struct Node {
	int data;
	Node *next;
};

Node *createNode(int data);
void destroyNode(Node **nodeRef);

void insertAtHead(int data, Node **headRef);

// TODO :-----------------------------------------------
void insertAtTail(int data, Node **headRef);
void insertAtPosi(int data, int pos, Node **headRef);

void deleteAtHead(Node **headRef);
void deleteAtTail(Node **headRef);
void deleteAtPosi(int pos, Node **headRef);

int countNodes(Node **headRef);
//-------------------------------------------------------
void displayList(Node **headRef);

void clearList(Node **headRef);

int main() {
	// code here
	struct Node *head = NULL;
	
	displayList(&head); // O/P : Empty list

	insertAtHead(10, &head);
	displayList(&head); // O/P : 10 -> NULL
	
	insertAtHead(5, &head);
	displayList(&head); // O/P : 5 -> 10 -> NULL
	
	insertAtHead(3, &head);
	insertAtHead(1, &head);
	
	displayList(&head); // O/P : 1 -> 3 -> 5 -> 10 -> NULL
	
	clearList(&head);
	puts("ListClearing is successfull");
	displayList(&head); // O/P : Empty list

	return 0;
}

void clearList(Node **headRef) {
    if (headRef == NULL || *headRef == NULL) return;

    // exactly 1 element
    if ((*headRef)->next == NULL) {
        puts("ONLY HeadNode is deleted");
        destroyNode(headRef);
        puts("ONLY HeadNode is deleted successfully");
    } else {
        // more than 1 element
        while ((*headRef)->next != NULL) {
            Node *temp = *headRef;
            (*headRef) = (*headRef)->next;
            destroyNode(&temp);
            puts("\tNode deletion completed");
            displayList(headRef);
        }
        puts("\tDeleting last Node");
        free(*headRef);
        *headRef = NULL;
        puts("\tLast Node is deleted");
    }
}

void displayList(Node **headRef) {
	if(headRef == NULL) {
		printf("Error! head pointer is non-existing.\n");
		return;
	}
	if(*headRef == NULL) {
		printf("Empty list\n");
		return;
	}
	Node *curr = *headRef;
	while(curr != NULL) {
		printf("%d -> ", curr->data);
		curr = curr->next;
	} 
	printf("NULL\n");
}

void insertAtHead(int data, Node **headRef) {
	if(headRef == NULL) return;
	if(*headRef == NULL) { 
		*headRef = createNode(data);
		return;
	}
	Node *node = createNode(data);
	node->next = *headRef;
	*headRef = node;
}

void destroyNode(Node **nodeRef) {
	if(nodeRef == NULL) return;
	if(*nodeRef != NULL)
		free((*nodeRef));
}

Node *createNode(int data) {
	Node *node = (Node *) malloc(sizeof(Node));
	if(node == NULL) return NULL;

	node->data = data;
	node->next = NULL;
	return node;
}