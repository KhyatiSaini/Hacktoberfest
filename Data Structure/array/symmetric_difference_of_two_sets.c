#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int a3[10] = {0},a4[10]={0}, i = 0, j = 0, ka = 0, n1 = 0,kb=0,k=0;
int  n2 = 0, k1 = 0, k2 = 0,final_arr[25]={0},final_index;
int *a1, *a2;
//------------------------------ display function ----------------------------------------
void display(int*a, int k)
{
    for (i = 0; i < k; i++)
    {                                                 // for printing all the sets 
        printf("%d ", a[i]); 
    }
}

//--------------------------------- Bubble sort ----------------------------------------

void sort(int *arr, int n)
{
    int k, temp, swap = 0;
    temp = arr[0];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {                               // sorting elements before removing dublicacy
                swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }
}
//---------------------------- --------------- deleting dublicacy ------------------------------------------
int delete_dub(int *arr, int n)
{
    int k1 = 0;
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])  // if adjacent elements are not equal then copy element
        {                         // into same array otherwise skip when element matches
            arr[k1] = arr[i];         // and consider only the last if there is repetation
            k1++;                  //eg: 2 2 3 4 then skip first 2 and copy 2nd 2 in same array
        }
    }
    arr[k1] = arr[n - 1];

    printf("set after removing dublication is : { ");
    for (j = 0; j <= k1; j++)
    {
        printf("%d ", arr[j]);
    }
    printf(" } \n");
    return k1 + 1;
}
// -------------------------------- inputing elements in sets A and B ----------------------------------
void input_sets()
{

    printf("Input size of set A \n");
    scanf("%d", &n1);

    printf("Input size of set B \n");
    scanf("%d", &n2);

    a1 = (int *)malloc(n1 * sizeof(int));
    a2 = (int *)malloc(n2 * sizeof(int));

    printf("Input elements of set A \n");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &a1[i]);
    }
    sort(a1, n1);
    k1 = delete_dub(a1, n1);          // k1 is now index of a1 after removing dublicacy

    printf("Input elements of set B\n");
    for (j = 0; j < n2; j++)
    {
        scanf("%d", &a2[j]);
    }
    sort(a2, n2);
    k2 = delete_dub(a2, n2);           // k2 is now index of a2 after removing dublicacy
}

//-------------------------------- finding union of both differences that is A-B and B-A-------------------

void union_of_both_differences(){

      i=0;j=0;                     // ka is new index of a3 that is index of A-B array
     while(i<ka && j<kb){                      // kb is new index of a4 that is index of B-A array
             if(a3[i]<a4[j])
             {final_arr[final_index]=a3[i];  // if element of A-B is greater then 
                                                 //it will be copied in final arr
             final_index++;
             i++;
             }
         
             
            else  if(a4[j]<a3[i])                 // if element of B-A is greater then it 
                                                               //will be copied in final array
           { final_arr[final_index]=a4[j];  
            final_index++;
            j++;
             }
            
            else
           { final_arr[final_index]=a3[i];   // if element of A-B and B-A are equal then A-B
                                       //wala element will be copied and indeces 
             i++;                                     //of both will be incremented
             j++;
           }
         }
         
         if(i>=ka){
             while(j<kb){
             final_arr[final_index]=a4[j];   // if after comparision elements of A
             final_index++;           // are finished then
                 j++;            // elements of B wil be copied directly in final array
             }
         }
          if(j>=kb){
              while(i<ka){
             final_arr[final_index]=a4[j];    // if after comparision elements 
              final_index++;                    //of B are finished then
                  i++;            // elements of A wil be copied directly in final array
              }
         }
    
     }


//-------------------------------------    A   -   B     ---------------------------------------------------------------------
int A_MINUS_B()
{

    for (i = 0; i < k1; i++)
    {
        for (j = 0; j < k2; j++)
        {
            if (a1[i] == a2[j])
            {
                break;
            }
            if ((a1[i] != a2[j]) && (j == (k2 - 1)))
            {
                a3[ka] = a1[i];
                ka++;
            }
        }
    }
}
//-------------------------------------    B   -   A     -------------------------------
int B_MINUS_A()
{
      
    for (j = 0; j < k2; j++)
    {
        for (i = 0; i < k1; i++)
        {
            if (a2[j] == a1[i])
            {
                break;
            }
            if ((a2[j] != a1[i]) && (i == (k1 - 1)))  // i-(k1-1) represents reaching last
            {                                   // index of a2 after traversing
                a4[kb] = a2[j];
                kb++;
            }
        }
    }
}

// ---------------------------------------   main function  ---------------------------------------------

int main()
{
     input_sets();

      printf("Result of A-B is : set { ");
      A_MINUS_B();
       display(a3 , ka);
       printf("}\n");

      printf("Result of B-A is : set { ");
      B_MINUS_A();
        display(a4, kb);
        printf("}\n");

     union_of_both_differences();
    printf("symmetric difference of given sets A and B is: ");
    display(final_arr,final_index);

    return 0;
}
