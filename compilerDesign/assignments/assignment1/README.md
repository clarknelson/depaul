# Assignment One

**Purpose:** To go over Recursive descent parsers

## Overview:

Finish my C++ program that implements a recursive-descent parser of a simple language on strings. The language can handle:

* String constants: "Hello" = "Hello"
* String concatenation: "Hello " + "there" = "Hello there"
* String repetition: 3 * "Hello " = "Hello Hello Hello "
* Parentheses: 3 * ("Hello " + "there ") = "Hello there Hello there Hello there ", not "Hello Hello Hello there "

## Instructions

Finish parseSentence() and parseExpression()

The grammar rules that parseSentence() should implement are:

1. `S -> E`
2. `S -> E '+' S`

The grammar rules that parseExpression() should implement are:

1. `E -> <string>`
2. `E -> <int> '*' E`
3. `E -> '(' S ')'`

If you detect an error then simply throw a string that describes the problem. In my code I had the following:

* `throw "Expected * after integer"`
* `throw "Expected end parenthesis"`
* `throw "Expected integer, string constant, or begin parenthesis"`

## Hints

Look at S: it has two productions

* `S -> E`
* `S -> E '+' S`

both of which begin with E. Therefore, the very first thing parseSentence() ought to do is parseExpression() (of course it should keep whatever parseExpression() returns in a Node* variable.)

After that, parseSentence() should then tokenizer.peek() at the next Symbol. If has type CONCAT_SYM then it should do a recursive parseSentence() and return a corresponding ConcatNode.

Look at the productions: what is allowed to come after S? If you do not see that then you may throw error string.

parseExpression() has three legal cases (that return a new StringNode, a new RepeatNode and a sentence). Anything else is an error.

## Methods:

**tokenizer.peek()** - It returns the symbol_t value for the next symbol on the input stream, without changing the input stream. When you reach the end of input it returns the value END_OF_INPUT_SYM.

**tokenizer.advance()** - It returns a pointer to the instance of Symbol that was next in the token stream, and internally goes to the next symbol. Once you are thru with them, all Symbol instances should be delete()d, except the one whose type is END_OF_INPUT_SYM.

**getType() of Symbol** - It tells what type of symbol you have, which is one of the constants of symbol_t.

**getString() of Symbol** - If getType()==STRING_CONST_SYM then getString() returns the string that was parsed as type std::string.

**getInteger() of Symbol** - If getType()==INTEGER_CONST_SYM then getInteger() returns the integer that was parsed as type unsigned int.

**new StringNode(string myString)** - Makes a Node instance that represents string constant myString.

**new ConcatNode(Node* lhs,Node* rhs)** - Makes a Node instance that represents the concatenation of the strings returned by lhs and rhs.

**new Repeat(unsigned int totalCount, Node* node)** - Makes a Node instance that represents the repetition of the string returned by node a total of totalCount times.

## Sample Output:

    [instructor@jphillipsCentOS6-5 Assign1]$ ./stringLanguage
    Expression to compute: "Hello"
    Hello

    [instructor@jphillipsCentOS6-5 Assign1]$ ./stringLanguage
    Expression to compute: (I just press Enter)
    Expected integer, string constant, or begin parenthesis

    [instructor@jphillipsCentOS6-5 Assign1]$ ./stringLanguage
    Expression to compute: "Hello " + "there"
    Hello there

    [instructor@jphillipsCentOS6-5 Assign1]$ ./stringLanguage
    Expression to compute: "Hello " +
    Expected integer, string constant, or begin parenthesis

    [instructor@jphillipsCentOS6-5 Assign1]$ ./stringLanguage
    Expression to compute: + "there"
    Expected integer, string constant, or begin parenthesis

    [instructor@jphillipsCentOS6-5 Assign1]$ ./stringLanguage
    Expression to compute: 3 * "Hello "
    Hello Hello Hello

    [instructor@jphillipsCentOS6-5 Assign1]$ ./stringLanguage
    Expression to compute: 3 *
    Expected integer, string constant, or begin parenthesis

    [instructor@jphillipsCentOS6-5 Assign1]$ ./stringLanguage
    Expression to compute: * "Hello "
    Expected integer, string constant, or begin parenthesis

    [instructor@jphillipsCentOS6-5 Assign1]$ ./stringLanguage
    Expression to compute: 3 * "Hello " + "there"
    Hello Hello Hello there

    [instructor@jphillipsCentOS6-5 Assign1]$ ./stringLanguage
    Expression to compute: ("Hello " + "there"
    Expected end parenthesis

    [instructor@jphillipsCentOS6-5 Assign1]$ ./stringLanguage
    Expression to compute: ("Hello " + "there")
    Hello there

    [instructor@jphillipsCentOS6-5 Assign1]$ ./stringLanguage
    Expression to compute: 3 * ("Hello " + "there ")
    Hello there Hello there Hello there
