# Textual Formulas
---

Written in C++.

The program takes raw mathematical expressions or equations and transforms them into a visually appealing format suitable for display on the terminal. This formatted output makes it easier to read, understand, and analyze complex formulas compared to their plain text representation. 

## Compiling the program

    [user@fedora TextualFormulas]$ cd builds; cmake ..; make

## Running  the program
     
    [user@fedora TextualFormulas]$ builds/TextualFormulas

The program is going to start a command line interface. Variables can be defined by prefixing them with the dolar sign symbol ('$'). For example:

```
[user@fedora TextualFormulas]$ build/TextualFormulas 
ENTER AN EMPTY COMMAND TO QUIT. DEFINE VARIABLES BY PREFIXING YOUR VARIABLE NAME WITH '$'.
>> $x
>> $y
>> (x+y)/2 + x

 -1: x + y     
  0:------- + x
  1:   2      
```

### Limitations

This program doesn't try to cover all cases. It currently only accepts the four basic operations and the equal sign ('\*', '/', '+', '-', '='). The inputs are not checked and variable names are restricted to a single character. The CLI only takes numbers as integers, even thought all the program blocks are made to accept floats (note that parsing and evaluating the entries isn't  the objective but mostly a demo).

