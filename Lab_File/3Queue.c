#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5    
int queue[MAXSIZE];
int rear = -1;
   
void enqueue();
void dequeue();
void first();
void last();
void count();
void display();
int isEmpty();
int isFull();

void main() {

	int choice;   
	while(1){
	    //printf("\t");
		printf("1. Enqueue\t");
		printf("2. Dequeue\t");
		printf("3. First\t");
		printf("4. Last\t");
        printf("5. Count\t");
		printf("6. Dispaly\t");
		printf("7. Quit\t");

		printf("\nEnter your Choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
			{
                enqueue();
				display();				
				break;
			}
			case 2:
			{
				dequeue();				
				break;
			}
			case 3:
			{
				first();
				break;
			}
            case 4:
			{
				last();
				break;
			}
			case 5:
			{
				count();
				break;
			}
			case 6:
			{
				display();
				break;
			}
			case 7:
			{
				exit(1);
			}
			default:
			{
				printf("Please enter a valid choice (1/2/3/4/5/6/7)\n");
                break;
			}
		}
	}
}

void enqueue() {
    int item;
    if(isFull()) {
        printf("Queue Overflow\n");
    } else {
        printf("\nEnter the element to be inserted in queue: ");
        scanf("%d",&item);
        rear = rear + 1;   
        queue[rear] = item;
    }
}

void dequeue() {
	int data;
	if(isEmpty()) {
		printf("\nCannot delete elements from the queue - Queue is Empty - Queue Underflow\n");
	} else {
		data = queue[0];
		printf("Dequeue element is : %d\t", data);
        int i;
        for (i = 0; i < rear; i++)    //shifting the elements to the front in queue
        {
            queue[i] = queue[i+1];
        }
        rear = rear - 1;
        display();
	}
}

void first() {
	if(isEmpty()) {
		printf("\tNo elements in the queue - Queue is Empty - Queue Underflow\t\t");
	} else {
		printf("\tElement at the front is: %d\t\t", queue[0]);
	}
}

void last() {
	if(isEmpty()) {
		printf("\nNo elements in the queue - Queue is Empty - Queue Underflow\t\t");
	} else {
		printf("Element at the back is: %d\t", queue[rear]);
	}
}

void count(){
	int count;
	if(isEmpty()) {
		printf("\nNo elements in the queue - Queue Underflow\t");
	} else {
		count = rear + 1;
		printf("\nNumber of items in the queue is: %d\t",count);
	}
}

void display(){
	if(isEmpty()) {
		printf("\tCannot display elements in the queue - Queue Underflow\t\t");
	} else {
        int i;
		printf("\nQueue Elements are:\n");
		for (i=0; i<=rear; i++){
			printf("|%d",queue[i]);
		}
        printf("|\n");
	} 
}

int isEmpty() {
	if(rear == -1){
		return 1;
	}
   	else{
		return 0;
	}
}
   
int isFull() {
	if(rear == MAXSIZE - 1){
		return 1;
    }
	else{
		return 0;
    }
}
