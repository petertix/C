#include <stdio.h>

int get_max_profit(int *stock_prices_yesterday, int size);
int get_max_profit_fast(int *stock_prices_yesterday, int size);

int get_max_profit(int *stock_prices_yesterday, int size) {
    // Big O(n^2) Solution
    int i,j;
    int diff;
    int max = 0;

    // printf("size = %d\n", size);

    for (i=0; i<size-1;i++) {  // loop (n-1) times
        for (j=i+1; j<size;j++){  // loop n(n+1)/2 times
            diff = stock_prices_yesterday[j] - stock_prices_yesterday[i];
            printf("(%2d,%2d) = %3d ", i,j,diff);
            if(diff > max) {
                max = diff;
            }
            diff = 0;
        }
        printf("\n");
    }
    return(max);
}

int get_max_profit_fast(int *stock_prices_yesterday, int size){
    // Big O(n) Solution

    int i;
    int save_pos;
    int max_profit;
    int current_profit;
    int min_price;
    int current_price;

    if (size >= 2){
        min_price = stock_prices_yesterday[0];
        max_profit = stock_prices_yesterday[1] - stock_prices_yesterday[0];

        for(i=1; i < size; i++){
            current_price = stock_prices_yesterday[i];
            current_profit = current_price - min_price;

            if (current_profit > max_profit) {
                max_profit = current_profit;
                save_pos = i;
            }

            if (current_price < min_price) min_price = current_price;
        }
    }
    else max_profit = -1;

    printf("Min Price: %4d  Max Profit = %4d   Position in array = %4d\n", min_price, max_profit, save_pos);

    return(max_profit);
}

void PrintArray(int *A, int size) {

    int *ptr;

    ptr = A;

    while(*ptr){
        printf("%3d ", *ptr);
        ptr++;
    }
    printf("\n");
}

int main() {

    int maxP = 0;
    //int prices[] = {10,7,5,8,11,9};
    //int prices[15] = {5, 6, 3, 2, 6, 5, 4, 7, 10, 12, 3, 4, 9, 3, 12};
    int prices[15] = {5, 6, 23, 2, 6, 5, 4, 7, 10, 12, 3, 4, 9, 3, 12};

    int size = sizeof(prices)/sizeof(prices[0]);

    // printf("size = %d\n", size);

    maxP = get_max_profit(prices, size);

    printf("\nO(n^2): Max Profit from yesterday = %d\n", maxP);

    PrintArray(prices, size);
    
    maxP = get_max_profit_fast(prices, size);
    
    printf("O(n): Max Profit from yesterday = %d\n\n", maxP);

    return 0;
}
