/* 
Rearrange geeks for geeks array DS question 
https://www.geeksforgeeks.org/rearrange-array-arri/
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n],temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i]=-1;
    }
    for (int i = 0; i < n; i++)
    {
        cin>>ar[i];
        temp[ar[i]]=ar[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<temp[i]<<" ";
    }
}