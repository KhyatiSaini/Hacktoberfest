//Searching kth smallest element
#include<iostream>
using namespace std;
int medianSearch(int arr[],int k,int n)
{ 
    int S1[n],S2[n],S3[n];
    int a=0,b=0,c=0;
    int r=arr[0];
    for(int l=0;l<n;l++)
    {
        if(arr[l]<r)
        {
            S1[a++]=arr[l];
        }
        else if(arr[l]==r)
        {
            S2[b++]=arr[l];
        }
        else
        {
            S3[c++]=arr[l];
        }
    }
    if(a>=k)
    {
        return medianSearch(S1,k,a);
    }
    else if((a+b)>=k)
    {
        return r;
    }
    else
    {
        return medianSearch(S3,k-(a+b),c);
    }
}
int main(int argc, char const *argv[])
{
    int n,k;
    cout<<"Enter the array size:";
    cin>>n;
    int arr[n];
    cout<<"Enter the values:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the value of k:";
    cin>>k;
    int x=medianSearch(arr,k,n);
    cout<<k<<"th smallest element:"<<x;
    return 0;
}