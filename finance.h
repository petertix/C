#define MAX_DEBT 100

struct loan
{
  float principle;
  float interest;
  int   n;
  float payment;
};

void time_til_payoff(struct loan *debt_p);
