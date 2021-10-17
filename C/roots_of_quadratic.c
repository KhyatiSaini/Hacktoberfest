#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, r1, r2, d, R, I1, I2; // variables are initialized
    printf("Enter values of a, b and c , where a, b and c are coefficients of the equation\n");
    scanf("%d%d%d", &a, &b, &c);
    printf("Required quadratic equation is %dx^2 + %dx + %d = 0\n", a, b, c);

    d = ((b * b) - (4 * a * c)); // d stands for discriminant
    if (d > 0)
    {
        r1 = ((-b) + (sqrt(d))) / (2 * a);
        r2 = ((-b) - (sqrt(d))) / (2 * a);

        printf("Roots are real\n r1 = %d and r2 = %d\n", r1, r2);
    }
    else if (d == 0)
    {

        // for equal roots
        r1 = r2 = -b / 2 * a;
        printf("Roots are real\n r1 = r2 =%d  ", r1);
    }

    else
    {

        // for imaginary roots
        printf("Roots are imaginary\n");
        R = (-b) / (2 * a);
        I1 = ((sqrt(-d)) / (2 * a));
        I2 = -((sqrt(-d)) / (2 * a));
        printf("Imaginary roots are r1 = %d + %di and r2 = %d + %di ", R, I1, R, I2);
    }

    return 0;
}
