#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int e1 = arr[0];
    int e2 = 0;
    int e1c = 1 , e2c = 0;

    for(int i = 1; i < n; i++)
    {
        if(arr[i] == e1) 
        {
            e1c++;
        }
        else if(arr[i] == e2)
        {
            e2c++;
        }
        else if(e1c == 0)
        {
          e1 = arr[i];
          e1c = 1;

        }
        else if(e2c == 0)
        {
          e2 = arr[i];
          e2c = 1;
        }
        else{
            e1c--;
            e2c--;
        }
    }

    e1c=0;
    e2c=0;
    for(int i =0;i<n; i++)
    {
        if(arr[i] == e1)
        {
            e1c++;
        }
    }
    for(int i =0;i<n; i++)
    {
        if(arr[i] == e2)
        {
            e2c++;
        }
    }

    if(e1c > n/3 && e2c > n/3)
    {
        cout<<e1<<" "<<e2<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}
