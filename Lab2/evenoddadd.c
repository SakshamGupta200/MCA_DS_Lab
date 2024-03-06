#include<stdio.h>

int main(){
    int n, i, arr[10],evensum = 0, oddsum =0;
    printf("Enter the number of elements you want in array: ");
    scanf("%d", &n);
    
    // Input elements into array
    printf("Enter the number :");
    for(i=0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    for (i = 0; i < n; i++)
    {
       if (arr[i] % 2 == 0)
       {
        evensum = evensum +  arr[i];
       }
       else
       {
        oddsum = oddsum + arr[i];
       }
       
       
    }
    printf("Additon of even elements in array are : %d",  evensum);
    printf("\n Additon of odd elements in array are : %d",  oddsum);
    return 0;
}