#include <iostream>
using namespace std;
// struct name is case-sensative
struct node {
	int data;
	struct node *next;
	struct node *prev;
};

/* push new node in front/top 
  
          head_ref----head----node
  value   OXB---------OXC-----0
  address OXA---------OXB-----OXC
   
  struct node **head_ref = &head;
*/
void push(struct node **head_ref, int new_data){

	// 1. allocate node
	// void* malloc (size_t size);
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	// 2. store the data inside new node
	new_node->data = new_data;
	// 3. Make next of new node as head and previous as NULL
	
	// get the address value inside head
	new_node->next = *head_ref;
	new_node->prev = NULL;
	// 4. change prev of head node from NULL to new node
	if(*head_ref != NULL){
		// Parentheses () needed for higher precedence
		// (*head_ref)->prev means (head)->prev
		(*head_ref)->prev = new_node;
	}
	// 5. move the head to point to the new node
	// assigning new_node's address into head via *head_ref
	*head_ref = new_node;
	
	return;
}

/* Given a node as prev_node, insert a new node after the given node */
void insertAfter(struct node* prev_node, int new_data){
	// 1. check if the given prev_node is NULL
	if(prev_node == NULL){
		cout<<"given node is NULL"<<endl;
		return;	
	}
	
	// 2. allocate new node
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	// 3. put in the data
	new_node->data = new_data;
	// 4. Make next of new node as next of prev_node
	new_node->next = prev_node->next;
	// 5. Make the next of prev_node as new_node
	prev_node->next = new_node;
	// 6. Make prev_node as previous of new_node
	new_node->prev = prev_node;
	// check what if prev_node is the last node in the list
	if(new_node->next != NULL){
		// 7. Change previous of new_node's next node
		new_node->next->prev = new_node;
	}
	
	return;
}

/* Given a reference (pointer to pointer) to the head
   of a DLL and an int, appends a new node at the end  */
void append(struct node** head_ref, int new_data){
	// 1. allocate node
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	// 2. put in the data
	new_node->data = new_data;
	// 3. This new node will be the last node, so make next of it as NULL
	new_node->next = NULL;
	struct node* last_node = *head_ref;
	// 4. If the List is empty, then make the new node as head
	if(*head_ref == NULL){
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}	
	// 5. Else traverse till the last node
	while(last_node->next != NULL){
			last_node = last_node->next;	
	}
	
	// 6.  Change the next of last node
	last_node->next =  new_node;
	
	// 7. Make last node as previous of new node
	new_node->prev = last_node;
	
	return;
}

/* Given a node as next_node, insert a new node before the given node */
void insertBefore(struct node** next_node, int new_data){
	
	// 1. check if the given next_node is NULL
	if(*next_node == NULL){
		cout<<"given node is NULL"<<endl;
		return;	
	}
	// 2. allocate new node
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	// 3. put data in node
	new_node->data = new_data;
	
	// 4. case: if next_node id head
	// Parentheses () needed for higher precedence
	if((*next_node)->prev == NULL){
		(*next_node)->prev = new_node;
		 new_node->next = *next_node;
		 new_node->prev = NULL;
		 // setting new head
		 *next_node = new_node;
		return;
	}
	
	// 5. set new_node's next & prev
	new_node->next =  *next_node;
	new_node->prev = (*next_node)->prev;
	
	// 6. set next_node's prev & its prev->next
	(*next_node)->prev = new_node;
	new_node->prev->next = new_node;
	
	return;
}

/* Function to delete a node in a Doubly Linked List.
   head_ref --> pointer to head node pointer.
   del  -->  pointer to node to be deleted. */
void deleteNode(struct node **head_ref, struct node *del){
	// base case
	if(*head_ref == NULL || del == NULL){
		return;
	}
	
	// If node to be deleted is head node 
	if(*head_ref == del){
		// shift head to  del->next ,since current head will be deleted 
		*head_ref = del->next;
	}
	
	// if node to be deleted is NOT the last node
	if( del->next != NULL){
		// set the front's previous
    	del->next->prev = del->prev;
	}
	
	// if node to be deleted is NOT the first node
	if(del->prev != NULL){
		// set the back's next
		del->prev->next = del->next;	
	}
	
	// Finally, free the memory occupied by del
	free(del);

	return;
}

// This function prints contents of linked list starting from the given node
void printList(struct node *node)
{
    struct node *last;
    cout<<"\nTraversal in forward direction \n";
    while (node != NULL)
    {
        cout<<" "<< node->data;
        last = node;
        node = node->next;
    }
 
    cout<<"\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        cout<<" "<<last->data;
        last = last->prev;
    }
    
    return;
}

int main() {
    // your code goes here
    /* Start with the empty list */
    struct node* head = NULL;
    // Push 7 at the beginning. So linked list becomes 7->NULL
    push(&head, 7);
    // Push 1 at the beginning. So linked list becomes 1->7->NULL
    push(&head, 1);
    
    // Insert 8, after 7. So linked list becomes 1->7->8->NULL
    insertAfter(head->next, 8);
    
    // Append 4 at the end. So linked list becomes 1->7->8->4->NULL
    append(&head, 4);
    
    // Insert 2, before 1. So linked list becomes 2->1->7->8->4->NULL
    insertBefore(&head, 2);
    // Insert 3, before 1. So linked list becomes 2->3->1->7->8->4->NULL
    insertBefore(&(head->next), 3);
    
    // delete 2, So linked list becomes 3->1->7->8->4->NULL
    deleteNode(&head, head);  //delete first node
    // delete 1, So linked list becomes 3->7->8->4->NULL
    deleteNode(&head, head->next);  //delete middle node
     
    cout<<"Created DLL is: ";
    printList(head);
    
	return 0;
}
