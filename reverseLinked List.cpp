#include <iostream>
using namespace std;
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};

static void reverse(struct node** head_ref){
	struct node* prev = NULL;
	// current starts from head node
	struct node* current = *head_ref;
	struct node* next;
	
	while(current != NULL){
		//next is now pointing to current's next.
		next = current->next;
		/* 
		  -> <- like loop current's next points to previous node
		        and previous node points to current node.
		 */
		current->next = prev;
		prev = current;
		/*after existing current referred by previous node, 
		  new current node will be next node.
		*/
		current = next;
	}
	//the last previous node willbe head for reverseLinked List
	*head_ref = prev;
}
/* Function to push a node */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
            
    /* put in the data  */
    new_node->data  = new_data;
                
    /* link the old list off the new node */
    new_node->next = (*head_ref);    
        
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
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
   
     push(&head, 20);
     push(&head, 4);
     push(&head, 15); 
     push(&head, 85);      
     
     cout<<"Given linked list"<<endl;
     printList(head);    
     reverse(&head); 
     cout<<"Reversed linked list"<<endl;
     printList(head);    
     getchar();
	return 0;
}