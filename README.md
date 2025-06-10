🐒 ﻿Simple brainfuck interpreter. 🐒

How to compile? ⚙️

Just simply write in the console CMake -B build and then make(or ninja if you prefer).

How to use? 📜

You must run the program from the console. As arguments you should give path/s to brainfuck source files. You can give as many as you want, the program will combine it in one long script. Source files can be in any text file format (not only .bf). The program will check if all brackets have pair and run program.

Why? ä

I was a little bored lol. But I will appreciate feedback (It's my first program where I use argc and argv).

Brainfuck convention 🧔‍♀️

* 30,000 fields, each can store number up to 255.
* If value goes under 0 it will be set to 255 and vice versa.
* If ptr goes to 30,001 field it will go back to first and vice versa.
* Available commands:
- '+' Increase value of field currently pointed by pointer. 
- '-' Decrease value of field actualy pointed by pointer.
- '<' Move pointer one field to the left.
- '>' Move pointer one field to the right.
- '[' Start of the loop. Loop will start if currently pointed field is bigger than 0. If not, it will skip to the corresponding ']'.
- ']' If a loop is ongoing, it goes back to the closest '['.
- '.' Print ASCII character of currently pointed field.
- ',' Save entered character as ASCII number.
