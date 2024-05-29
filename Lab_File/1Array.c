#include <stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

int array[MAX_SIZE];
int size;

void traverse() {
    int i;
    printf("Array elements are: ");
    
    for (i = 0; i <= size-1; i++) {
        printf("%d ", array[i]);
    }
    
    printf("\n\n");
}

void insert(int value, int position) {
    int i;
    if (size >= MAX_SIZE) {
        printf("Array is full, insertion not possible\n");
        return;
    }
    if (position <= 0 || position > size) {
        printf("Invalid position, insertion not possible\n");
        return;
    }
    for (i = size; i >= position; i--) {
        array[i] = array[i-1];
    }
    array[position-1] = value;
    size++;
}

void delete(int position) {
    int i;
    if (position <= 0 || position > size) {
        printf("Invalid position, deletion not possible\n");
        return;
    }
    for (i = position-1; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
}

void update(int value, int position) {
    if (position <= 0 || position > size) {
        printf("Invalid position, updation not possible\n");
        return;
    }
    array[position-1] = value;
}


int main() {
    int choice, value, position;
 	    
    printf("Enter the total number of elements in array:");
    scanf("%d",&size);
    
    printf("Enter the elements of array\n");
    for(int i =0; i<= size-1; i++){
        scanf("%d",&array[i]);
    }
    printf("\n");
    
    while (1) {
        printf("1. Traverse\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Update\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                traverse();
                break;
            case 2:
                printf("Enter value and position: ");
                scanf("%d%d", &value, &position);
                
                insert(value, position);
                traverse();
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &position);
                delete(position);
                traverse();
                break;
            case 4:
                printf("Enter value and position: ");
                scanf("%d%d", &value, &position);
                update(value, position);
                traverse();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

