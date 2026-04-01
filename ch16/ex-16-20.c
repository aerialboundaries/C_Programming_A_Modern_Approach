/* C Programming A Modern Approach ***************************************
 * ex-16-20.c
 * 2026-04-01
 *
 * Suppose that the direction varilable is declared in the following way.
 * enum {NORTH, SOUTH, EAST, WEST} direction;
 * Let x and y be int variables. Write a switch statement that tests the
 * vavlue of direction, incrementing x if direction is EAST, decrementing
 * x if direction is WEST, incrementing y if direction is SOUTH, and
 * decrementing y if direction is NORTH.
 **************************************************************************
switch (direction) {
    case EAST: x++;
      break;
    case WEST: x--;
      break;
    case SOUTH: y++;
      break;
    case NORTH: y--;
      break;
    default:
      break;
}

 */
