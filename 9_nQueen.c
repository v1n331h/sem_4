#include<stdio.h>
#include<stdlib.h>

int count = 0 ;

void print(int n, int x[]){  //nx
    for (int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(x[i] == j){
                printf(" Q ");
            }else{
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int place(int i, int a, int x[10]){  // iax
    for(int j=1; j<a; j++){
        if (x[j] == i || (abs(x[j]-i) == abs(j-a))){
            return 0;
        }
    }
    return 1;    
}


void nqueen(int a, int n, int x[]){  // anx
    for(int i = 1; i<=n; i++){
        if(place( i, a, x)){
            x[a] = i;
            if(a==n){
                count++;
                printf("Solution: %d\n", count);
                print(n,x);
            }
            else{
            nqueen(a+1, n, x);
            }
        }
    }
}
int main(){
    int n, x[10];
    printf("Enter the no. of queens: ");
    scanf("%d", &n);
    nqueen(1, n,x);
    printf("Number of solutions: %d", count);
    return 0;
}