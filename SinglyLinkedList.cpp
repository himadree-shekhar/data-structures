#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
	int data;
	struct node* next;	
};


void printList( struct node *head_ref){
	while(head_ref !=NULL){
		cout<<head_ref->data<<" ";	
		head_ref = head_ref->next;
	}
	cout<<endl;
}


//pointer to pointer is used for Direct change in head pointer without return;
void push(struct node** head_ref, int new_node_data){
    struct node* new_node = (struct node*) malloc (sizeof(struct node));
    new_node->data = new_node_data;
    //Chain pointer *head_ref pointing *head pointer(it's Address value)
    new_node->next = *head_ref;
    //Means head = new_node;
    *head_ref = new_node;
    
}

/* Given a node prev_node, insert a new node after the given
   prev_node */
void insertAfter(struct node* prev_node, int new_data){
	
	if(prev_node == NULL){
		cout<<"Its Null"<<endl;	
		return;
	}
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;
	// to Retain all the linked list nodes after prev_node
	new_node->next = prev_node->next;
	// new_node is now inserted after prev_node
	prev_node->next = new_node;
	
}

/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end  */
void append(struct node** head_ref, int new_node_data){
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_node_data;
	new_node->next = NULL;
	struct node* last_node = *head_ref;
	//check if the struct node* is exists
	if(*head_ref == NULL){
		*head_ref  = new_node;
		return;
	}
	
	while(last_node->next != NULL){
		last_node= last_node->next;
	}
	last_node->next = new_node;
}


/* Given a reference (pointer to pointer) to the head of a list
   and a key, deletes the first occurrence of key in linked list */
void deleteNodeByKey(struct node **head_ref, int key){
	struct node *prev, *temp;
	temp = *head_ref;
	if(temp != NULL && temp->data == key){
		*head_ref = temp->next;
		free(temp);
		return;
	}
	
	while(temp != NULL && temp->data != key){
		prev = temp;
		temp = temp->next;
	}
	
	if(temp == NULL)
		return;
		
	prev->next = temp->next;
	free(temp);	
}


/* Given a reference (pointer to pointer) to the head of a list
   and a position, deletes the node at the given position */
void deleteNodeByPosition(struct node **head_ref, int position){
	if(*head_ref == NULL)
		return;
	struct node* temp = *head_ref;
	
	if(position == 0){
		*head_ref = temp->next;
		free(temp);
	}
	
	for(int i=0; temp != NULL && i<position-1; i++){
		temp = temp->next;
	}
	
	if(temp == NULL || temp->next == NULL)
		return;
		
	struct node* next = temp->next->next;	
	free(temp->next);
	temp->next = next;
	
}


int main() {
	// your code goes here
	/* Start with the empty list */
    
    struct node* head = (struct node*) malloc (sizeof(struct node));
    head->data = 1;
    head->next = NULL;
    push(&head, 2);
    printList(head);
    insertAfter(head , 3);
    printList(head);
    append(&head, 4);
    printList(head);			
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    printList(head);
    deleteNodeByKey(&head, 1);
    deleteNodeByPosition(&head, 2);
    printList(head);
	return 0;
}
