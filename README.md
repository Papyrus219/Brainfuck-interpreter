Simple brainfuck interpreter.

How to compile? ⚙️

Just simply write in console CMake -B build and then make(or ninja if you prefere.).

How to\ use? 📜

You must run program from console. As arguments you should give path/s to brainfuck source files. You can give as many as you want, program will combine it in one long script. Source files can be in any text file format (not only .bf). Program will check if all brackets have pair and run program.

Why? ä

I was little bored lol. But i will glad for feedback (Its my first program where I use argc and argv).

Brainfuck convention 🧔‍♀️

* 30,000 fields, each can storage 255.
* If value go under 0 it will be set to 255 and vice versa.
* If ptr go on 30,001 field it will go back to first and vice versa.
* Available commands:
- '+' Increase value of field actualy pointed by pointer 
- '-' Decrease value of field actualy pointed by pointer
- '<' Move pointer one field to left.
- '>' Move pointer one field to right.
- '[' Start of loop. Loop will start if actualy pointed field is bigger than 0. If no it will skip to coresponding ']'.
- ']' If loop ongoing it go back to closest '['.
- '.' Print ascii character of actual pointed field.
- ',' Save entered character as ascii number.
