/* C Programming A Modern Approach
 * pp-13-03.c
 * 2026-03-06
 *
 * Modify the deal.c program of Section 8.2 so that it prints the full names
 * of the cards it deals;
 *
 * Enter number of cars in hand: 5
 * Your hand:
 * Seven of clubs
 * Two of spades
 * Five of diamonds
 * Ace of spades
 * Two of hearts
 *
 * Hint: Replace rank_code and suit_code by arrays containing pointer to
 * strings.
 */

/* Deals a random hadn of cards */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITES 4
#define NUM_RANKS 13

int main(void) {

  bool in_hand[NUM_SUITES][NUM_RANKS] = {false};
  int num_cards, rank, suit;
  const char rank_code[] = {'2', '3', '4', '5', '6', '7', '8',
                            '9', 't', 'j', 'q', 'k', 'a'};
  const char suit_code[] = {'c', 'd', 'h', 's'};

  srand((unsigned)time(NULL));

  printf("Enter number of cards in hand: ");
  scanf("%d", &num_cards);

  printf("your hand: ");
  while (num_cards > 0) {
    suit = rand() % NUM_SUITES; /* picks a random suit */
    rank = rand() % NUM_RANKS;  /* picks a randon rank */
    if (!in_hand[suit][rank]) {
      in_hand[suit][rank] = true;
      num_cards--;
      printf(" %c%c", rank_code[rank], suit_code[suit]);
    }
  }
  printf("\n");

  return 0;
}
