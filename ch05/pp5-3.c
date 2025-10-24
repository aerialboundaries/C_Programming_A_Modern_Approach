/* C Programming A Modern Approach pp5-3.c
 *
 * Modify the broker.c program of Section 5.2 by making both of the following
 * changes: (a) Ask the user to enter the number of shares and the price per
 * share, instead of the value of the trade. (b) Add statements that compute the
 * comission charged by a rival broder ($33 plus 3c per share for fewwer than
 * 2000 shares; $33 plus 2c per share for f2000 shares or more). Display the
 * rival's commissions asa well as the comission charged by the original
 * broker*/

#include <stdio.h>

int main(void) {
  int n_share;
  float p_share, value, commission, r_commission;

  printf("Enter number of share and price per share (??? ??.??): ");
  scanf("%d %f", &n_share, &p_share);
  value = n_share * p_share;

  if (value < 2500.00f)
    commission = 30.00f + .017f * value;
  else if (value < 6250.00f)
    commission = 56.00f + .0066f * value;
  else if (value < 20000.00f)
    commission = 76.00f + .0034f * value;
  else if (value < 50000.00f)
    commission = 100.00f + .0022f * value;
  else if (value < 50000.00f)
    commission = 155.00f + .0011f * value;
  else
    commission = 255.00f + .0009f * value;

  if (commission < 39.00f)
    commission = 39.00f;

  if (n_share <= 2000)
    r_commission = 33.00f + 0.03f * n_share;
  else
    r_commission = 33.00f + 0.02f * n_share;

  printf("Trade value : $%.2f\n", value);
  printf("commission: $%.f\n", commission);
  printf("Rival Commission: $%.f\n", r_commission);

  return 0;
}
