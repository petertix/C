#include <stdio.h>

void sort_insertion(int A[], int n);
void Print(int A[], int n);

void sort_insertion(int A[], int n){
    int i;
    int j;
    int tmp;

    for(i=1; i < n; i++) {

        tmp = A[i];
        j = i - 1;

        while (j >= 0 && tmp < A[j]) {
            A[j+1] = A[j]; 
            j--;
        }
        A[j+1] = tmp;
    }
}

void Print(int A[], int n) {

    int i;

    printf("The Array = ");
    for (i=0; i < n; i++) {
        printf("%3d  ", A[i]);
    }
    printf("\n");
}

int main() {

    int A[] = {22, 14,8,4,3,4,2,6,1,12,11,32,66,33};
    int n;

    n = sizeof(A)/sizeof(A[0]);

    Print(A,n);
    sort_insertion(A,n);
    Print(A,n);

    return 0;
}