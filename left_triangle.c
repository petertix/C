#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    int counter;

    counter = 0;
    n = 6;

    for (int i=0; i < n; i++) {
        for (int j=0; j < n ; j++){
            if (j < n-i-1) printf(" ");
            else {
                printf("%d", counter);
                counter++;

                if (counter > 9) counter = 0;
            }
        }
        printf("\n");
    }

    return 0;

}