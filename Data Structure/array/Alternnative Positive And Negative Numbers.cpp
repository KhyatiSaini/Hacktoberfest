// Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
// Note: Array should start with positive number.
 

// Example 1:

// Input: 
// N = 9
// Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
// Output:
// 9 -2 4 -1 5 -5 0 -3 2
// Example 2:

// Input: 
// N = 10
// Arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
// Output:
// 5 -5 2 -2 4 -8 7 1 8 0 


// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function rearrange() which takes the array of integers arr[] and n as parameters. You need to modify the array itself.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
 

// Constraints:
// 1 ≤ N ≤ 107
// -106 ≤ Arr[i] ≤ 107

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    
	    int j=0, k=0;
	    for(int i=0;i<n;i++){
	        if(arr[i] < 0){
	            j++;
	        }
	        else{
	            k++;
	        }
	    }
	   
	    int a[j], b[k],t=0,y=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]<0){
	            a[t]=arr[i];
	            t++;
	        }
	        else{
	            b[y]=arr[i];
	            y++;
	        }
	    }
	    
	    int p=0,q=0;
	    while(p<j && p<k){
	        arr[q] =b[p];
	        q++;
	        arr[q]=a[p];
	        q++;
	        p++;
	    }
	    if(p<j){
	        while(p<j){
	            arr[q]= a[p];
	            q++;
	            p++;
	        }
	    }
	        if(p<k){
	            while(p<k){
	            arr[q] =b[p];
	            q++;
	            p++;
	        }
	        }
	         
	    
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}