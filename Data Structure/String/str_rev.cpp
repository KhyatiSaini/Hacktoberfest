#include <bits/stdc++.h>
using namespace std;
 
// Function to reverse a string
void reverseStr(string& s)
{
    int n = s.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - i - 1]);
}
 
// Driver program
int main()
{
    string s = "MHHM";
    reverseStr(s);
    cout << s;
    return 0;
}
