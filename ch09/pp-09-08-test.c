/* C Programming A Modern Approach
 * pp-09-08.c
 * 2026-01-29
 *
 * Write a program that simulates the game of craps, which is played with
 * two dice. On the first roll, the player wins if the sum of the dice is 7
 * or 11. The player loses if the sum is 2, 3, or 12. Any other roll is called
 * the "point" and the game continues. On each subsequest roll, the player wins
 * if he or she rolls the point again. The player loses by rolling 7.
 * Any other roll is ignored and the game contines. At the end of each game,
 * the program will ask the user whether or not to play again. When the use
 * enters a response other than y o Y, the program will display the number of
 * wins and losses and then terminate.
 *
 * you rolled: 8
 * Your point is 8
 * You rolled: 3
 * You rolled: 10
 * You rolled: 8
 * You win!
 *
 * Play again? y
 *
 * You rolled: 6
 * Your point is 6
 * You rolled: 5
 * You rolled: 12
 * You rolled: 3
 * You rolled: 7
 * You lose!
 *
 * Play again? Y
 *
 * You rolled 11
 * You win!
 *
 * Play again? n
 *
 * Wins: 2 Losses: 1
 *
 * Write your program as threee functions: main, roll_dice, and play_game.
 * Here are the prototypes for the latter two functions:
 *
 * int roll_dice(void);
 * bool play_game(void);
 *
 * roll_dice should generate two random numbers, each between 1 and 6, and
 * return their sum. play_game should play one craps game (calling roll_dice
 * to determine the outcome of each dice roll); it will return true if the
 * player wins and false if the player loses. play_game is also responsible
 * for dieplaying messages showing the results of the player's dice rolls.
 * main will call play_game repeatedly, keeping track of the number of wins
 * and losses and displaying the "you win" and "you lose" messages.
 * Hint: Use the rand function to generate randome numbers. See the deal.c
 * program in Section 8.2 for an example of how to call rand and the related
 * srand function
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_MAX 6

int roll_dice(void);
bool play_game(void);

int main(void) {
  srand((unsigned)time(NULL));

  int number_win = 0, number_loss = 0;
  char player_answer;

  for (;;) {
    if (play_game()) {
      printf("You win!\n\n");
      number_win++;
    } else {
      printf("You lose!\n\n");
      number_loss++;
    }

    printf("Play again? ");
    scanf(" %c", &player_answer);

    if (player_answer == 'Y' || player_answer == 'y')
      continue;
    else
      break;
  }

  printf("Wins: %d  Losses: %d\n", number_win, number_loss);

  return 0;
}

bool play_game(void) {
  int sum = roll_dice(), point;
  printf("You rolled: %d\n", sum);

  switch (sum) {
  case 7:
  case 11:
    return true;
    break;
  case 2:
  case 3:
  case 12:
    return false;
    break;
  default:
    point = sum;
    printf("Your point is %d\n", point);
    break;
  }

  for (;;) {
    sum = roll_dice();
    printf("You rolled: %d\n", sum);

    if (sum == point) {
      return true;
    } else if (sum == 7) {
      return false;
    }
  }
}

int roll_dice(void) { return (rand() % 6 + 1) + (rand() % 6 + 1); }
