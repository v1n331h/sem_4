#include <stdio.h>

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int adj[n][n]; 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("Is there an edge from vertex %d to %d? (1/0): ", i, j);
            scanf("%d", &adj[i-1][j-1]); // using 0-based indexing
        }
    }
    // Warshall's algorithm for transitive closure
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
            }
        }
    }
    // Print transitive closure matrix
    printf("\nTransitive Closure:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j == 0) {
                printf("%d: ", i+1);
            }
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    } 
    return 0;
}