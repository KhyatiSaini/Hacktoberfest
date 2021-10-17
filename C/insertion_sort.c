#include <conio.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n, current,j=0,*arr;
    printf("input n\n");
   scanf("%d",&n);
    
    arr = (int*)calloc(n,sizeof(int));  
    //dynamic memory allocation for arr

     printf("Input array\n");
    for (int i = 0; i < n; i++)
    {
       scanf("%d",&arr[i]);
    }
     // elements are stored in "arr" array
      
    for (int i = 1; i < n; i++)  // loop will run n-1 times
    { 
       current = arr[i]; // ith element of arr will be stored in current variable
    for ( j=i-1; arr[j] > current && j >= 0 ; j--){
      
// j will start with i-1 and when both the conditions are true then
// jth element will be coppied at j+1 th position

        arr[j+1]=arr[j];
        
    }
    
    arr[j+1]= current;
    }
    

    // below , final array after sorting is printed
     printf("Array after sorting is :\n");
    for(int i=0;i<n;i++)
    {
   
    printf("%d ", arr[i]);
    }
    return 0;
}