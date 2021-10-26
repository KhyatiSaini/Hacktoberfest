#include <stdio.h>
#include <math.h>

int *reverseArray(int *arr, int n)
{
    // int c = n % 2 == 0 ? n / 2 : (n / 2) + 1;
    int c = ceil(n / 2);
    for (int i = 0; i < n / 2; i++)
    {
        int temp = *(arr + i);
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    return arr;
}

int main()
{
    int n;
    n = 10;
    // cin >> n;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int *a = reverseArray(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < n + 1; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    int *b = reverseArray(arr2, n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    return 0;
}