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
void insertAtTail(int data, Node **headRef);
void insertAtPosi(int data, int pos, Node **headRef);

// TODO :-----------------------------------------------
void deleteAtHead(Node **headRef);
void deleteAtTail(Node **headRef);
void deleteAtPosi(int pos, Node **headRef);
//------------------------------------------------------

int countNodes(Node **headRef);
void displayList(Node **headRef);
void clearList(Node **headRef);

int main() {
	// code here
	struct Node *head = NULL;
	
	displayList(&head); // O/P : Empty list
        printf("The number of nodes are : %d\n", countNodes(&head));

	insertAtHead(10, &head);
	displayList(&head); // O/P : 10 -> NULL
        printf("The number of nodes are : %d\n", countNodes(&head));

	insertAtHead(5, &head);
	displayList(&head); // O/P : 5 -> 10 -> NULL
        printf("The number of nodes are : %d\n", countNodes(&head));
	
	insertAtHead(3, &head);
	insertAtHead(1, &head);
	
	displayList(&head); // O/P : 1 -> 3 -> 5 -> 10 -> NULL
        printf("The number of nodes are : %d\n", countNodes(&head));
	
	clearList(&head);
	puts("ListClearing is successfull");
	displayList(&head); // O/P : Empty list
	printf("The number of nodes are : %d\n", countNodes(&head));

	insertAtTail(10, &head);
	displayList(&head); // O/P : 10 -> NULL
        printf("The number of nodes are : %d\n", countNodes(&head));
	
	insertAtTail(20, &head);
	displayList(&head); // O/P : 10 -> 20 -> NULL
        printf("The number of nodes are : %d\n", countNodes(&head));

	while(1) {
		int data = 0;
		puts("Enter the data you want to be inserted : ");
		scanf("%d", &data);

		int pos = 0;
		puts("Enter the position at which you want the data to be inserted : ");
		scanf("%d", &pos);

		insertAtPosi(data, pos, &head);
		displayList(&head);
		printf("The number of nodes are : %d\n", countNodes(&head));

		int prompt = 0;
		puts("Enter 1 to continue or else enter any key to exit");
		scanf("%d", &prompt);

		if(prompt != 1) break;
	}
	clearList(&head);
	displayList(&head);
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

int countNodes(Node **headRef) {
	if(headRef == NULL) return -1;
	if(*headRef == NULL) return 0;
	
	// here size of list is >= 1
	int count = 1;
	Node *curr = *headRef;
	while(curr->next != NULL) {
		curr = curr->next;
		count++;
	}
	return count;
}

// TODO 

void insertAtPosi(int data, int pos, Node **headRef) {
	if(headRef == NULL) return;
	if(*headRef == NULL) {
		*headRef = createNode(data);
		return;
	}
	// here list size is >= 1
	if((*headRef)->next == NULL) {
		if(pos <= 1) {
			insertAtHead(data, headRef);
		} else {
			insertAtTail(data, headRef);
		}
		return;
	}

	// here list size is >= 2
	if(pos <= 1) {
		insertAtHead(data, headRef);
		return;
	}
	puts("checkpoint 1");
	// here pos >= 2
	int curr = 1;
	Node *it = *headRef;

	// here list size is >= 2
	while(it->next != NULL && curr != pos-1) {
		it = it->next;
		curr++;
		printf("curr : %d\n", curr);
		printf("curr->data : %d\n", it->data);
	}
	puts("checkpoint 2");
	if(it->next == NULL) {
		// handling the case where position to insert is greater than list size
		it->next = createNode(data);
		return;
	}
	puts("checkpoint 3");
	// insertion is always between two nodes
	Node *temp = createNode(data);
	temp->next = it->next;
	it->next = temp;
}

void insertAtTail(int data, Node **headRef) {
	if(headRef == NULL) return;
	if(*headRef == NULL) {
		*headRef = createNode(data);
		return;
	}
	Node *curr = *headRef;
	while(curr->next != NULL) curr = curr->next;
	curr->next = createNode(data);
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
