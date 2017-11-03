#include <stdio.h>

float power(float , int );

int main() {

   float     P;
   float     I;
   float     I_plus_1;
   float     MonthPay;
   int       months;


   printf("\n\nEnter the Principle: ");
   scanf("%f",&P);
   printf("\n");

   printf("Enter the Interest Rate: ");
   scanf("%f",&I);
   printf("\n");

   printf("Enter the Number of Months: ");
   scanf("%d",&months);
   printf("\n");

/*   printf("P=%f I=%f Months=%d\n",P,I,months);  */

   I = I/1200.0;
   I_plus_1 = I + 1;
 
   MonthPay = (P*I) / ( 1 - ( 1 / (power(I_plus_1,months)) ) );

   printf("Monthly Payment = $%8.2f\n\n ",MonthPay);

   return 0;

}


float power(float a, int n)
{
  int i;
  float total;
  
  total = 1;
  if (n > 0) for (i = 1; i <= n; ++i) total = total * a;
  if (n == 0) total = 1;
  return total;
}
