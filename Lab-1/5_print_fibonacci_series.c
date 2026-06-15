#include<stdio.h>
#include<time.h>
int fibonacciSeries(int);
void main(){
    int num;
    clock_t st, en;
    printf("Enter a number :");
    scanf("%d", &num);
    st = clock();
    int fact = fibonacciSeries(num);
    en = clock();
    printf("Fibonacci series of %d is %d", num, fact);
    printf("\nTime taken: %f", ((double)(en - st)) / CLOCKS_PER_SEC);   
}

int fibonacciSeries(int n){
    if(n == 0 || n == 1){
        return 0;
    }
    else{
        return (fibonacciSeries(n-1) + fibonacciSeries(n-2));
    }
}
//// 0, 1, 1, 2, 3, 5, 8, 13, 21, .....
/// num = 5