#include <stdio.h>

float power(float, int );

int main() {

  float     P;
  float     Pn;
  float     pn_1;
  float     pn_2;
  float     pn_3;
  float     Pn_old;
  float     I;
  float     I_plus_1;
  float     R;
  float     fin_chg;
  float     fin_chg_n;
  int       n;

  printf("\n\nEnter the principle: ");
  scanf("%f",&P);
  printf("\n");

  printf("Enter the Interest Rate: ");
  scanf("%f",&I);
  printf("\n");

  printf("Enter the Monthly Payment: ");
  scanf("%f",&R);
  printf("\n");

  printf("P=%f I=%f R=%f\n",P,I,R);

  I         = I/1200.0;
  I_plus_1  = I + 1;
  n         = 1;
  Pn        = P;
  Pn_old    = 0;
  fin_chg   = 0.0;

  while ( Pn >= 0.0) {

    Pn_old = Pn;
      
    pn_1 = power(I_plus_1,n);
    pn_2 = (R/I);
    pn_3 = power(I_plus_1,n);
    

    Pn = P * pn_1 - (pn_2 * (pn_3 - 1.0) );
    fin_chg_n = (Pn + R) - Pn_old;

    if(Pn >= 0)
    {
      printf(" %4d  %12.2f  %10.2f %10.2f\n",n,Pn,R,fin_chg_n);
      fin_chg += fin_chg_n;
    }
    n++;
    
  }

    printf("\nPrinciple: %10.0f   Int: %3.3f   Payment: %8.2f\n\n", P, I*1200, R);
    printf("\nTotal Payments: %8.2f   Total Finance Charge: %8.2f   Years to payoff: %6.2f\n\n"
                  ,(n-2)*R + Pn_old, fin_chg, n/12.0);

    return 0;

}


float power(float a, int n) {
  int i;
  float total;

  total = 1;
  if (n > 0) for (i = 1; i <= n; ++i) total = total * a;
  if (n == 0) total = 1;
  return total;
}
