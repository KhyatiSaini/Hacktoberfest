#include <stdio.h>
#include <conio.h>
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
void sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("sorted array : ");
    display(a, n);
}
void insert(int a[], int n, int b, int c)
{
    int m = n + 1;
    for (int i = m; i >= b; i--)
        a[i] = a[i - 1];
    a[b - 1] = c;
    printf("new array : ");
    display(a, m);
    printf("\n");
}
void delete (int a[], int n, int b)
{
    int m = n - 1;
    for (int i = b - 1; i < m; i++)
        a[i] = a[i + 1];
    printf("new array : ");
    display(a, m);
    printf("\n");
}
int main()
{
    int n;
    char ch = 'y';
    printf("enter size of array \n");
    scanf("%d", &n);
    int a[n];
    printf("enter elements in array \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int b = 0;
    printf("enter 1 to display the array\nenter 2 to insert an element\nenter 3 to delete an element\nenter 4 to sort the array\n");
    int c, d, e;
    while (ch == 'y' || ch == 'Y')
    {
        scanf("%d", &b);
        switch (b)
        {
        case 1:
            display(a, n);
            break;
        case 2:
            printf("enter the position \n");
            scanf("%d", &c);
            printf("enter the element \n");
            scanf("%d", &d);
            insert(a, n, c, d);
            break;
        case 3:
            printf("enter the position \n");
            scanf("%d", &e);
            delete (a, n, e);
            break;
        case 4:
            sort(a, n);
            break;
        default:
            printf("wrong input \n");
            break;
        }
        printf("\nenter y to continue or n to exit\n");
        fflush(stdin);
        scanf("%c", &ch);
    }
    getch();
    return 0;
}
