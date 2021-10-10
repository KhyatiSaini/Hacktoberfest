#include <stdio.h>
#include<stdlib.h>

void swapper(int *p1,int *p2){      //function to perform swapping
    int temp= *p1;
    *p1=*p2;
    *p2=temp;
}

void bubbleSort(int a[],int size){     //function to perform bubble sort
    int i,j;

    for(int i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(a[j]>a[j+1])
                swapper(&a[j],&a[j+1]);
        }
    }
}

void display(int a[],int size){
    int i;                                             //function to display the sorted array
    printf("\nThe sorted array is ");
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
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

    bubbleSort(a,size);

    display(a,size);


    return 0;
}
