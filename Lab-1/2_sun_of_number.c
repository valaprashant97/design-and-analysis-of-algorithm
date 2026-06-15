#include<stdio.h>
#include<time.h>
int sumOfNumber(int);
int sumNumber(int);

void main(){
    clock_t start, end, st, en;
    int size;
    printf("Enter a number :");
    scanf("%d", &size);

    start = clock();
    int sum0 = sumOfNumber(size);
    end = clock();

    st = clock();
    int sum1 = sumNumber(size);
    en = clock();


    printf("Sum of first %d natural numbers is %d using recursion", size, sum0);
    printf("\nTime taken: %f", ((double)(end - start)) / CLOCKS_PER_SEC);
    printf("\nSum of first %d natural numbers is %d using iteration", size, sum1);
    printf("\nTime taken: %f", ((double)(en - st)) / CLOCKS_PER_SEC);
}
int sumOfNumber(int size){
    if(size == 0){
        return 0;
    }
    else{
        return size + sumOfNumber(size - 1);
    }
}

int sumNumber(int size){
    int sum = 0;
    for(int i = 1; i <= size; i++){
        sum += i;
    }
    return sum;
}
// output
// Enter a number :10
// Sum of first 10 natural numbers is 55 using recursion
// Time taken: 0.000002
// Sum of first 10 natural numbers is 55 using iteration
// Time taken: 0.000001