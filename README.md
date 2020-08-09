# SPEL

Spel is a programming language submitted as an evaluation project for the 2019-20 Formal Language and Compilers course at the UAIC University.

Spel is a language designed to mimic a fantasy story, in a way you might not expect.

Spel was compiled with win_flex_bison, but it *might* be compatible with lex/yacc. This repo comes with a built-in unittester that can be accessed from the compiler.

Command arguments:
### FILE
> "SPEL.exe \<file\>"

### STRING

> "SPEL.exe -s or /s \<string\> for parsing a string";

You can pass a string to the console for the program to parse.

### TESTS
> "SPEL.exe \<test_file\> --test or /test for running on a test file";

You can create tests for checking the language by appending blocks with the structure:

```c++
[TEST] Test name :
//Your code here
[END]
```

The output will be either FAIL/PASS depending on wether the word is accepted or not. 
You can check if a test which is supposed to fail actually behaves like so by writing `[TEST][SHOULD FAIL] ...`.

### Debug

> "... -v or /v for enabling debug info";

Running the debug mode will print the grammar rules and non-terminals in the order they were acessed by the compiler.Note

Note: If you notice one non-terminal starts with [!warning] that means that the name of the non-terminal is probably incorect, due to a parser error. Refer to the printed rule for determining the correct non-terminal (look for the nt parent of the rule).

### Example program:
```
The tale begins.

I summon thy name Link 
	craft points life_points.
	craft precise mana_points.
	craft rune armor_enchantments.
	craft absolute mortality.
	craft tome allegiance bestow "Zelda".
	
	void spell attack sacrifice precise stamina, precise mana :
		enchant stamina with stamina - 1.
		enchant mana with mana - 2.
	terminus
	points spell fire sacrifice precise mana, rune equipment :
		cast (mana*equipment).
		enchant a with life_points of clone.
		if (equipment > '\3') beginif
			enchant life_points of clone with a.
		endif
		else beginelse
			cast 0.
		endelse
	terminus
and thy brethren.

craft Link clone.

enchant life_points of clone with 100.

craft artifact points basic_attack bestow 3.
```
