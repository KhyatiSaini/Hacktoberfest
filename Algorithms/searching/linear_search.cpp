#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin>>ar[i];
    }
    int s;
    cin>>s;
    for (int i = 0; i < n; i++)
    {
        if(s==ar[i])
        {
            cout<<"At : "<<i+1;
            break;
        }
    }
}