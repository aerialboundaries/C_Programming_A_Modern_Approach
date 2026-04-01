/* C Programming A Modern Approach
 * ex-16-15.c
 * 2016-03-31
 *
 * (a) Declare a tag for an enumeration whose values represent the seven
 *     days of the week.
 * (b) Use typedef to define a name for the enumeration of part (a).
 *
 */

// (a)
enum week { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
// (b)
typedef enum {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
} Week;
