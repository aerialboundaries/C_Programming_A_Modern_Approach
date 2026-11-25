#ifndef TOKEN_H
#define TOKEN_H

#define BUFFER 128

enum token { PLUS, MINUS, MULTI, DIV };

void input(void);
void parse_input(char ch);

#endif /* TOKEN_H */
