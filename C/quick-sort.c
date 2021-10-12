#include <stdio.h>
#include<stdlib.h>

void swap(int a[],int v1,int v2){
    int temp=a[v1];
    a[v1]=a[v2];
    a[v2]=temp;
}

int partition(int a[],int l,int h){
    int pivot=a[l];
    int i=l;int j=h;
    while(i<j) {
        while (a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;


        if (i < j)
            swap(a, i, j);
    }

    swap(a,j,l);
    return j;


}
void quickSort(int a[],int l,int h){
    if(l<h){
        int pivot=partition(a,l,h);
        quickSort(a,l,pivot);
        quickSort(a,pivot+1,h);

    }
}




int main(){
    int size,i;

    printf("Enter the number of elements ");   //size of array input from user
    scanf("%d",&size);

    int *a=(int*)calloc(size,sizeof(int));  //memory allocated for array dynamically

    printf("\nEnter the elements ") ;       //input of elements by the user
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }

    quickSort(a,0,size-1);

    printf("\nThe sorted array is ");
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }


    return 0;
}