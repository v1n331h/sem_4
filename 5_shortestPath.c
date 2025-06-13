// shortest path-> baseball game -> dijkstra's
#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

int find_min_vertex(int n, int distance[], int visited[]) {
    int min_vertex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && (min_vertex == -1 || distance[i] < distance[min_vertex])) {
            min_vertex = i;
        }
    }
    return min_vertex;
}

int main() {
    int n, source, dest;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_VERTICES) {
        printf("Invalid number of vertices. Must be between 1 and %d.\n", MAX_VERTICES);
        return 1;
    }

    printf("\nEnter the adjacency matrix (use 0 for no connection):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Distance from %d to %d: ", i + 1, j + 1);
            scanf("%d", &graph[i][j]);
            
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    printf("\nEnter source vertex (1-%d): ", n);
    scanf("%d", &source);
    source--;

    printf("Enter destination vertex (1-%d): ", n);
    scanf("%d", &dest);
    dest--;

    if (source < 0 || source >= n || dest < 0 || dest >= n) {
        printf("Invalid source or destination vertex.\n");
        return 1;
    }

    int distance[n], visited[n], parent[n];
    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    distance[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = find_min_vertex(n, distance, visited);
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF && 
                distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    if (distance[dest] == INF) {
        printf("\nNo path exists between %d and %d\n", source + 1, dest + 1);
    } else {
        printf("\nShortest path from %d to %d:\n", source + 1, dest + 1);
        
        // Store path in reverse order
        int path[MAX_VERTICES];
        int current = dest;
        int path_length = 0;
        
        while (current != -1) {
            path[path_length++] = current + 1; // Convert to 1-based
            current = parent[current];
        }
        
        // Print path in correct order
        for (int i = path_length - 1; i >= 0; i--) {
            printf("%d", path[i]);
            if (i > 0) printf(" -> ");
        }
        
        printf("\nTotal distance: %d\n", distance[dest]);
    }

    return 0;
}