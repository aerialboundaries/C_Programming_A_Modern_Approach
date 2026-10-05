/*
(a) Assertions can be used to test for two kinds of problems: (1) problems that should never
occur if the program is correct, and (2) problems that are beyond the control of the program.
Explain why assert is best suited for problems in the first category.
(b) Give three examples of problems that are beyond the control of the program.

My Answer:
(a) assert is designed to catch programmer errors or logic bugs that should theoretically
never happen in a correct program. When an assertion fails, it immediately terminates the
program to prevent further corruption and aids in debugging. Furthermore, assertions can
be disabled in production builds (using NDEBUG ), so they must not be used to handle
runtime operational errors that the program needs to recover from.
(b) User's input, Functions which depends on network status, program termination by ctrl-c.
*/
