#include <stdio.h>
#include <time.h>
// Time Complexity of Bubble Sort
// 	           1k	       10k	      100k
// best	    0.001000s   0.116000s	11.031000s
// average	0.002000s	0.325000s	35.031000s
// worst	0.004000s	0.336000s	22.031000s

int main() {
    FILE *fp;
    int n, i, j, temp;
    clock_t st, en;

    fp = fopen("worst_100k.txt", "r");
    n = 100000; // Assuming the file contains 100,000 integers
    int arr[n];
    for (i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    st = clock();
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    en = clock();

    // printf("Sorted Data:\n");
    // for (i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    printf("Time taken: %f seconds\n", ((double)(en - st)) / CLOCKS_PER_SEC);
    return 0;
}

