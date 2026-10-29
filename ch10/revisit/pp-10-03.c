/* C Programming A Modern Approach
 * pp-10-03.c
 * 2026-02-04, 2026-10-29
 *
 * Remove the num_in_rank, num_in_suit, and card_exists arrays from
 * the poker.c program of Section 10.5. Have the program store the cards
 * in a 5 x 2 array insted. Each row of the array will represent a card.
 * For example, if the array is named hand, then hand[0][0] will store the
 * rank of the first card and hand[0][1] will store the suite of the
 * first card */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables */
bool straight, flush, four, three;
int pairs; /* can be 0, 1, or 2 */
int hand[NUM_CARDS][2];

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);
int compare_ints(const void *a, const void *b);

/*************************************************************************
 * main: Calls read_cards, analyze_hand, and print_result repeatedly.    *
 * ***********************************************************************/
int main(void)
{
  for (;;) {
    read_cards();
    analyze_hand();
    print_result();
  }
  return 0;
}

/*************************************************************************
 * read_dards: Reads the cards into the external variables num_in_rank   *
 *             and num_in_suit; checks for bad cards and duplicate cards.*
 * ***********************************************************************/
void read_cards(void)
{
  char ch, rank_ch, suit_ch;
  int rank, suit;
  bool bad_card;
  int cards_read = 0;

  while (cards_read < NUM_CARDS) {
    bad_card = false;

    printf("Enter a card: ");

    rank_ch = getchar();
    switch (rank_ch) {
    case '0':
      exit(EXIT_SUCCESS);
    case '2':
      rank = 0;
      break;
    case '3':
      rank = 1;
      break;
    case '4':
      rank = 2;
      break;
    case '5':
      rank = 3;
      break;
    case '6':
      rank = 4;
      break;
    case '7':
      rank = 5;
      break;
    case '8':
      rank = 6;
      break;
    case '9':
      rank = 7;
      break;
    case 't':
    case 'T':
      rank = 8;
      break;
    case 'j':
    case 'J':
      rank = 9;
      break;
    case 'q':
    case 'Q':
      rank = 10;
      break;
    case 'k':
    case 'K':
      rank = 11;
      break;
    case 'a':
    case 'A':
      rank = 12;
      break;
    default:
      bad_card = true;
    }

    suit_ch = getchar();
    switch (suit_ch) {
    case 'c':
    case 'C':
      suit = 0;
      break;
    case 'd':
    case 'D':
      suit = 1;
      break;
    case 'h':
    case 'H':
      suit = 2;
      break;
    case 's':
    case 'S':
      suit = 3;
      break;
    default:
      bad_card = true;
    }

    while ((ch = getchar()) != '\n')
      if (ch != ' ')
        bad_card = true;

    if (bad_card) {
      printf("Bad card; ignored. \n");
      continue;
    }

    bool duplicate = false;
    for (int i = 0; i < cards_read; i++) {
      if (hand[i][0] == rank && hand[i][1] == suit) {
        printf("Duplicated card; ignored.\n");
        duplicate = true;
        break;
      }
    }

    if (duplicate) {
      continue;
    }

    hand[cards_read][0] = rank;
    hand[cards_read][1] = suit;
    cards_read++;
  }
}

/*************************************************************************
 * analyze_hand: Determines whether the hand contains a straint, a flush
 * four-of-a-kind, and/or three-of-a-kind; determines the number of
 * pairs; stores the results into the external variables straight, flush,
 * four, three, and pairs.
 * ***********************************************************************/
void analyze_hand(void)
{
  straight = false;
  flush = false;
  four = false;
  three = false;
  pairs = 0;

  /*check for flush */
  flush = true;
  for (int i = 1; i < NUM_CARDS; i++) {
    if (hand[i][1] != hand[0][1]) {
      flush = false;
      break;
    }
  }

  /* check for straight */
  int rank_arr[NUM_CARDS];
  for (int i = 0; i < NUM_CARDS; i++) {
    rank_arr[i] = hand[i][0];
  }
  qsort(rank_arr, NUM_CARDS, sizeof(int), compare_ints);

  straight = true;
  for (int i = 0; i < NUM_CARDS - 1; i++) {
    if (rank_arr[i] + 1 != rank_arr[i + 1]) {
      straight = false;
      break;
    }
  }

  /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
  if (rank_arr[0] == rank_arr[3] || rank_arr[1] == rank_arr[4]) {
    four = true;
  } else if ((rank_arr[0] == rank_arr[2] && rank_arr[3] == rank_arr[4]) ||
             (rank_arr[0] == rank_arr[1] && rank_arr[2] == rank_arr[4])) {
    three = true;
    pairs = 1; // Full house
  } else if (rank_arr[0] == rank_arr[2] || rank_arr[1] == rank_arr[3] ||
             rank_arr[2] == rank_arr[4]) {
    three = true;
  } else {
    int pair_count = 0;
    for (int i = 0; i < NUM_CARDS - 1; i++) {
      if (rank_arr[i] == rank_arr[i + 1]) {
        pair_count++;
      }
    }
    pairs = pair_count;
  }
}

/*************************************************************************
 * print_result: Prints the classification of the hand, based on the
 *               variables straight, flush, four, three, and pairs.
 *************************************************************************/
void print_result(void)
{
  if (straight && flush)
    printf("Straight flush");
  else if (four)
    printf("Four of a kind");
  else if (three && pairs == 1)
    printf("Full house");
  else if (flush)
    printf("Flush");
  else if (straight)
    printf("Straight");
  else if (three)
    printf("Three of a kind");
  else if (pairs == 2)
    printf("Two pairs");
  else if (pairs == 1)
    printf("Pair");
  else
    printf("High card");

  printf("\n\n");
}

int compare_ints(const void *a, const void *b)
{
  int int_a = *(const int *)a;
  int int_b = *(const int *)b;

  if (int_a < int_b)
    return -1;
  if (int_a > int_b)
    return 1;
  return 0;
}
