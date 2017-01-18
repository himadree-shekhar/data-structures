#include <iostream>
using namespace std;

/* Link list node */
struct node
{
    int data;
    struct node* next;
};

// This function rotates a linked list counter-clockwise or shift left and 
// updates the head. The function assumes that k is smaller 
// than size of linked list. It doesn't modify the list if 
// k is greater than or equal to size
void rotate(struct node **head_ref, int k){
	if(k==0)
		return;
		
	struct node *current = *head_ref;
	// current will either point to kth or NULL after this loop.
	for(int i = 1; i < k && current != NULL; i++ ){
		current = current->next;
	}
	
	if(current == NULL)
		return;
	
	// current points to kth node.	
	struct node *kthnode = current;	
	
	// current will point to last node after this loop
	while(current->next!= NULL){
		current = current->next;	
	}
	
	// Change next of last node to previous head
	current->next = *head_ref;
	
	// Change head to (k+1)th node
	*head_ref = kthnode->next;
	
	 // change next of kth node to NULL
	 kthnode->next = NULL;
	
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

void printList( struct node *head_ref){
	while(head_ref !=NULL){
		cout<<head_ref->data<<" ";	
		head_ref = head_ref->next;
	}
	cout<<endl;
}
int main() {
	// your code goes here
	/* Start with the empty list */
    struct node* head = NULL;
 
    // create a list 10->20->30->40->50->60
    for (int i = 60; i > 0; i -= 10)
        push(&head, i);
 
    cout<<"Given linked list:"<<endl;
    printList(head);
    rotate(&head, 4);
    
 	cout<<"Rotated linked list:"<<endl;
    printList(head);
	return 0;
}