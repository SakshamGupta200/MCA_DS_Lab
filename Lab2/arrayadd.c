#include<stdio.h>

int main(){
    int n, i, arr[10],sum = 0;
    printf("Enter the number of elements you want in array: ");
    scanf("%d", &n);
    
    // Input elements into array
    printf("Enter the number :");
    for(i=0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    for (i = 0; i < n; i++)
    {
       sum = sum + arr[i];
    }
    printf("Additon of array elements are : %d",  sum);
    return 0;
}