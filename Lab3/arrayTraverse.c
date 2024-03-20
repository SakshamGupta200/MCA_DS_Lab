#include<stdio.h>

void traverse(int arr[], int n)
{
int i;

for ( i = 0; i < n; i++)
{
    printf("%d\t",arr[i]);
}
}



int main(){
int arr[20], n, i;
printf("Enter the number of elements you want to insert in array: ");
scanf("%d", &n);

for (i = 0; i < n; i++)
{
    scanf("%d",&arr[i]);
}
traverse(arr,n);
return 0;

}