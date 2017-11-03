#include <stdio.h>
#include "finance.h"

void time_til_payoff(struct loan *debt_p)
{
   float P;
   float I;

   P = debt_p->principle;
   printf("%f\n",P);

   debt_p->n = 0;

   I = debt_p->interest / 1200.0;

   while ( P > 0.0 )
   {
      P *= (1.0 + I);
      P = P - debt_p->payment;
      debt_p->n++;
   }

}
