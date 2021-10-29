#include<bits/stdc++.h>

using namespace std;
int arr[100001]; //array to store the pre-compute values of fibonacci which can be directly used when they reappear in the another part of dp tree

int fibonacci(int n){
    if(arr[n]!=-1){
        return arr[n];
    }
    else if(n==0 || n==1){
        return 1;
    }
    else{
        arr[n] = fibonacci(n-1) + fibonacci(n-2);
    }
    return arr[n];
}

int main(){
    int n;
    cin>>n;
    memset(arr,-1,sizeof(arr));
    cout<<fibonacci(n);
}
