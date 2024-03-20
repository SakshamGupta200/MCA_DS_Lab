#include<stdio.h>
int main(){
int arr[20], n, i,pos,value;
printf("Enter the number of elements you want to insert in array: ");
scanf("%d", &n);

for (i = 0; i < n; i++)
{
    scanf("%d",&arr[i]);
}

printf("Enter the position to insert  a new element: ");
scanf("%d", &pos);

printf("Enter the value :");
scanf("%d",&value);

if(pos > n || pos < 0){
    printf("\nInvalid Position\n");
}
for ( i = n; i >= pos-1; i--)
{
    /* code */
    arr[i] = arr[i-1];

}
arr[pos-1]=value;
n++;
printf("After inserting the element :");
for ( i = 0; i < n; i++)
{
    /* code */
    printf("%d\t",arr[i]);
}

// ************************ delete value ***********************
int pos1;
printf("\nEnter the position to be deleted : ");
scanf("%d",&pos1);
if(pos1 > n || pos1 < 0 ){
    printf("invalid position");

}
for ( i = n; i < pos1; i--)
{
    /* code */
    arr[i] = arr[i - 1];
    arr[pos1] = arr[i];
}
n--;
printf("After deleting the element :");
for ( i = 0; i < n; i++)
{
    /* code */
    printf("%d\t", arr[i]);
}


return 0;

}