#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5  
int queue[MAXSIZE];
int front = -1;
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
        //printf("\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. First\n");
        printf("4. Last\n");
        printf("5. Count\n");
        printf("6. Display\n");
        printf("7. Quit\n");

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
                printf("Please enter a valid choice (1/2/3/4/5/6/7)\n\n");
                break;
            }
        }
    }
}

void enqueue() {
	
	int item;
    printf("\nEnter the element to be inserted in queue: ");
    scanf("%d",&item);
	
	if(isEmpty()){
		front = 0;  
		rear = 0;  
		queue[rear] = item;
	}
    else if(isFull()) {
        printf("\nCannot Insert the item -- Queue Overflow\n");
    } 
	else {
        rear = (rear + 1) % MAXSIZE;   
        queue[rear] = item;
    }
}


void dequeue(){
	
    if(isEmpty()) {
        printf("\nCannot delete elements from the queue -- Queue Underflow\n\n");
    } 
	else {
    	int data;
        data = queue[front];
        printf("Dequeued element is : %d\n", data);
        
        if(front == rear) {
            front = -1;
            rear = -1;
        } 
		else {
            front = (front + 1) % MAXSIZE;
        }
        display();
    }
}

void first() {
	
    if(isEmpty()) {
        printf("\nNo elements in the queue - Queue is Empty\n\n");
    } 
	else {
        printf("\nElement at the front is: %d\n\n", queue[front]);
    }
}

void last() {
	
    if(isEmpty()) {
        printf("\nNo elements in the queue - Queue is Empty\n\n");
    } 
	else {
        printf("Element at the rear is: %d\n\n", queue[rear]);
    }
}

void count(){
	
	int count = 0;
	if(isEmpty()) {
		printf("\n%d or No elements in the queue\n\n",count);
	} 
	else {
        count = (rear - front + MAXSIZE) % MAXSIZE + 1;
		printf("\nNumber of items in the queue is: %d\n\n",count);
	}
}

void display() {
    
    if(isEmpty()){  
        printf("\nCannot display any elements - Empty Queue\n\n"); 
    }  
    else {
	 
        int i = front;
        int j = rear;
		printf("\nElements in a Queue are :");
		
		if (front == rear) {
			printf("|%d", queue[i]);  
        }
        else if (front < rear){
        	for(i = front; i <= rear; i++){
        		printf("|%d", queue[i]);  
			}
		}
		else {
			for(i = front; i <= MAXSIZE-1; i++){
        		printf("|%d", queue[i]);  
			}
            for (i = 0; i <= rear; i++) {
                printf("|%d", queue[i]);
            }
		}			
		printf("|\n\n"); 
	}
}

int isEmpty() {
	
    if (front == -1 && rear == -1) {
        return 1;
    } 
	else {
        return 0;
    }
}

int isFull() {
	
    if ((rear + 1) % MAXSIZE == front) {
        return 1;
    } 
	else {
        return 0;
    }
}