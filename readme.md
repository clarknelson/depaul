# DePaul University - Computer Science

A collection of files worked on in my final two classes at DePaul university. Files from my other classes were lost in the great hard drive crash of 2016.

I uploaded these files for easy access, and to provide sample code in system languages for potential employers.

## CSC 348: Introduction to Compiler Design

### Assignment One

#### Purpose:

To go over Recursive descent parsers

#### Overview:

Finish my C++ program that implements a recursive-descent parser of a simple language on strings. The language can handle:

* String constants: "Hello" = "Hello"
* String concatenation: "Hello " + "there" = "Hello there"
* String repetition: 3 * "Hello " = "Hello Hello Hello "
* Parentheses: 3 * ("Hello " + "there ") = "Hello there Hello there Hello there ", not "Hello Hello Hello there "

#### Instructions

Finish parseSentence() and parseExpression()

The grammar rules that parseSentence() should implement are:

1. `S -> E`
2. `S -> E '+' S`

The grammar rules that parseExpression() should implement are:

1. `E -> <string>`
2. `E -> <int> '*' E`
3. `E -> '(' S ')'`

If you detect an error then simply throw a string that describes the problem. In my code I had the following:

* throw "Expected * after integer"
* throw "Expected end parenthesis"
* throw "Expected integer, string constant, or begin parenthesis" (2x)



#### Sample Output:

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
    [instructor@jphillipsCentOS6-5 Assign1]$
