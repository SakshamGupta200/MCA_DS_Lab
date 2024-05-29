#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
  
int stack[MAXSIZE];
int top = -1;
   
void push();
void pop();
void peek();
void count();
void displayStack();
int isEmpty();
int isFull();

void main() {

	int choice;
	 
	while(1){
		
		printf("1. Push\t");
		printf("2. Pop\t");
		printf("3. Peek\t");
		printf("4. Count\t");
		printf("5. Dispaly\t");
		printf("6. Quit\n");

		printf("Enter your Choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
			{
                push();
				displayStack();			
				break;
			}
			case 2:
			{
				pop();
				displayStack();				
				break;
			}
			case 3:
			{
				peek();
				break;
			}
			case 4:
			{
				count();
				break;
			}
			case 5:
			{
				displayStack();
				break;
			}
			case 6:
			{
				exit(1);
			}
			default:
			{
				printf("\nPlease Enter a valid choice (1/2/3/4/5/6)\n");
                break;
			}
		}
	}
}


void push() {
	
    int item;
    
    if(isFull()) {
        printf("Stack Overflow\n");
    } 
	else {
        printf("Enter the item to be pushed: ");
        scanf("%d",&item);
        top = top + 1;   
        stack[top] = item;
    }
}

void pop() {
	
	int data;
	
	if(isEmpty()) {
		printf("\nCannot pop elements from the Stack - Stack is Empty - Stack Underflow\n");
	} else {
		data = stack[top];
		top = top - 1;
		printf("Popped Item is : %d\t", data);
	}
}

void peek() {
	
	if(isEmpty()) {
		printf("\nNo elements in the Stack - Stack is Empty - Stack Underflow");
	} 
	else {
		printf("\nItem at the top is: %d\t", stack[top]);
	}
}

void count(){
	
	int count;
	
	if(isEmpty()) {
		printf("\nNo elements in the Stack - Stack Underflow\n\n");
	} 
	else {
		count = top + 1;
		printf("\nNumber of items in the stack is: %d\t",count);
	}
}

void displayStack(){
	
	int i;
	
	if(isEmpty()) {
		printf("\nCannot Display Stack - No elements in the Stack - Stack Underflow\n\n");
	} 
	else {
		printf("\nStack Elements are:\t");
		for (i = top; i >= 0; i--){
			printf("|%d|\t",stack[i]);
		}
        printf("\n");
	} 
}

int isEmpty() {
	
	if(top == -1){
		return 1;
	}
   	else{
		return 0;
	}
}
   
int isFull() {
	if(top == MAXSIZE - 1){
		return 1;
    }
	else{
		return 0;
    }
}
