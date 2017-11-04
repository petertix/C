#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern int main(void) {

    int n=0;
    double_t    a,b,c,d;
    system("clear");
    
    printf("\n\n This program will search for solutions to the equation:\n");
    printf("\n            a^3 + b^3 = c^3 + d^3\n\n");
    
    printf("Enter a number n: ");
    scanf("%d",&n);

    for (a=0; a < n; a++) {
        for (b=0; b < n; b++) {
            for (c=0; c < n; c++) {
                for (d=0; d < n; d++) {
                    if ( (pow(a,3)+pow(b,3)) == (pow(c,3)+pow(d,3)) ) 
                        printf("%.0f,%.0f,%.0f,%.0f\n", a, b,c,d);
                }
            }
        }

    }

    return 0;
}