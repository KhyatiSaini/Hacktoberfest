/* 

Given n people in a circle, every k-th person is killed in iteration. Find the survivour.

I/p : n=10, k=3 
O/p : 4

*/

#include <iostream>
using namespace std;

int joseph(int n, int k)
{
	if (n == 1)
		return n;
	return (joseph(n - 1, k) + k - 1) % n + 1;
}

int main()
{
	int n, k;
	cout<<"Enter the value of n: ";
	cin>>n;
	cout<<"\nEnter the value of k: ";
	cin>>k;
	cout << "\nThe survivour is at place: " << joseph(n, k);
	return 0;
}