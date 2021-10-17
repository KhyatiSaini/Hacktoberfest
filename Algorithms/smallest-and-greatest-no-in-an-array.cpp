#include <iostream>
#include <climits>

using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements in the array\n";
    cin>>n;                    //inputing the number of elements in the array
    int A[n];
    cout<<"Enter the elements of the array\n";
    
    for(int i=0; i<n; i++)     //loop to input all the elements of the array
    {
        cin>>A[i];              //inputing all the elements of the array  
    }
    
    int max_no = INT_MIN;       //assigning the least value in the max_no variable
    int min_no = INT_MAX;       //assigning the maximum value in the min_no variable
    
    for(int i=0; i<n; i++)
    {
      max_no = max(max_no, A[i]); //comparing for maximum number between max_no and element at i index of the array
      min_no = min(min_no, A[i]); //comparing for minimum number between min_no and element at i index of the array
    }
    cout<<"The greatest number present in the array is "<<max_no<<endl;   //printing the greatest number in the array
    cout<<"The smallest number present in the array is "<<min_no<<endl;    //printing the smallest number in the array
    return 0;
} 

