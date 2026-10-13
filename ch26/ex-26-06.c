/*
Write the following function:

   char *max_pair(int num_pairs, ... );

The arguments of max_pair are assumed to be "pairs" of integers and strings;
the value of num_pairs indicates how many pairs will follow.
(A pair consists of an int argument followed by a char * argument).
The function searches the integers to find the largest one;
it then returns the string argument that follows it. Consider the following
call:

   max_pair(5, 180, "Seinfeld", 180, "I Love Lucy",
   39, "The Honeymooners", 210, "All in the Family",
   86, "The Sopranos")

The largest int argument is 210, so the function returns "All in the Family",
which follows it in the argument list.
*/
