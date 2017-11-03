#include <stdio.h>


int main() {
    int x;
    int y;

    printf("Enter an integer: ");
    scanf("%d", &x);

    printf("Enter another integer: ");
    scanf("%d", &y);
    
    printf("\n x = %d   y = %d\n", x,y);

    // Swap x and y without using a temporary variable

    if (x > y){
        x = x - y;
        y = x + y;
        x = y - x;
    }
    else {
        y = y - x;
        x = x + y;
        y = x - y;
    }

    printf("\n*** SWAP ***\n\n x = %d   y = %d\n\n", x,y);
    
    return 0;
}