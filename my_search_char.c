#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char source_str[] = "I am a stranger in a strange land";
    char find_str[] = "strange";

    if (strstr(source_str, find_str) == NULL){
        printf("String not found\n");
    }
    else {
        printf("Found: %s in the string: %s\n", find_str, source_str);
    }
    return 0;
}