#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

void push();
void pop();
void peek();
void display();
void count();
int isEmpty();
int isFull();

int top = -1 ;
int stack[SIZE];
int main(){
    int choice;
    while (1)
    {
    
    printf("1. Push \n2. Pop \n3. Peek \n4. Display \n5. Count \n6. Exit \n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
        switch(choice)  
        {
        case 1: 
            push(); 
            break;
        case 2: 
            pop();
            break;
        case 3:
            peek();
            break;
        case 4: 
            display(); 
            break; 
        case 5:
            count();
            break;
        case 6:
            exit(0);
        default:
        printf("\nInvalid Input!\n");
        }
    }
    return 0;
}
void push(){
    int item;
    if(top == SIZE - 1){
        printf("Stack overflow \n ");
    }
    else{
        printf("Enter the items :");
        scanf("%d",&item);
        top = top + 1;
        stack[top] = item;
    }
}
void pop(){
    if(top == -1){
        printf("Stack underflow \n ");
    }
    else
    {
         printf("\nPopped element: %d", stack[top]);
        top = top - 1;
    }
}

void display(){
    int i;
    if(top == -1){
        printf("Stack Underflow\n ");
    }
    else
    {
        for(i = 0; i <= top; i++){
            printf("%d\t",stack[i]);
        }
        printf("\n");
    }
}
void peek(){}
void count(){}
int isEmpty(){}
int isFull(){}