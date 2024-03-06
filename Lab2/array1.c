#include<stdio.h>

int main(){
    int n, i, arr[10];
    printf("Enter the number of elements you want in array: ");
    scanf("%d", &n);
    
    // Input elements into array
    for(i=0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}