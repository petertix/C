#include <stdio.h>

int  *calc_change(int owed, int change[], int size){

    int tmp;

    tmp = owed;

    if (tmp > 0){
        change[0] = tmp/25;
        tmp-=change[0]*25;
        if (tmp>0){
            change[1] = tmp/10;
            tmp-=change[1]*10;
            if(tmp>0){
                change[2] = tmp/5;
                tmp-=change[2]*5;
                if(tmp>0){
                    change[3] = tmp;
                }
            }
        }
    }

    return(change);
}

int main(){
    int owed;
    int change[4];

    printf("How much change is owed?: ");
    scanf("%d", &owed);

    calc_change(owed, change, 4);

    printf("Quarters: %5d  Dimes: %5d  Nickels: %5d  Pennies: %5d\n",change[0],change[1],change[2],change[3]);
    
}

