#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);

int main() {
    long int nums[] = {4,2,3,5,4,2,6,5,2,12,44,33,19,23,43,4453,465511212131};
    int len;
    long int test_num = 0;

    len = sizeof(nums)/sizeof(nums[0]);

    printf("len = %d\n",len);

    for (int i=0; i < len; i++){
        if (isPrime(nums[i])){
            printf("N = %ld is Prime\n", nums[i]);
        }
    }

    printf("\n\nEnter an integer: ");
    scanf("%ld", &test_num);

    if (isPrime(test_num)){
        printf("\nN = %ld is Prime\n\n", test_num);
    }
    else
        printf("\nN = %ld is Not Prime\n\n", test_num);


}

bool isPrime(int n){

    for (int x = 2; x * x <=n; x++){
        if ( (n % x) == 0) {
            return false;
        }
    }
    return true;
}