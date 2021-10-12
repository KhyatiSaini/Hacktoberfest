#include <stdio.h>
#include <stdlib.h>

void merge(int a[],int low,int m,int high){           //function to merge
    int i,j,k;
    int s1=m-low+1;
    int s2=high-m;

    int l[s1],r[s2];

    for(i=0;i<s1;i++){
        l[i]=a[low+i];
    }

    for(j=0;j<s2;j++){
        r[j]=a[m+1+j];
    }

    i=0;j=0;k=low;

    while(i<s1 && j<s2){
        if(l[i]<=r[j]){
            a[k]=l[i];
            i++;
        }

        else{
            a[k]=r[j];
            j++;
        }

        k++;
    }

    while(i<s1){
        a[k]=l[i];
        i++;
        k++;
    }

    while(j<s2){
        a[k]=r[j];
        j++;
        k++;
    }

}


void mergeSort(int a[],int low,int high){
    if(low<high){
        int m= (low+high)/2;

        mergeSort(a,low,m);
        mergeSort(a,m+1,high);

        merge(a,low,m,high);
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

    mergeSort(a,0,size-1);

    printf("\nThe sorted array is ");
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }


    return 0;
}
