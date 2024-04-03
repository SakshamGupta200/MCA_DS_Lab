#include<stdio.h>
void TOH(int n, char source, char aux,  char des) { 
    if (n > 0) {
        // Move n-1 disks from source A to target C  
        // through Target B  
        TOH(n - 1, source, des, aux);
        printf("Move disk %d from %c to %c\n", n, source, des); 
          
        TOH(n - 1, aux, source, des);  
    }   
}

int main(){
    int n;
    printf("Enter the number of rings :");
    scanf("%d",&n);
    TOH(n,'A','B','C');
    return 0;
}