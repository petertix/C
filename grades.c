#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    //printf("len = %d\n", len);

    save_idx = 0;
    word_len = 0;

    for (i=0; i < len; i++) {
        //printf("%c\n",str[i]);
        if ( (str[i] == split_char) || (i == (len-1)) ) {
            word_len = i - save_idx;
            strncpy (words[num_words], &str[save_idx], word_len);
            save_idx = i+1;
            num_words++;
        }
    }
    return num_words;
}


int main() {
    int i, j;
    char    str[MAX_LEN];
    char    split_char = ',';
    char    words[MAX_STR][MAX_LEN];
    char    data[MAX_STR][MAX_LEN];
    int     num_words = 0;
    char    *line = NULL;
    int     count = 0;
    double     sum;
    ssize_t line_len;
    size_t  len;

    FILE *fp;

    fp = fopen("./scores.txt", "r");

    if(fp == NULL) return 1;

    // Ignore the first line of the file
    line_len = getline(&line, &len, fp);

    while ( (line_len = getline(&line, &len, fp)) != -1) {
        printf("Student(%d): %s", count, line);
        strncpy (data[count], line, line_len);
        count++;
    }
    printf("\n\n");

    for (i=0; i < count; i++){
        num_words = split(data[i], split_char, words);
        sum = 0;
        for (j=0; j<num_words; j++){
            //printf("num[%d] = %s\n", j, words[j]);
            sum += strtod(words[j],NULL);
            //printf("sum = %g\n",sum);
            printf("%s ",words[j]);
        }
        printf("Avg[%d] = %4.2f\n", j, sum / (num_words*1.0) );
    }

    //printf("num_words = %d\n", num_words);
    printf("\ncount = %d\n", count);
    
    printf("All Done.\n");
    
    return 0;
}
