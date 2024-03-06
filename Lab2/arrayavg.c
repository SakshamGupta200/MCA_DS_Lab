#include<stdio.h>

int main(){
    int n, i, arr[10],sum = 0, avg;
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
    avg  = sum / n;
    printf("Average of array elements are : %d",  avg);
    return 0;
}