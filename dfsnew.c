// DFS Algorithm
#include <stdio.h>

int a[20][20], visited[20], n;

void dfs(int s) {
    printf("%d", s + 1);
    visited[s] = 1;

    for (int j = 0; j < n; j++) {
        if (!visited[j] && a[s][j] == 1) {
            printf("-->");
            dfs(j);
        }
    }
}

int isconnected() {
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            return 0;
    }
    return 1;
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS traversal starting from node 1: ");
    dfs(0);

    if (isconnected())
        printf("\nGraph is connected\n");
    else
        printf("\nGraph is not connected\n");

    return 0;
}
