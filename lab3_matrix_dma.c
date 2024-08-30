#include <stdio.h>
#include <stdlib.h>

int main() {
    int **mat1, **mat2, **result;
    int i, j, k, r1, c1, r2, c2;

    printf("Enter the number of rows and columns for Matrix 1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the number of rows and columns for Matrix 2: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Invalid order of matrices for multiplication.\n");
        return 1;
    }

    mat1 = (int **)malloc(r1 * sizeof(int *));
    mat2 = (int **)malloc(r2 * sizeof(int *));
    result = (int **)calloc(r1, sizeof(int *));

    for (i = 0; i < r1; i++) {
        mat1[i] = (int *)malloc(c1 * sizeof(int));
        result[i] = (int *)calloc(c2, sizeof(int));
    }

    for (i = 0; i < r2; i++)
        mat2[i] = (int *)malloc(c2 * sizeof(int));

    printf("Enter elements for Matrix 1:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements for Matrix 2:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("Matrix Multiplication Result:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    free(mat1);
    free(mat2);
    free(result);

    return 0;
}
