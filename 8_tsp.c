#include <stdio.h>
#define MAX 999

int n, a[20][20], source, visited[20], tempPath[20], bestPath[20];
int mincost = MAX;

void tsp(int src, int count, int currCost) {
    if (count == n && a[src][source]) { // checks for hamiltonian cycle
        int totalCost = currCost + a[src][source];
        if (totalCost < mincost) {
            mincost = totalCost;
            for (int i = 1; i <= n; i++) {
                bestPath[i] = tempPath[i];
            }
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && a[src][i]) {
            visited[i] = 1;
            tempPath[count + 1] = i;
            tsp(i, count + 1, currCost + a[src][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    printf("Enter the number of holes:\n");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter the source:\n");
    scanf("%d", &source);

    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    visited[source] = 1;
    tempPath[1] = source;

    tsp(source, 1, 0);

    printf("The minimum cost is %d\n", mincost);
    printf("Path: ");
    for (int i = 1; i <= n; i++)
        printf("%d -> ", bestPath[i]);
    printf("%d\n", source);  // return to source

    return 0;
}