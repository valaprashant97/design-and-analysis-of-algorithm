#include<stdio.h>
#include<time.h>
int fact_num(int);
void main(){
    int num;
    clock_t st, en;
    printf("Enter a number :");
    scanf("%d", &num);
    st = clock();
    int fact = fact_num(num);
    en = clock();
    printf("Factorial of %d is %d", num, fact);
    printf("\nTime taken: %f", ((double)(en - st)) / CLOCKS_PER_SEC);   
}

int fact_num(int n){
    if(n==0 || n==1)
        return 1;
    else
        return n * fact_num(n-1);
}

// cd .\Lab-1
// gcc hello.c -o hello.exe
// .\hello.exe