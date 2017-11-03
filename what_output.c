#include <stdio.h>

int main(){
    int a = 5;
    int b = 3;

    //printf("%d\n", ++(a*b+1));  // Will cause comlie error
    printf("%d\n", (a*b+1));

    return 0;
}