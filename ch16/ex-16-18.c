/* C Programming A Modern Approach
 * ex-16-18.c
 * 2026-03-31
 *
 * (a) Each square of a chess board can hold one piece - a pawn, knight,
 *     bishop, rook, queen, or King - or it may be empty. Each piece is
 *     either black or white. Define two enumerated types: Piece, which
 *     has seven possible values (one of which is "empty"). and Color,
 *     which has two.
 * (b) Using the types from part (a), define a structure type named Square
 *     that can store both the type of a piece and its color.
 * (c) Using the Square type from part (b), declare an 8 x 8 array named
 *     board that can store the entire contents of a chessboard.
 * (d) Add ann initializer to the declaration in part (c) so that boards'
 *     initial vale corresponds to the usual arrangement of pieces at the
 *     start of chess game. A square that's not occcupied by a piece should
 *     have an "empty" piece value and the color black.
 ****************************************************************************
(a)
typedef enum {PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, EMPTY} Piece;
typedef enum {BLACK, WHITE} Color;

(b)
typedef struct {
  Piece p;
  Color c;
} Square;

(c)
Square board[8][8] = {
{{ROOK, BLACK}, {KNIGHT, BLACK}, {BISHOP, BLACK}, {QUEEN, BLACK},
{KING, BLACK}, {BISHOP, BLACK}, {KNIGHT, BLACK}, {ROOK, BLACK}},

{{PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK},
{PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}},

[2 ... 5] = {[0 ... 7] = {EMPTY, BLACK}},

{{PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE},
{PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}},


{{ROOK, WHITE}, {KNIGHT, WHITE}, {BISHOP, WHITE}, {QUEEN, WHITE},
{KING, WHITE}, {BISHOP, WHITE}, {KNIGHT, WHITE}, {ROOK, WHITE}},
}
 */
