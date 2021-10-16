#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int max_num = arr[0], secmax_num=arr[1];
    for (int i = 0; i < n; i++)
    {
        if (max_num < arr[i])
        {
            secmax_num = max_num;
            max_num = arr[i];   
        }
        if(secmax_num<arr[i]&&arr[i]<max_num)
                secmax_num=arr[i];       
    }
    cout << secmax_num;
}