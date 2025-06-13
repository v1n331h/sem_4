#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void print(int arr[],int size){
        for(int i=0; i<size; i++){
            printf("%d ",arr[i]);
        }
    printf("\n");
    }

void merge(int arr[], int low, int mid, int high,int size){
int b[size], i=low, j=mid+1, k=low;
    while(i<=mid && j<= high){
        if( arr[i]<arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
        }
    while( i<=mid){
            b[k++] = arr[i++];
        }
    while( j<=high){
        b[k++] = arr[j++];
        }
// in  ' l <= high ', <= is important
for(int l =low; l<=high; l++)
arr[l] = b[l];
}


void mergeSort( int arr[], int low, int high, int size){

if(low<high){
// this next line should always come after if condition above
int mid = (low+ high)/2;
mergeSort(arr, low, mid, size);
mergeSort(arr, mid+1, high,size);
merge(arr, low, mid, high, size);
    }
}

int main(){

int n;
clock_t start, end;
double time_taken;
printf("Enter the size of the array(no. of elements): \n");
scanf("%d",&n);
int a[n];

for(int i=0; i<n; i++){
    a[i] = rand() % 10000;
}

printf("Elements before Merge Sort: ");
print(a, n);

start = clock();
mergeSort(a, 0, n-1, n);
end = clock();

printf("\nElements  after Merge Sort: ");
print(a, n);

time_taken = (double)(end - start)/CLOCKS_PER_SEC*1000;
printf("Time taken to execute merge sort : %.3f ms", time_taken);

return 0;
}