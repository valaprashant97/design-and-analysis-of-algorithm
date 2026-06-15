// Program: Find Prime Factors of a Number using Recursion
// Author: vala prashant
// Date: 15/06/2026
// Description: 
#include<stdio.h>
#include<time.h>
int primeFectors(int);
void main(){
    clock_t start, end;
    int num;
    printf("Enter a number :");
    scanf("%d", &num);

    start = clock();
    int result = primeFectors(num);
    end = clock();

    printf("\nTime taken: %f", ((double)(end - start)) / CLOCKS_PER_SEC);
}
int primeFectors(int num){
    
}