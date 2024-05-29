#include<stdio.h>
#include <stdlib.h>

struct node{
	struct node *prev;
	int data;
    struct node  *next;
};

struct node *head = NULL;


void createList();
void insertBeginning();
void insertEnd();
void insertSpecificLocation();
void deleteBegining();
void deleteEnd();
void deleteSpecificLocation();
void count();
void display();



void main()
{
   int choice;
   while(1)
   {
      	printf("1. Create List \n");
        printf("2. Insert at Begining \n");
        printf("3. Insert at Specified Location \n");
        printf("4. Insert at End \n");
        printf("5. Delete at Begining \n");
        printf("6. Delete at Specified Location \n");
        printf("7. Delete at End \n");
        printf("8. Count \n");
        printf("9. Traverse or Dispaly \n");
        printf("10. Quit \n");
        
        printf("\nEnter your Choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
            {
                createList();
                break;
            }
            case 2:
            {
                insertBeginning();
                break;
            }
            case 3:
            {
                insertSpecificLocation();
                break;
            }
            case 4:
            {
                insertEnd();
                break;
            }
            case 5:
            {
                deleteBegining();
                break;
            }
            case 6:
            {
                deleteSpecificLocation();
                break;
            }
            case 7:
            {
                deleteEnd();
                break;
            }
            case 8:
            {
                count();
                break;
            }
            case 9:
            {
                display();
                break;
            }
            case 10:
            {
                exit(1);
            }
            default:
            {
                printf("Please enter a valid choice (1/2/3/4/5/6/7) \n");
                break;
            }
        }
    }
}


void createList(){
    
    int n;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    
    struct node *newNode, *temp;
    int item, i;
    
    head = (struct node *)malloc(sizeof(struct node));
    
    // Terminate if memory not allocated
    if(head == NULL){
        printf("Unable to allocate memory.");
        exit(0);
    }
    
    // Input data of node from the user
    printf("Enter the data of node 1: ");
    scanf("%d", &item);
    
    head->data = item; // Link data field with data
    head->next = NULL; // Link address field to NULL
    head->prev = NULL;
    // Create n - 1 nodes and add to list
    temp = head;
    
    for(i=2; i<=n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        
        /* If memory is not allocated for newNode */
        if(newNode == NULL){
            printf("Unable to allocate memory.");
            break;
        }
        
        printf("Enter the data of node %d: ", i);
        scanf("%d", &item);
        
        newNode->next = NULL;	// Make sure new node points to NULL
        newNode->data = item;	// Link data field of newNode
        newNode->prev = temp;	// new node points to prev node
        
        temp->next = newNode;	// Link prev node with newNode
        temp = temp->next;		// Make current node as prev node
    }
    display();
}

void insertBeginning()
{    
	struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
	
	if(newNode == NULL){
        printf("Unable to allocate memory\n");
        return;
    }
    else{
    	int value;
	    printf("Enter the data of the node: ");
	    scanf("%d", &value);
	    
    	newNode -> data = value;
		newNode -> prev = NULL;
		
		if(head == NULL){
		   newNode -> next = NULL;
		   head = newNode;
		}
		else
		{
		   newNode->next = head;
		   head = newNode;
		}
		printf("\nData Inserted at the Begining sucessfully\n\n");
	}
	display();
}

void insertEnd()
{
	struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
	
	if(newNode == NULL){
        printf("Unable to allocate memory.");
        return;
    }
    else{
    	
    	int value;
	    printf("Enter the data of the node: ");
	    scanf("%d", &value);
	    
	    newNode->data = value;		// Link the data part
	    newNode -> next = NULL;
	    
		if(head == NULL){
			newNode -> prev = NULL;
			head = newNode;
		}
		else{
			struct node *temp = head;
			
			// Traverse to the last node
			while(temp -> next != NULL){
				temp = temp -> next;
			}
			temp->next = newNode;
			newNode->prev = temp;
		}
		printf("Data Inserted at the END sucessfully\n");
	}
	display(); 
}


