#include <iostream>
using namespace std;

int main()
{
    int n;  
    cout<<"Input a number that you want to reverse\n";
    cin>>n;               //inputing a number from the user
    int rem = 0;         //initializing remainder by 0 
    
    while(n!=0)         //checking condition in order to find the reverse of the number
    {
        rem = n%10;     //to find the last digit of the number
        cout<<rem;     //printing the last digit
        n = n/10;     //to take out the number excluding the last digit
        
    }

    return 0;
}                   //program ends    
