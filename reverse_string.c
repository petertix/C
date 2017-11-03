#include <stdio.h>
#include <string.h>

void reverse(char *str);
void reverse2(char *str);
void reverse3(char *str);
void Print(char *str);

void reverse(char *str) {

    int i;
    int len;
    char temp;
    
    len = strlen(str);

    for (i=0; i<len/2; i++) {
        temp = str[i]; 
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}

void reverse2(char *str) {
    char    temp;
    char    *end;

    end = str;

    if (str) {
        while(*end) {
            end++;
        }
        end--;
        printf("strlen = %lu  end = %c\n", strlen(str), *end);
        while(str < end) {
            temp = *str;
            *str++ = *end;
            *end-- = temp;
        }
    }
}

void reverse3(char *str)
{
   if (*str)
   {
       reverse3(str+1);
       printf("%c", *str);
   }
}

void Print(char *str) {
    printf("Len = %lu  String = %s\n", strlen(str), str);
}

int main(){
    char    str[80];
    int i;
    int len;

    strncpy(str, "This is the string to be reversed.", strlen("This is the string to be reversed.")+1);

    printf("\n");
    Print(str);
    reverse(str);
    Print(str);
    
    strncpy(str, "It was the best of times, it was the worst of times.", strlen("It was the best of times, it was the worst of times.")+1);
    
    printf("\n");
    Print(str);
    reverse2(str);
    Print(str);
    
    strncpy(str, "Yellow, blue and red.", strlen("Yellow, blue and red.")+1);
    
    printf("\n");
    Print(str);
    reverse3(str);
    //Print(str);

    printf("\n");
    
    return 0;
}