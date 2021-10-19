// CPP program to find minimum and maximum lement in an array.
#include <bits/stdc++.h>
using namespace std;
 
int getMin(int arr[], int n){
    return (n == 1) ? arr[0] : min(arr[0],getMin(arr + 1, n - 1));
}
 
int getMax(int arr[], int n){
    return (n == 1) ? arr[0] : max(arr[0],getMax(arr + 1, n - 1));
}
 
int main(){
    int arr[] = { 15, 454, 76, 87, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Min element : " <<getMin(arr, n) << "\n";
    cout << "Max element: " <<getMax(arr, n);
    return 0;
}
