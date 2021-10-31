#include <bits/stdc++.h>
using namespace std;

void print_max(int a[], int n, int k)
{
	int max_upto[n];
	stack<int> s;
	s.push(0);
	for (int i = 1; i < n; i++) {
		while (!s.empty() && a[s.top()] < a[i]) {
			max_upto[s.top()] = i - 1;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		max_upto[s.top()] = n - 1;
		s.pop();
	}
	int j = 0;
	for (int i = 0; i <= n - k; i++) {
		while (j < i || max_upto[j] < i + k - 1)
			j++;
		cout << a[j] << " ";
	}
	cout << endl;
}


int main()
{
	int a[] = { 9, 7, 2, 4, 6, 8, 2, 1, 5 };
	int n = sizeof(a) / sizeof(int);
	int k = 3;
	print_max(a, n, k);

	return 0;
}
