#include<stdio.h>
#include<stdlib.h>
#define max 30

int main() {
    int a, b, m, n;
    printf("\nMatrix Multiplication: ");
    printf("\nEnter the number of rows in first matrix: ");
    scanf("%d", &a);
    printf("\nEnter the number of columns in the second matrix: ");
    scanf("%d", &b);
    printf("\nEnter the number of rows in the second matrix: ");
    scanf("%d", &m);
    printf("\nEnter the number of columns in the second matrix: ");
    scanf("%d", &n);
    if(b!=m) {
        printf("\nInvalid size\n");
        exit(0);
    }
    printf("\nEnter the elements of the matrix 1: \n");
    int arr1[a][b], arr2[m][n], arr3[a][n], i, j, k;
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("\nEnter the elements of the matrix 2: \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }
    printf("\nProduct of the two matrix: \n");
    for (i = 0; i < a; i++) {
        for (j = 0; j < n; j++) {
            arr3[i][j] = 0;
            for (k = 0; k < m; k++) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }
    return 0;
}