#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *longer(char *s1, char *s2);
char *shouting(char *input);

int main() {
    char *str1 = "A long time ago";
    char *str2 = "In a galaxy far, far away...";
    char *result;

    result = longer(str1, str2);
    
    printf("String '%s' is longer.\n", result);

    result = shouting(result);

    printf("Shouting: %s\n", result);

    return(0);
}

char *longer(char *s1, char *s2){
    int len1;
    int len2;

    len1 = strlen(s1);
    len2 = strlen(s2);

    if (len1 > len2) 
        return s1;
    else 
        return s2;

}

char *shouting(char *input){

    //char **result= (char *)malloc(sizeof(char *) * 100);
    char  *result;
    char *p;

    result = (char *)malloc(sizeof(char *) * 100);

    p = result;

    while(*input){

        *p = toupper(*input);
        input++;
        p++;
    }
    free(result);
    return result;
}