#include<stdio.h>

int findParent(int x, int parent[]){
    if ( x!= parent[x]){
        parent[x] = findParent( parent[x], parent);
    }
    return parent[x];
}

int main(){
    int a[50][50], i, j, n, min, minC = 0, u, v, aa,bb,ne = 0,parent[10];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 0; i < n; i++){
        parent[i] = i;
    }

    while(ne!=n){
        min = 999;
        for(i = 0; i<n; i++){
            for(j= 0; j<n; j++){
                if( a[i][j] < min && i!=j)
                {
                    min = a[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        aa = findParent(u, parent);
        bb = findParent(v, parent);
        parent[bb] = aa;

        if( aa!=bb){
            printf("Edge%d --> %d, cost: %d\n", u,v, min);
            minC += min;
        }
        ne+=1;
        a[u][v] = a[v][u] = 999;
    }
    printf("\nMinimum cost: %d", minC);
}