/*
 Replace the test condition in the following if statement by a single call of strstr:
if (strcmp(str, "foo") == 0 || strcmp(str, "bar") == 0 ||
strcmp(str, "baz") == 0) ...
Hint: Combine the string literals into a single string, separating them with a special charac-
ter. Does your solution assume anything about the contents of str?

KN Answer:
if (strstr("foo#bar#baz", str) != NULL) ...

The assumptions are str is at least 3 characters long and doesn't contain # character
*/
