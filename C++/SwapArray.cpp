#include <iostream>

using namespace std;
int swapme(int A[],int size){
    int tmp,j,mid=size/2;
    if (size%2 == 0){
            j=mid;
        }
    else{
        j=mid+1;
    }
    for(int i=0;i<mid;i++,j++){
        tmp=A[i];
        A[i]=A[j];
        A[j]=tmp;

    }
    cout<<"The changed array is ";
    for(int k=0;k<size;k++){
        cout<<A[k]<<" ";
    }
    return 0;
}


int main()
{
    int t,h,len;
    cout<<"The length of array: ";
    cin>>len;
    int a[len];
    for(int i=0;i<len;i++){
        cout<<"Enter the value of array: ";
        cin>>a[i];

    }
    cout<<"The array provided is ";
    for(int l=0;l<len;l++)
        cout<<a[l]<<" ";
    cout<<endl;


    swapme(a,len);

    return 0;
}


