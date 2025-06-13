#include<stdio.h>

int main(){
    int n, i, j, a[50][50], min, minC, u, v, ne = 0, visited[50] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    visited[0] = 1; // Start from the first vertex
    while(ne != n-1){
        min = 999;
        for(i =0; i<n; i++){
            if(visited[i]){
                for(j = 0; j<n; j++){
                    if(!visited[j] && a[i][j]<min){
                        min = a[i][j];
                        u= i;
                        v = j;
                    }
                }
            }
        }
        minC +=min;
        printf("Edge%d --> %d cost= %d\n", u,v,min);
        ne+=1;
        visited[v] = 1;
    }
    printf("Minimum cost = %d\n", minC);
    return 0;
}