#include <stdio.h>
#include <conio.h>

int find(int v, int parent[10]) {
    while (parent[v] != v) {
        v = parent[v];
    }
    return v;
}

void union1(int i, int j, int parent[10]) {
    if (i < j)
        parent[j] = i;
    else
        parent[i] = j;
}

void kruskal(int n, int a[10][10]) {
    int count = 0, k = 0, sum = 0;
    int i, j, u, v, parent[10], t[10][10];

    for (i = 0; i < n; i++)
        parent[i] = i;

    while (count != n - 1) {
        int min = 999;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (a[i][j] < min && a[i][j] != 0) {
                    min = a[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        i = find(u, parent);
        j = find(v, parent);

        if (i != j) {
            union1(i, j, parent);
            t[k][0] = u;
            t[k][1] = v;
            k++;
            count++;
            sum += a[u][v];
        }

        a[u][v] = a[v][u] = 999;
    }

    if (count == n - 1) {
        printf("Spanning tree:\n");
        for (i = 0; i < n - 1; i++) {
            printf("%d %d\n", t[i][0], t[i][1]);
        }
        printf("Cost of spanning tree = %d\n", sum);
    } else {
        printf("Spanning tree does not exist\n");
    }
}

void main() {
    int n, i, j, a[10][10];
    clrscr();
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    kruskal(n, a);
    getch();
}
