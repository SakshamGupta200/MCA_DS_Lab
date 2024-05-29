#include<stdio.h>
#include<stdlib.h>

struct node
{
    int  data;
    struct node *next;
};

struct node *head = NULL;

void createlist();
void begininsert();
void endinsert();
void middleinsert();
void begindelete();
void middledelete();
void lastdelete();
void display();
void search();

int main()
{

    while (1)
    {
        int choice;
        printf("Choose an option to perform linked list operation : \n");
        printf("1. Create list : \n");
        printf("2. Insert at begning : \n");
        printf("3. Insert at specific position : \n");
        printf("4. Insert at last : \n");
        printf("5. Delete at begning : \n");
        printf("6. Delete at specific position : \n");
        printf("7. Delete at last : \n");
        printf("8. Search the element : \n");
        printf("9.  Display the elements : \n");
        printf("10. Exit : \n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            createlist();
            
            break;

            case 2:
            begininsert();
            
            break;

            case 3:
            middleinsert();
            
            break;

            case 4:
            endinsert() ;
            
            break;

            case 5:
            begindelete();
            
            break;
            
            case 6:
            middledelete();
            
            break;

            case 7:
            lastdelete() ;
            
            break;

            case 8:
            search();
            break;

            case 9:
            display();
            break;
            
            case 10:
            exit(1);
            break;

            default:
            printf("\n\t Invalid Choice !!! \n");
        }
    }
    return 0;
}

void createlist()
{
    if (head ==  NULL) 
    {
        int n;
        printf("\n Enter the number of nodes : ");
        scanf("%d", &n);

        if (n != 0)
        {
            int data;
            struct node *newnode;
            struct node *temp;
            newnode = malloc(sizeof(struct node));
            head = newnode;
            temp = head;
            for (int  i = 2; i <= n ; i++)
            {
                newnode = malloc(sizeof(struct node));
                temp -> next = newnode;
                printf("\n Enter number to be inserted : ");
                scanf( "%d" ,&data );
                newnode -> data = data;
                temp = temp -> next;
                
            }            
        }
        printf("\n Thw list is created\n : ");     
    }
    else
    {
        printf("The list already exists.\n");
    }    
}

void begininsert()
{

}
void endinsert()
{

}
void middleinsert()
{

}
void begindelete()
{

}
void middledelete()
{

}
void lastdelete()9
{

}
void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print.\n ");
    }
    else
    {
        printf("\n Printing values \n :");
        while (ptr != NULL)
        {
            printf("\t%d",ptr->data);
            ptr = ptr->next;
        }
        
    }
    
}
void search()
{

}