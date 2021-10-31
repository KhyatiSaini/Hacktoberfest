#include <iostream>
#include <cmath>
using namespace std;
void set_union(int a[], int m, int b[], int n)
{
    int o = m + n;
    int c[o], d = 0, k = m;
    for (int i = 0; i < m; i++)
    {
        c[i] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[i] == a[j])
                d = 1;
        }
        if (d == 0)
        {
            c[k] = b[i];
            k++;
        }
        d = 0;
    }
    cout << "the union of A and B is \n";
    for (int i = 0; i < k; i++)
    {
        cout << c[i] << "\t";
    }
}
void intersection(int a[], int m, int b[], int n)
{
    int o = m + n;
    int c[o], k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
            {
                c[k] = a[i];
                k++;
                break;
            }
        }
    }
    cout << "the intersection of A and B is \n";
    for (int i = 0; i < k; i++)
    {
        cout << c[i] << "\t";
    }
    cout << endl;
}
void difference(int a[], int m, int b[], int n)
{
    int o = m + n;
    int c[o], d = 0, k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
                d = 1;
        }
        if (d == 0)
        {
            c[k] = a[i];
            k++;
        }
        d = 0;
    }
    cout << "the set difference A-B is \n";
    for (int i = 0; i < k; i++)
    {
        cout << c[i] << "\t";
    }
    cout << endl;
}
void symmetricdiff(int a[], int m, int b[], int n)
{
    int o = m + n;
    int d = 0;
    cout << "the symmetric set difference of A and B is \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
                d = 1;
        }
        if (d == 0)
        {
            cout << a[i] << "\t";
        }
        d = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[i] == a[j])
                d = 1;
        }
        if (d == 0)
        {
            cout << b[i] << "\t";
        }
        d = 0;
    }
    cout << endl;
}
int main()
{
    int m, n;
    cout << "Enter size of set A and set B" << endl;
    cin >> m >> n;
    int a[m], b[n];
    cout << "Enter elements in set A" << endl;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    cout << "Enter elements in set B" << endl;
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int x;
    cout << "Enter 1 to perform union operation" << endl;
    cout << "Enter 2 to perform intersection operation" << endl;
    cout << "Enter 3 to perform set difference operation" << endl;
    cout << "Enter 4 to perform symmetric set differnce operation" << endl;
    cin >> x;
    switch (x)
    {
    case 1:
        set_union(a, m, b, n);
        break;
    case 2:
        intersection(a, m, b, n);
        break;
    case 3:
        difference(a, m, b, n);
        break;
    case 4:
        symmetricdiff(a, m, b, n);
        break;
    default:
        cout << "wrong choice" << endl;
        break;
    }
    return 0;
}
