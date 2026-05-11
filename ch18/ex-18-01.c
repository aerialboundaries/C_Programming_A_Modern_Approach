/* C Programming A Modern Approach */

/* ex-18-01.md
2026-05-09

For each of the following declarations, identify the storage class, type
qualifiers, type specifiers, declarators, and initializers.

(a) static char **lookup(int level);
(b) volatile unsigned long io_flags;
(c) extern char *file_name[MAX_FILES], path[];
(d) static const char token_buf[] = "";

My Answer:
(a) static = storage class
    char = type specifier
    **lookup(int level) = declarator returns pointer to pointer to char

(b) volatile = type qualifier
    unsigned long = type specifier
    io_flags = declarator

(c) extern = storage class
    char = type specifier
    *file_name[MAX_FILES] = declarator
    path[] = declarator

(d) static = storage class
    const = type qualifier
    char = type specifier
    token_buf[] = declarator
    "" = initializer
*/
