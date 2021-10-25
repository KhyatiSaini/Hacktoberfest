#include<stdio.h>
#include<stdlib.h>

int main() {
    int h, m;
    float angh, angm;
    printf("\nAngle between hour hand and minute hand\n");
    printf("\nEnter the values in 12hr clock format\n");
    printf("\nEnter the hours: ");
    scanf("%d", &h);
    printf("\nEnter the minutes: ");
    scanf("%d", &m);
    if(h>12 || h<0 || m>60 || m<0) {
        printf("\nInvalid Input\n");
        exit(0);
    }
    angh = 0.5 * (h * 60 + m);
    angm = 6 * m;
    if(angh>angm) {
        if((angh-angm)>180) {
            printf("\nThe angle between the hands of the clock is %.2f.\n", 360.00 - (angh - angm));
        }
        else {
            printf("\nThe angle between the hands of the clock is %.2f.\n", angh - angm);
        }
    }
    else {
        if((angm-angh)>180) {
            printf("\nThe angle between the hands of the clock is %.2f.\n", 360 - (angm - angh));
        }
        else {
            printf("\nThe angle between the hands of the clock is %.2f.\n", angm - angh);
        }
    }
    return 0;
}