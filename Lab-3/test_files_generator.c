#include<stdio.h>
#include<stdlib.h>
void main(){
    int a;
    printf("Enter a number :");
    scanf("%d", &a);

    // for best case time complexity
    FILE *file = fopen("best_100k.txt", "w");
    for(int i=0; i<a; i++){
        fprintf(file, "%d\n", i);
    }
    fclose(file);

    // for worst case time complexity
    FILE *file2 = fopen("worst_100k.txt", "w");
    for(int i=a-1; i>=0; i--){
        fprintf(file2, "%d\n", i);
    }
    fclose(file2);

    // for average case time complexity
    FILE *file3 = fopen("average_100k.txt", "w");
    for(int i=0; i<a; i++){
        fprintf(file3, "%d\n", rand() % a);
    }
    fclose(file3);
}