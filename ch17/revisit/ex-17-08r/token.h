#ifndef TOKEN_H
#define TOKEN_H

enum token { PLUS, MINUS, MULTI, DIV, EQ, OTHER, MAX };

int parse_input(char ch);

#endif /* TOKEN_H */
