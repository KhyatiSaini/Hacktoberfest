#include <stdio.h>
#include <stdlib.h>

void difference(int a[],int b[],int m,int n){
    int i=0; int j=0;
    while(i<m&&j<n){
        if(a[i]<b[j]){
            printf("%d ",a[i]);
            i++;
        }

        else if(b[j]<a[i]){
            printf("%d ",b[j]);
            j++;
        }

        else{
            i++;
            j++;
        }

    }

    if(m>n) {

        while (i < m) {
            printf("%d ", a[i]);
            i++;
        }
    }

    else if(n>m) {

        while (j < n) {
            printf("%d ", b[j]);
            j++;
        }
    }
}

int main() {
//    int a[]={1,2,3,4,5,6,7};
//    int b[]={4,5,6,8,9};
//    int m=sizeof(a)/sizeof(int);
//    int n=sizeof(b)/sizeof(int);

    int m,i,n;

    printf("Enter the number of elements for set 1 ");   //size of array input from user
    scanf("%d",&m);

    int *a=(int*)calloc(m,sizeof(int));  //memory allocated for array dynamically

    printf("\nEnter the elements for set 1 ") ;       //input of elements by the user
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }

    printf("Enter the number of elements for set 2 ");   //size of array input from user
    scanf("%d",&n);

    int *b=(int*)calloc(n,sizeof(int));  //memory allocated for array dynamically

    printf("\nEnter the elements for set 2 ") ;       //input of elements by the user
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
    }

    difference(a,b,m,n);
    return 0;
}
