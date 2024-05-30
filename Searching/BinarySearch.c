#include <stdio.h>
void main() 
{
     int i, beg, end, middle, n, search, a[100];
printf("Enter number of elements\n");
scanf("%d", &n);
for (i = 0;i < n; i++)
{
scanf("%d", &a[i]);
}
printf("Enter value to find\n");
scanf("%d", &search);
beg = 0; end =n-1;
middle = (beg+end)/2;
while (beg <end)
{ // Loop Start 
if (a[middle] < search) 
    beg= middle + 1;
else if (a[middle] == search)
{ 
    printf("%d found at location %d.\n", search, middle+1); 
    break; 
    } 
    else 
    end = middle - 1;
    middle = (beg +end)/2; 
} 
// Loop Close 
if (beg >= end) 
printf("Not found! %d isn't present in the list.\n", search); 
}