#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *next;
};

struct node *head = NULL;

void createList();
void insertBegining();
void insertEnd();
void insertSpecificLocation();
void deleteBegining();
void deleteEnd();
void deleteSpecificLocation();
void count();
void display();


void main() {
    int choice;
    while(1){
        printf("1. Create List \n");
        printf("2. Insert at Begining \n");
        printf("3. Insert at Specified Location \n");
        printf("4. Insert at Tail \n");
        printf("5. Delete at Begining \n");
        printf("6. Delete at Specified Location \n");
        printf("7. Delete at Tail \n");
        printf("8. Count \n");
        printf("9. Dispaly \n");
        printf("10. Quit \n");
        
        printf("Enter your Choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
            {
                createList();
                break;
            }
            case 2:
            {
                insertBegining();
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
        newNode->data = item; // Link data field of newNode
        newNode->next = NULL; // Make sure new node points to NULL
        temp->next = newNode; // Link previous node with newNode
        temp = temp->next; // Make current node as previous node
    }
    display();
}


void insertBegining(){
    
    int data;
    printf("Enter the data of the node: ");
    scanf("%d", &data);
    
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    
    if(newNode == NULL){
        printf("Unable to allocate memory.");
        return;
    }
    else{
        newNode->data = data; // Link the data part
        temp = head;
        
		if(temp == NULL){
	        head = newNode;
	        head->next = NULL;
	        printf("Data Inserted at the Begining sucessfully \n");
	        display();
	        return;
        }
        newNode->next = head;
        head = newNode;
        printf("Data Inserted at the Begining sucessfully \n");
    }
    display();
}

void insertEnd(){
    
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    
    if(newNode == NULL){
        printf("Unable to allocate memory.");
        return;
    }
    else{
        int data;
        printf("Enter the data of the node: ");
        scanf("%d", &data);
        
        newNode->data = data; // Link the data part
        newNode->next = NULL;
        temp = head;
        
        if(temp == NULL){
            head = newNode;
            head->next = NULL;
            printf("Data Inserted at the END sucessfully\n");
            display();
            return;
        }
        // Traverse to the last node
        while(temp != NULL && temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode; // Link address part
        printf("Data Inserted at the END sucessfully\n");
    }
    display();
}


void insertSpecificLocation(){
    
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    
    if(newNode == NULL){
    printf("Unable to allocate memory.");
        return;
    }
    else{
        int data;
        printf("Enter the data of the node: ");
        scanf("%d", &data);
        
        int pos;
        printf("Enter the pos of the insertion: ");
        scanf("%d", &pos);
        
        newNode->data = data; // Link the data part
        temp = head;
        
        if(pos < 1){
            printf("Enter the position greater than 0 \n");
            return;
        }
        else if (temp == NULL && pos > 1){
            printf("Empty List! Please enter position of insertion as 1 \n");
            return;
        }
        else if(temp == NULL && pos == 1){
            head = newNode;
            head->next = NULL;
            printf("Data Inserted at the 1st position sucessfullygggggggg: \n");
            display();
            return;
        }
        else if(temp != NULL && pos == 1){
            newNode->next = head;
            head = newNode;
            printf("Data Inserted at the 1st position sucessfully: \n");
            display();
            return;
        }
        else{
            int i=1;
            while(temp->next != NULL){
                if(i < pos-1){
                temp = temp->next;
                i++;
                }
                else{
                    newNode->next = temp->next;
                    temp->next = newNode;
                    display();
                    return;
                }
            }
            if (temp->next == NULL && i == pos-1){
                newNode->next = temp->next;
                temp->next = newNode;
                display();
                return;
            }
            else{
                printf("Enter the pos of the insertion between 1 and %d: \n",i+1);
                display();
                return;
            }
        }
    }
}

void deleteBegining(){
    
    if(head == NULL){
        printf("List is Empty!!! \n");
        return;
    }
    else{
        struct node *temp = head;
        if(head->next == NULL){
            head = NULL;
            free(temp);
            printf(" List is now Empty!!!\n");
        }
        else{
            head = temp->next;
            free(temp);
            printf("Starting node deleted!!!\n");
            display();
        }
    }
}
   
   
   
void deleteEnd(){
    
    if(head == NULL){
        printf("List is Empty!!!\n");
        return;
    }
    else{
        struct node *temp1 = head,*temp2;
        if(head->next == NULL){
            head = NULL;
            printf("List is now Empty!!!\n");
            return;
        }
        else{
            while(temp1->next != NULL){
            temp2 = temp1;
            temp1 = temp1->next;
            }
            temp2->next = NULL;
            display();
        }
        free(temp1);
    }
}
    
    
    
void deleteSpecificLocation(){
    
    if(head == NULL){
        printf("List is Empty!!!\n");
        return;
    }
    else{
        int pos,i;
        printf("Enter the pos of the deletion: ");
        scanf("%d", &pos);
        
        struct node *temp = head;
        if(pos < 1){
            printf("Enter the position greater than 0\n");
            return;
        }
        else if(temp->next == NULL && pos == 1){
            head = NULL;
            free(temp);
            printf("List is now Empty!!!\n");
        }
        else if(temp->next == NULL && pos > 1){
            printf("Single Node only! Please enter position of deletion as 1 \n");
            return;
        }
        else if (temp->next != NULL && pos == 1){
            head = temp->next;
            free(temp);
            display();
            return;
        }
        else{
            i=1;
            while(temp->next != NULL){
                if(i < pos-1){
                temp = temp->next;
                i++;
                }
                else{
                    temp->next = temp->next->next;
                    display();
                    return;
                }
            }
            printf("Enter the pos of the insertion between 1 and %d: \n",i);
        }
    }
}


void display(){
    // Return if list is empty
    if(head == NULL){
        printf("List is empty. \n");
        return;
    }
    
    struct node *temp;
    temp = head;
    printf("[");
    
    while(temp != NULL) {
        printf("%d->", temp->data); // Print data of current node
        temp = temp->next; // Move to next node
    }
    printf("NULL]\n");
}


void count(){
    
    // Return if list is empty
    if(head == NULL){
        printf("List is empty. \n");
        return;
    }
    
    struct node *temp;
    temp = head;
    int c=0;
    
    while(temp != NULL){
        c++;
        temp = temp->next; // Move to next node
    }
    printf("Number of elemnts in the list are: %d \n",c);
}