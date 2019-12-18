# SPEL

Spel is a programming language submitted as an evaluation project for the 2019-20 Formal Language and Compilers course at the UAIC University.

Spel is a language designed to mimic a fantasy story, in a way you might no expect.

Spel was compiled with win_flex_bison, but it *might* be compatible with lex/yacc.

Command arguments:
### TESTS
> "-t or /t for running on a test file";

You can create tests for checking the language by appending blocks with the structure:

```c++
[TEST] Test name (mandatory \n)
statement
/*
*/
declaration //
[END]
```

The output will be either FAIL/PASS depending on wether the word is accepted or not. 
You can check if a test which is supposed to fail actually behaves like so by writing `[TEST][SHOULD FAIL] ...`.

### STRING

> "-s or /s \"string\" for parsing a string";

You can pass a string to the console for the program to parse.

### Debug

> "-v or /v for enabling debug info";

If you want to debug why the word is not accepted, you can do so by:
- debugging in Visual Studio with breakpoints
- running -v and looking at the accessed rules
- running -v and looking at the accessed non-terminal states
