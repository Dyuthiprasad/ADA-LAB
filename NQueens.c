#include <stdio.h>
#include <math.h>

#define MAX 20

int board[MAX];
int found = 0;

void printSolution(int n) {
    printf("One solution for %d-Queens:\n", n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    found = 1;
}

int isSafe(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (board[j] == i || fabs(board[j] - i) == fabs(j - k))
            return 0;
    }
    return 1;
}

void nQueens(int k, int n) {
    for (int i = 1; i <= n && !found; i++) {
        if (isSafe(k, i)) {
            board[k] = i;
            if (k == n)
                printSolution(n);
            else
                nQueens(k + 1, n);
        }
    }
}

int main() {
    int n;
    printf("Enter number of queens (N): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Please enter N between 1 and %d.\n", MAX);
        return 1;
    }

    nQueens(1, n);

    if (!found)
        printf("No solution exists for N = %d\n", n);

    return 0;
}
