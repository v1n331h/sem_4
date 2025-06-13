#include<stdio.h>
int max_value(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main(){
    int n,max,w[50],p[50],v[50][50],s[10]={0};
    printf("Enter the no. of items\n");
    scanf("%d",&n);

    printf("Enter the weight");
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);

    printf("Enter the profit\n");
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);

    printf("Enter the max capcaity\n");
    scanf("%d",&max);

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=max;j++)
        {
            if(i==0||j==0)
                v[i][j]=0;
            else if(j<w[i])
                v[i][j]=v[i-1][j];
            else
                v[i][j]=max_value(v[i-1][j], v[i-1][j-w[i]]+p[i]);
        }
    }

    printf("Table is \n");
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=max;j++)
        {
            printf("%d\t",v[i][j]);
        }
        printf("\n");
    }

    printf("Max profit is %d\n",v[n][max]);

    int i=n,j=max;
    while(i>0 && j>0)
    {
        if(v[i][j] == v[i-1][j])
            i--;
        else
        {
            s[i]=1;
            j=j-w[i];
            i=i-1;
        }
    }

    printf("Selected items are\n");
    for(int i=1;i<=n;i++)
    {
        if(s[i]==1)
        {
            printf("Item :%d\n",i);
        }
    }
}