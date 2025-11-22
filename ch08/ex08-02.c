/* C Programming A Modern Approach ex08-02.c
 * 2025-11-22
 *
 * The Q&A section shows how to use a letter as array subscript.
 * Describe how to use a digit (in character form) as a subscript.
 *
 * My Answer:
 * Scale the letter to indicate the number of the element.
 * For small letter, [ch - 'a'], for capitals [ch - 'A'] will give the number
 * '0'.
 *
 * KN's Answer:
 * To use a digit d (in character form) as a subscript into the array a,
 * we would write a [d - '0']. This assumes that digits have consecutive codes
 * in the underlying character set, whichis true of ASCII and other popular
 * characters. */