void insertSpecificLocation()
{
	struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    
    if(newNode == NULL){
    	printf("Unable to allocate memory.");
        return;
    }
    else{
		struct node *temp1 = head, *temp2;
        
        int pos;
		printf("Enter the pos of the insertion: ");
		scanf("%d", &pos);
        
		if(pos < 1){
        	printf("Enter the position greater than 0 \n");
        	return;
        }
        else if (head == NULL && pos > 1){
            printf("Empty List! Please enter position of insertion as 1 \n");
            return;
        }
        else if((head == NULL || head != NULL) && pos == 1){
            insertBeginning();
        }
		else{
			int i=1;
			
            while(temp1->next != NULL){
                if(i < pos-1){
	                temp1 = temp1->next;
	                i++;
                }
                else{
                	int value;
		        	printf("Enter the data of the node: ");
		        	scanf("%d", &value);
                	newNode->data = value; // Link the data part
                	
                	temp2 = temp1->next;
					temp1 -> next = newNode;
					newNode -> prev = temp1;
					newNode -> next = temp2;
					temp2 -> prev = newNode;
                    display();
                    return;
                }
            }
            if (temp1->next == NULL && i == pos-1){
                insertEnd();
            }
            else{
                printf("Enter the pos of the insertion between 1 and %d: \n",i+1);
                display();
                return;
            }
		}
	}
}


void deleteBegining()
{
	if(head == NULL){
		printf("\nList is Empty!!! Deletion not possible!!!\n\n");
	}
	else
	{
		struct node *temp = head;
		if(temp -> prev == temp -> next)
		{
			head = NULL;
			free(temp);
			printf("\nList is now Empty!!!\n\n");
		}
		else{
			head = temp -> next;
			head -> prev = NULL;
			free(temp);
			printf("\nStarting node deleted!!!\n\n");
            display();
		}
	}
}

void deleteEnd()
{
	if(head == NULL){
		printf("\nList is Empty!!! Deletion not possible!!!\n\n");
	}
	else
	{
		struct node *temp = head;
		if(temp -> prev == temp -> next)
		{
			head = NULL;
			free(temp);
			printf("\nList is now Empty!!!\n\n");
            return;
		}
		else{
			while(temp -> next != NULL){
				temp = temp -> next;
			}
			temp -> prev -> next = NULL;
			free(temp);
			display();
		}
	}
}


void deleteSpecificLocation()
{
	if(head == NULL){
		printf("List is Empty!!! Deletion not possible!!!\n\n");
	}
	else
	{
		int pos,i;
        printf("Enter the pos of the deletion: ");
        scanf("%d", &pos);
        
        if(pos < 1){
            printf("Enter the position greater than 0\n\n");
            return;
        }
        else if(head->next == NULL && pos > 1){
            printf("Single Node only! Please enter position of deletion as 1\n\n");
            return;
        }
        else if((head->next == NULL || head->next != NULL) && pos == 1){
            deleteBegining();
        }
        else{
            i=1;
            struct node *temp = head,*temp2;
            
            while(temp->next->next != NULL){
                if(i < pos-1){
	                temp = temp->next;
	                i++;
                }
                else{
                	temp2 = temp->next;
                    temp->next = temp2->next;
                    temp2->next->prev = temp;
                    display();
                    return;
                }
            }
            
            if (temp->next->next == NULL && i == pos-1){
            	deleteEnd();
			}
			else{
				printf("Wrong Location! Enter the pos of the insertion between 1 and %d: \n\n",i);
				display();
                return;
			}
        }
	}
}


void display()
{
   if(head == NULL){
		printf("\nDoubly Linked List is Empty!!!\n\n");
   }
   else
   {
		struct node *temp = head;
		printf("\nDoubly Linked List elements are: \n\n");
		printf("NULL <--- ");
		
		while(temp->next != NULL){
			printf("%d <===> ",temp->data);		// Print data of current node
			temp = temp->next;						// Move to next node
		}
		printf("%d ---> NULL\n\n", temp->data);
   }
}


void count(){
    
    // Return if list is empty
    if(head == NULL){
        printf("List is empty. \n\n");
        return;
    }
    
    struct node *temp;
    temp = head;
    int c=0;
    
    while(temp != NULL){
        c++;
        temp = temp->next; // Move to next node
    }
    printf("Number of elemnts in the list are: %d \n\n",c);
}