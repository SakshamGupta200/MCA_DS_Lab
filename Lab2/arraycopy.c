#include<stdio.h>

int main(){
    int n, i, arr[10],arr1[10];
    printf("Enter the number of elements you want in array: ");
    scanf("%d", &n);
    
    // Input elements into array
    printf("Enter the number :");
    for(i=0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    for (i = 0; i < n; i++)
    {
       arr1[i] = arr[i];
    }
    printf("First array is ");
    for(i=0;i<n;i++){
        printf("%d\t ",arr[i]);
    }
    printf("Copied array is :");

    for(i=0;i<n;i++){
        printf("%d\t ",arr1[i]);
    }
    return 0;
}