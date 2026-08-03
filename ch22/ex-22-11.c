// The following loop appears in the fcopy.c program:
// while ((ch = getc(source_fp) ) != EOF)
// putc(ch, dest_fp);
// Suppose that we neglected to put parentheses around ch = getc (source_fp):
// while (ch = getc(source_fp) != EOF)
// putc(ch, dest_fp);
// Would the program compile without an error? If so, what would the program do
// when it's run?
//
// My Answer:
// Program compiles.  But ch will contain 1 as a result of getc(source_fp) !=
// EOF. When reached to EOF, ch will contain 0.
