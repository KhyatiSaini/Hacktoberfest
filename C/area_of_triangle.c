#include <stdio.h>
#include <conio.h>
#include <math.h>

// This program is finding area of any given triangle

int main()
{
    int area, a, b, c, x, s;
    // variables are initialized

    printf("input values of a.b and c\n");
    scanf("%d%d%d", &a, &b, &c); // values of sides of trisngle are scanned in a, b and c

    s = (a + b + c) / 2;                   // s will store (the sum of a , b , c divide by 2)
    x = (s * (s - a) * (s - b) * (s - c)); // heron`s formula is used
    area = sqrt(x);

    printf("%d is the area of the triangle ", area); // printing area of the triangle
    getch();

    return 0;
}
