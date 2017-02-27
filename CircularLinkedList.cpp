#include <iostream>
#include <stdlib.h>
using namespace std;

/* structure for a node */
struct node
{
    int data;
    struct node *next;
};

/* Function to insert a node at the begining of a Circular
   linked list */
void push(struct node **head_ref, int data)
{
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = data;
	ptr->next = *head_ref;
	struct node *temp = *head_ref;
	 /* If linked list is not NULL then set the next of last node. 
	 	It is going to last node by circling 1 times.
	 */
	if(*head_ref != NULL){
		while(temp->next != *head_ref){
			temp = temp->next;
		}
		//set last node by ptr
		temp->next = ptr;
	}
	else{
		// 1 node circular linked list
		ptr->next = ptr;
	}
	// after push ptr is the new node
	*head_ref = ptr;
}

//get the previous node
struct node* getPreviousNode(struct node* current_node){
	struct node* prev = current_node;
	while(prev->next != NULL && prev->next->data != current_node->data ){
		prev = prev->next;
	}
	return prev; 
}


/* Given a reference (pointer to pointer) to the head of a list
   and a key, deletes the first occurrence of key in linked list */
void deleteNodeByKey(struct node **head_ref, int key)
{
    struct node* current_node = *head_ref, *prev;
    
    while(current_node != NULL && current_node->data != key){
    	current_node = current_node->next;   
    }
    
    if(current_node == NULL){
    	return;current_node->next;
    }
    //Removing the node
    if(current_node->data == key){
    	//key is inside head node
    	if(current_node == *head_ref ){
    		//changing the head point to next
    		*head_ref = current_node->next;
    	}
    	prev = getPreviousNode(current_node);
        prev->next = current_node->next; 
        current_node->next = NULL;
        free(current_node);               
        return;
    }
}


/* Function to print nodes in a given Circular linked list */
void printList(struct node *head)
{
	struct node *temp = head;
	if(head != NULL){
		/*
			do-while because at 1st temp points head 
			and after 1 rotation temp wil come back to head again
		*/
		do{
			cout<<temp->data<<' ';
			temp = temp->next;
		}
		while(temp != head);
		cout<<endl;
	}
}

int main() {
	 /* Initialize lists as empty */
    struct node *head = NULL;
    /* Created linked list will be 11->2->56->12 */
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
    cout<<"Contents of Circular Linked List"<<endl;
    printList(head);
    deleteNodeByKey(&head, 12);
    printList(head);
    
	return 0;
}