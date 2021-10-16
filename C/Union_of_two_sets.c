//---------------- program for calculating union of any two given sets ------------


#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

void sort(int *arr ,int n);
void DelDublicate(int *arr, int k);
int finalArray[30]={0};

//--------------------------- main function ----------------------------------

int main()
{  
 int n1=0,n2=0;
    int*a1=NULL,*a2=NULL, a3[50]={0};
     int  i, j, k = 0, i1,j1=0;
printf("Input number of elements in set A \n");
scanf("%d",&n1);

    
    
    a1 = (int*)malloc(n1*sizeof(int)); 
    //dynamic memory allocation for set A
  

   
    printf("input elements of set A \n");

    for (i = 0; i < n1; i++)
    {
        scanf("%d", &a1[i]);
    }
     
    sort(a1,n1);
    //sort function will sort the elements of set A


    printf("Input number of elements in set B \n");
    scanf("%d",&n2);

    a2 = (int*)malloc(n2*sizeof(int));
    //dynamic memory allocation for set B


    printf("input elements of set B \n");
    for (j = 0; j < n2; j++)
    {
        scanf("%d", &a2[j]);
    }
    sort(a2,n2);
    //sort function will sort the elements of set B


    i = 0;  j = 0;

    // finding union of set A and B without deleting repetation of elements and then storing
    // the union into a3 .
    for (k = 0; k < (n1+n2), i < n1, j < n2; k++)
    {
        if (a1[i] < a2[j])
        {
            a3[k] = a1[i]; // element is coppied into new array
            i++;
        }

        else if (a2[j] < a1[i])
        {
            a3[k] = a2[j];  // element is coppied into new array
            j++;
        }

        else       // this will execute when a1[i] is equal to a2[j]
        {
            a3[k] = a1[i];
            i++;
            j++;
        }
    }
   
   // for the remaining elements of set B
    if (i >= n1)
    {
        while (j < n2)
        { //k=j+(i-j);
            a3[k] = a1[j];
            i++;
            k++;
        }
    }

   // for the remaining elements of set B
    if (j >= n2)
    {

        while (i < n1)
        { 
            a3[k] = a1[i];
            i++;
            k++;
        }
    }


  DelDublicate(a3, k);  
  // This function will delete the dublicate elements present in a3 
  // that is the union of set A and B
   
  
    return 0;
}

//--------------------------------- Bubble sort ----------------------------------------

void sort(int *arr, int n)
{
    int i = 0, j = 0, k, temp, swap = 0;
    temp = arr[0];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n- 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
           

          
        }
    }
}

// ------------------------------------- DelDublicate -----------------------------------

void DelDublicate(int *arr, int k)
{
    int i1, j1 = 0;
    for (i1 = 0; i1 < k - 1; i1++)  
    {
        if (arr[i1] != arr[i1 + 1]) 
        // arr has union of set A and B without deleting repetation
        {
            finalArray[j1] = arr[i1]; // j1 is the length of new array 
                                      //   in which union is stored
            j1++;
        }
    }
   
    finalArray[j1] = arr[k - 1];  
    // storing the last element  of arr in the 
    //finalArray as the above loop terminates before the last element
  

      printf("Union is : ");


// This loop is for printing the elements of finalArray which has union of set A and B
    for (i1 = 0; i1 <=j1; i1++)
    {
        printf("%d ", finalArray[i1]);
    }

}
      