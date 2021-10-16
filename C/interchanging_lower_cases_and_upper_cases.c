#include <stdio.h>
#include <conio.h>

int main()
{
    char ch;
    printf("Input character\n");
    scanf("%c", &ch);

// The ASCII value of a is 97 and A is 65 so the difference is 32

    if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch + 32;

/* After adding 32 to ASCII value of capital letter , the ASCII value of
final character (ch) will be equal to the ASCII value of small letter .
*/
        printf("character after interchanging is : %c", ch);
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        ch = ch - 32;


/* After subtracting 32 from ASCII value of small letter , the ASCII value of
final character (ch) will be equal to the ASCII value of capital letter .
*/


        printf("character after interchanging is : %c", ch);
    }
    else
    {
        printf("enter valid input");
    }

    return 0;
}