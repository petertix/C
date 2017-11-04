#include <stdio.h>

int main() {

    char *str = "Hello There!\n";
    char *ptr;

    ptr = str;

    while(*ptr){
        printf("%c", *ptr);
        ptr++;
    }
    return 0;
}