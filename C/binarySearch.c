#include <stdio.h>
#include <stdlib.h>

int binarySearch(int a[],int l,int r,int x){
    int mid=(l+r)/2;
    while(r>=l) {
        if (a[mid] == x) {
            return mid;
        }

        if (a[mid] > x) {
            return binarySearch(a, l, mid - 1, x);
        }

        if (a[mid] < x) {
            return binarySearch(a, mid + 1, r, x);
        }
    }
    return -1;
}

int main() {

    int size,i,x;

    printf("Enter the number of elements ");   //size of array input from user
    scanf("%d",&size);

    int *a=(int*)calloc(size,sizeof(int));  //memory allocated for array dynamically

    printf("\nEnter the elements ina sorted order ") ;       //input of elements by the user
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }

    printf("Enter the element to be searched ");
    scanf("%d",&x);

    int pos= binarySearch(a,0,size,x);
    printf("Element was found at %d position ",pos+1);

    return 0;
}
