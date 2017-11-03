#include <stdio.h>
#include <string.h>

#define MAX_STR 10
#define MAX_LEN 80

int split(char *str, char split_char, char words[MAX_STR][MAX_LEN]);


int split(char *str, char split_char, char words[MAX_STR][MAX_LEN]){
    //char myarray[MAXSTR][MAXLEN] = {{0}};
    int num_words = 0;
    int word_len;
    int len;
    int i;
    int save_idx;

    len = strlen(str);
    printf("len = %d\n", len);

    save_idx = 0;
    word_len = 0;

    for (i=0; i < len; i++) {
        //printf("%c\n",str[i]);
        if ( (str[i] == split_char) || (i == (len-1)) ) {
            word_len = i - save_idx + 1;
            strncpy (words[num_words], &str[save_idx], word_len);
            save_idx = i+1;
            num_words++;
        }
    }
    return num_words;
}


int main() {
    int i;
    char    str[MAX_LEN];
    char    split_char = ' ';
    char    words[MAX_STR][MAX_LEN];
    int     num_words = 0;

    strncpy (str, "This is only a test. Hello everyone!", strlen("This is only a test  Hello everyone!")+1);
    printf("str = %s\n", str);

    num_words = split(str, split_char, words);

    printf("num_words = %d\n", num_words);
    
    for (int i=0; i < num_words; i++){
        printf("word[%d] = %s\n", i, words[i]);
    }
    printf("All Done.\n");
    
    return 0;
}