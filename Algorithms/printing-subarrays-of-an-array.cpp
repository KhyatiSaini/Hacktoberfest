#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the no of elements in the array\n";
    cin>>n;             //inputing the no of elements in the array
    int A[n];    
    cout<<"Enter the elements of the array\n";
    for(int i=0; i<n; i++)
    {
        cin>>A[i];      //inputing all the elements of the array  
    }
    
    cout<<"The subarray of the given array are as follows\n";
    
    //code for printing the subarrays of the given array
    
    for(int i=0; i<n; i++)           //loop pointing to individual elements of the array
    {
        for(int j=i; j<n; j++)       //loop for traversing all the elements in the given subarray
        {
            for(int k=i; k<=j; k++)   //loop for printing the elements of the subarray
            {
            cout<<A[k];
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}  //end of program

