#include <stdio.h>
#include "finance.h"

int main()
{
  struct loan debt[MAX_DEBT];
  struct loan *debt_p; 
  char   done[1]; 
  int    i=0;


  debt_p = &debt[0];

  for (;;) {

    printf("\nEnter Loan Number %d Information\n\n",i);
   
    printf("Principle: ");
    scanf("%f",&debt_p[i].principle);
    printf("%f\n",debt_p[i].principle);

    printf("\nInterest Rate: ");
    scanf("%f",&debt_p[i].interest);
    printf("%f\n",debt_p[i].interest);

    printf("\nMonthly Payment: ");
    scanf("%f",&debt_p[i].payment);
    printf("%f\n",debt_p[i].payment);

    time_til_payoff(&debt_p[i]);

    printf("\nThe number of months until the loan is paid off is: %d\n",debt_p->n);

    break;
 }

 return 0;
}

