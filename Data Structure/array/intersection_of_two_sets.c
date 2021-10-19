#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// declaration of user defined functions

void intersection_of_sets(int *a1, int *a2, int n1, int n2);
void input_set();
void print_intersection();
int delete_dub();
void sort();

// glabal variables are declared and initialized

int n1 = 0, n2 = 0, i1 = 0;
int *a1, *a2;
int final_array[30] = {0}, k = 0;
int k1 = 0, k2 = 0;


//--------------------------------- Bubble sort ----------------------------------------

void sort(int *arr, int n)         // arr is a pointer storing address of base index of array which is passed in the function
{
    int i = 0, j = 0, k, temp, swap = 0;
    temp = arr[0];
    for (i = 0; i < n; i++)           // outer for loop for no of passes
    {
        for (j = 0; j < n- 1 - i; j++)      // inner for loop for no of comparisions
        {
            if (arr[j] > arr[j + 1])
            {
                swap = arr[j];
                arr[j] = arr[j + 1];                       // swapping two values by using third variable
                arr[j + 1] = swap;
            }
           

          
        }
    }
}

//--------------------------- deleting dublicate element in a set ----------------------------------------

int delete_dub(int *arr, int n)
{
    int t = 0, k1 = 0;                      // initializing variables
    for (t = 0; t < n - 1; t++)
    {
        if (arr[t] != arr[t + 1])     
        {
            arr[k1] = arr[t];       // if both the values are not equal then arr[t] will be stored in arr[k1]
            k1++;                             // k1 is incremented
        }
    }
    arr[k1] = arr[n - 1];

    printf("set after removing dublication is\n");
    for (i1 = 0; i1 <= k1; i1++)
    {
        printf("%d ", arr[i1]);
    }
    printf("\n");
    return k1+1; 
}

//------------------------- printing intersection of two given sets ----------------------------------------

void print_intersection()
{
    printf("set after intersection is\n");
    for (i1 = 0; i1 <k; i1++)                 // loop for printing array after intersection
    {
        printf("%d ", final_array[i1]);
    }
}

//---------------------- inputing values of both the sets ----------------------------------------

void input_set()
{

    printf("input n1\n");
    scanf("%d", &n1);
    printf("input n2\n");
    scanf("%d", &n2);
    a1 = (int *)malloc(n1 * sizeof(int));
    a2 = (int *)malloc(n2 * sizeof(int));

    printf("input array 1 \n");
    for (i1 = 0; i1 < n1; i1++)
    {
        scanf("%d", &a1[i1]);
    }
     sort(a1,n1);
    k1 = delete_dub(a1, n1);

    printf("input array 2 \n");
    for (i1 = 0; i1 < n2; i1++)
    {
        scanf("%d", &a2[i1]);
    }
    sort(a2,n2);
    k2 = delete_dub(a2, n2);
}

//------------------- finding intersection of both the sets ----------------------------------------

void intersection_of_sets(int *a1, int *a2, int k1, int k2)
{

    int i = 0, j = 0;
    for (i = 0; i < k1; i++)
    {
        for (j = 0; j < k2; j++)
        {
            if (a1[i] == a2[j])
            {
                final_array[k] = a1[i];
                k++;
                break;
            }
        }
    }
}

//---------------------------- main function ----------------------------------------

int main()
{
    input_set();

    intersection_of_sets(a1, a2, k1, k2);

    print_intersection();
}