#include <iostream>
using namespace std;

/*  -----------This is factorial function whose base cases are written in if conditions 
and recursive call is done in else part--------------------------------- */

//There is no need of function decleration as user defined function is
//defined before main fumction.

int factorial(int n)
{
    int temp = 0;
    if (n < 0)
        exit;
    if (n == 0)
        return 1;
    else
    {
        temp = n * factorial(n - 1); // n is the number and factorial(n-1) will give n-1 till n=0
    }                                // n*(n-1)*(n-2)*(n-3)- - - - 0 , 0! is 1 therefore it will give
                                     // the factorial of number n.
    return temp;
}
// temp will store the final factorial which is finally returned to the main function.

int main()
{
    int n;
    cout << "Input value of the number to find it`s factorial " << endl;
    cin >> n;
    if (n < 0)
        cout << "Factorial of a negative number do not exist " << endl;
    if (n == 0)
        cout << "Factorial of 0 is 1 " << endl;
    else
    {
        cout << "factorial of number"
             << " " << n << " "
             << "is : " << factorial(n) << endl;
    }
    // the above line will print the value of n factorial.

    return 0;
}