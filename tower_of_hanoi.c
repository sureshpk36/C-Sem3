#include <stdio.h>

void TOH(int n, int A, int B, int C) {
    if (n > 0) {
        TOH(n - 1, A, C, B);  // Move n-1 discs from A to B using C as auxiliary
        printf("Move a Disc from %d to %d\n", A, C);  // Move the nth disc from A to C
        TOH(n - 1, B, A, C);  // Move n-1 discs from B to C using A as auxiliary
    }
}

int main() {
    int n;
    printf("Enter the number of discs: ");
    scanf("%d", &n);
    TOH(n, 1, 2, 3);  // A = 1, B = 2, C = 3
    return 0;
}
