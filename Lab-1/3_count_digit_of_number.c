#include<stdio.h>
#include<time.h>
int countDigits(int);
void main(){
    clock_t start, end;
    int num;
    printf("Enter a number :");
    scanf("%d", &num);

    start = clock();
    int count = countDigits(num);
    end = clock();

    printf("Number of digits in %d is %d", num, count);
    printf("\nTime taken: %f", ((double)(end - start)) / CLOCKS_PER_SEC);
}
int countDigits(int num){
    if(num == 0){
        return 0;
    }
    else{
        return 1 + countDigits(num / 10);
    }
}