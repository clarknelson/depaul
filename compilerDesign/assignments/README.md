## Compiler Design Assignments

#### Assignment 1

The first assignment is a parser for a simple language written in C++. Most of the code was provided by the teacher to turn a raw stream of characters into leximes. There is also code provided to create Nodes which are used by the program to construct a tree.

Our assignment was to finish the `parseSentence` and `parseExpression` functions which are fundemental to getting the parser to work. These function construct Nodes based on the input which are returned to the program.

The language is designed to support "strings", Ints (1,3,5), parenthesis to establish precidence, multipication (*) to duplicate a string, and addition (+) to concat strings. An example input to the program would look something like this: `3 * ("Hello " + "World")`

#### Assignment 2

