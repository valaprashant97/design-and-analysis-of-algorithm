#include<stdio.h>
#include<time.h>
int calculatePower(int, int);
void main(){
    clock_t start, end;
    int base, exponent;
    printf("Enter the base :");
    scanf("%d", &base);
    printf("Enter the exponent :");
    scanf("%d", &exponent);

    start = clock();
    int power = calculatePower(base, exponent);
    end = clock();

    printf("%d raised to the power of %d is %d", base, exponent, power);
    printf("\nTime taken: %f", ((double)(end - start)) / CLOCKS_PER_SEC);
}
int calculatePower(int base, int exponent){
    if(exponent == 0){
        return 1;
    }
    else{
        return base * calculatePower(base, exponent - 1);
    }
}