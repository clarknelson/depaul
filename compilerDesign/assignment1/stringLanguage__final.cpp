/*--------------------------------------------------------------------------*
 *----                                                                  ----*
 *----      This file defines a recursive-descent parser for a simple   ----*
 *----      grammar on strings:                                         ----*
 *----                                                                  ----*
 *----      (1) S -> E                                                  ----*
 *----      (2) S -> E '+' S  // String concatenation                   ----*
 *----      (3) E -> <string>  // String constant                       ----*
 *----      (4) E -> <int> '*' E  // String repetition                  ----*
 *----      (5) E -> '(' S ')'                                          ----*
 *----                                                                  ----*
 *--------------------------------------------------------------------------*
 *----                                                                  ----*
 *----      Version 1.0    2016 April 2     Joseph Phillips             ----*
 *----      Version 1.1    2016 April 10    Clark Nelson                ----*
 *----      - new whitespace formating                                  ----*
 *----                                                                  ----*
 *--------------------------------------------------------------------------*/


#include  <cstdlib>
#include  <iostream>
#include  <string>


//  PURPOSE:  To represent the different lexemes in the language.
typedef enum
    {
      END_OF_INPUT_SYM,
      STRING_CONST_SYM,
      INTEGER_CONST_SYM,
      BEGIN_PAREN_SYM,
      END_PAREN_SYM,
      CONCAT_SYM,
      REPEAT_SYM
    }
    symbol_t;


//  PURPOSE:  To represent the different types of ground Node classes.
typedef enum
    {
      STRING_CONST_NODE,
      CONCAT_NODE,
      REPEAT_NODE
    }
    node_t;

//  PURPOSE:  To represent the double quote character.
const char QUOTE_CHAR = (char)0x22;


//  PURPOSE:  To serve as the base class of all Node classes.
class Node {

  Node& operator= (const Node& rhs);

public :
  //  PURPOSE:  To initiailize '*this'.  No parameters.  No return value.
  Node () { }

  //  PURPOSE:  To make '*this' a copy of 'rhs'.  No return value.
  Node (const Node&  rhs) { }

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
  //  value.
  virtual ~Node () { }

  //  PURPOSE:  To return a 'node_t' representing the type of '*this'.  No
  //  parameters.
  virtual node_t getType () const = 0;

  //  VII.  Methods that do main and misc work of class:
  virtual std::string getValue () const { return(std::string("")); }
};


//  PURPOSE:  To serve as the base class of all constant-storing Node classes.
class StringNode : public Node
{
  //  PURPOSE:  To hold the string constant associated with '*this' Node.
  std::string value_;

  //  No default constructor:
  StringNode ();

  //  No copy assignment operator:
  StringNode operator= (const StringNode& rhs);

public :
  //  PURPOSE:  To initialize '*this' to hold 'newString'.  No return value.
  StringNode (const std::string& newString) : Node(), value_(newString) { }

  //  PURPOSE:  To make '*this' a copy of 'rhs'.  No return value.
  StringNode (const StringNode& rhs) : Node(*this), value_(rhs.value_) { }

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
  //  value.
  ~StringNode () { }

  //  PURPOSE:  To return a 'node_t' representing the type of '*this'.  No
  //  parameters.
  node_t getType () const { return(STRING_CONST_NODE); }

  //  VII.  Methods that do main and misc work of class:
  std::string getValue () const { return(value_); }
};


//  PURPOSE:  To represent the concatenation operation Node.
class ConcatNode : public Node
{
  //  PURPOSE:  To point to the Node on the left hand side of
  //  '*this' concatenation.
  Node* lhsPtr_;

  //  PURPOSE:  To point to the Node on the right hand side of
  //  '*this' concatenation.
  Node* rhsPtr_;

  //  No default constructor:
  ConcatNode ();

  //  No copy constructor:
  ConcatNode (const ConcatNode& rhs);

  //  No copy assignment operator:
  ConcatNode operator= (const ConcatNode& rhs);

public :
  //  PURPOSE:  To initialize '*this' to have node '*newLhsPtr' on the left
  //  hand side and node '*newRhsPtr' on the right hand side.  No return
  //  value.
  ConcatNode (Node* newLhsPtr, Node* newRhsPtr) : Node(), lhsPtr_(newLhsPtr), rhsPtr_(newRhsPtr) { }

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
  //  value.
  ~ConcatNode () {
    delete(rhsPtr_);
    delete(lhsPtr_);
  }

  //  PURPOSE:  To return a 'node_t' representing the type of '*this'.  No
  //  parameters.
  node_t getType () const { return(CONCAT_NODE); }

  std::string getValue () const {
    return( lhsPtr_->getValue() + rhsPtr_->getValue() );
  }
};


//  PURPOSE:  To represent the repetition operation Node.
class RepeatNode : public Node
{
  //  I.  Member vars:
  //  PURPOSE:  To hold the integer constant telling how many times to repeat the string.
  unsigned int totalCount_;

  // PURPOSE: To point to the Node telling the string to repeat.
  Node* nodePtr_;

  //  No default constructor:
  RepeatNode ();
  //  No copy constructor:
  RepeatNode (const RepeatNode& rhs);
  //  No copy assignment operator:
  RepeatNode operator= (const RepeatNode& rhs);

public :
  //  PURPOSE:  To initialize '*this' to note that '*newNodePtr' ought to be
  //  repeated 'newTotalCount' times.  No return value.
  RepeatNode (unsigned int newTotalCount, Node* newNodePtr)
    : Node(), totalCount_(newTotalCount), nodePtr_(newNodePtr) { }

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
  //  value.
  ~RepeatNode () { delete(nodePtr_); }

  //  V.  Accessors:
  //  PURPOSE:  To return a 'node_t' representing the type of '*this'.  No
  //  parameters.
  node_t getType () const { return(REPEAT_NODE); }

  //  VII.  Methods that do main and misc work of class:
  std::string getValue () const {
    std::string toReturn("");

    if (totalCount_ == 0)
      return(toReturn);

    std::string addend = nodePtr_->getValue();
    unsigned int count = 0;

    do {
      toReturn += addend;
      count++;
    }
    while (count < totalCount_);

    return(toReturn);
  }
};

/*  PURPOSE:  To implement an interface that manages the character source. */
class InputCharStream
{
  //  PURPOSE:  To hold the input.
  std::string input_;

  //  PURPOSE:  To hold where the cursor is.
  int index_;

public:
  //  IV.  Constructor(s), assignment op(s), factory(s) and destructor:
  InputCharStream (std::string& newInput) : input_(newInput), index_(0) { }

  //  VII.  Methods that do main and misc work of class:
  //  PURPOSE:  To return the current char, or '\0' if there are no more.
  //  No parameters.
  char peek () const throw() {
    return ( (index_ >= input_.length()) ? '\0' : input_[index_] );
  }

  //  PURPOSE:  To return 'true' if at eof-of-input, or 'false' otherwise.
  bool isAtEnd () const throw() { return(index_ >= input_.length()); }

  //  PURPOSE:  To advance to the next char (if not already at end).  No
  //  parameters.  No return value.
  void advance () throw() {
    if (index_ < input_.length()) index_++;
  }
};


//  PURPOSE:  To represent a parsed symbol, and any associated data.
class Symbol
{
  //  PURPOSE:  To tell the type of symbol that '*this' represents.
  symbol_t symbol_;

  //  PURPOSE:  To point to the string associated with '*this' symbol (if there is one).
  std::string* stringPtr_;

  //  PURPOSE:  To hold the integer associated with '*this' symbol (if there is one).
  unsigned int integer_;

  //  No default constructor:
  Symbol ();
  //  No copy constructor:
  Symbol (const Symbol&);
  //  No copy assignment op:
  Symbol& operator= (const Symbol&);

public :

  //  PURPOSE:  To initialize '*this' to hold symbol 'newSymbol'.  No return
  //  value.
  Symbol (symbol_t newSymbol)
  : symbol_(newSymbol), stringPtr_(NULL), integer_(0) { }

  //  PURPOSE:  To initialize '*this' to hold string 'newString'.  No return
  //  value.
  Symbol (const std::string& newString)
    : symbol_(STRING_CONST_SYM), stringPtr_(new std::string(newString)), integer_(0) { }

  //  PURPOSE:  To initialize '*this' to hold integer 'newInteger'.  No return
  //  value.
  Symbol (unsigned int newInteger)
    : symbol_(INTEGER_CONST_SYM), integer_(newInteger), stringPtr_(NULL) { }

  //  V.  Accessors:
  //  PURPOSE:  To return the type associated with '*this' Symbol.  No parameters.
  symbol_t getType () const { return(symbol_); }

  //  PURPOSE:  To return the integer stored at '*this' Symbol, or '0' if
  //  '*this' does not represent an integer.
  unsigned int getInteger () const { return(integer_); }

  //  PURPOSE:  To return a reference to the string stored at '*this' Symbol,
  //  or the empty string if '*this' does not represent a string.
  const std::string& getString () const {
    static std::string empty("");
    return( (stringPtr_ == NULL) ? empty : *stringPtr_ );
  }
};

//  PURPOSE:  To represent the end of input.
Symbol endSymbol(END_OF_INPUT_SYM);

//  PURPOSE:  To implement an interface that gathers characters into lexemes.
class TokenStream
{
  //  I.  Member vars:
  //  PURPOSE:  To hold the source of the character input.
  InputCharStream& inputCharStream_;

  //  PURPOSE:  To hold the lastest lexeme parsed.
  Symbol* lastParsedPtr_;

  //  No default constructor:
  TokenStream ();

  //  No copy constructor:
  TokenStream (const TokenStream&);

  //  No copy assignment op:
  TokenStream& operator= (const TokenStream&);

protected :
  //  III.  Protected methods:
  //  PURPOSE:  To return a pointer representing a scanned string constant.
  //  No parameters.
  Symbol* scanString () {
    std::string lex("");
    bool haveFoundEnd = false;

    //  Advance past first quote:
    inputCharStream_.advance();

    while ( !inputCharStream_.isAtEnd() ) {
      char c = inputCharStream_.peek();

      inputCharStream_.advance();

      if (c == QUOTE_CHAR) {
        haveFoundEnd  = true;
        break;
      }

      lex += c;
    }

    if (!haveFoundEnd){
      throw "Non-terminated string constant";
    }

    return(new Symbol(lex));
  }

  //  PURPOSE:  To return a pointer representing a scanned integer.  No
  //  parameters.
  Symbol* scanDigits () throw(const char*) {
    std::string lex("");

    while ( isdigit(inputCharStream_.peek()) ) {
      lex += inputCharStream_.peek();
      inputCharStream_.advance();
    }

    return(new Symbol(atoi(lex.c_str())));
  }

  //  PURPOSE:  To return a pointer representing a scanned Symbol, or to return
  //  '&endSymbol' if the '*this' is at the end-of-input.  No parameters.
  Symbol* scanner () throw(const char*) {
    while ( isspace(inputCharStream_.peek()) )
      inputCharStream_.advance();

    if ( inputCharStream_.isAtEnd() )
      return( &endSymbol );

    if ( inputCharStream_.peek() == QUOTE_CHAR )
      return( scanString() );

    if ( isdigit(inputCharStream_.peek()) )
      return( scanDigits() );

    char ch = inputCharStream_.peek();
    Symbol* symbolPtr = NULL;

    inputCharStream_.advance();

    switch (ch) {
      case '(' :
        symbolPtr = new Symbol(BEGIN_PAREN_SYM);
        break;
      case ')' :
        symbolPtr = new Symbol(END_PAREN_SYM);
        break;
      case '+' :
        symbolPtr = new Symbol(CONCAT_SYM);
        break;
      case '*' :
        symbolPtr = new Symbol(REPEAT_SYM);
        break;
      default :
        throw "Unexpected character in input";
    }

    return(symbolPtr);
  }

public :
  //  PURPOSE:  To initialize '*this' to tokenize given characters read from
  //    'newInputCharStream'.  No parameters.
  TokenStream (InputCharStream&  newInputCharStream ) throw(const char*)
    : inputCharStream_(newInputCharStream), lastParsedPtr_(NULL) {
      advance();
  }

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
  //  value.
  ~TokenStream () { }

  //  PURPOSE:  To return the 'symbol_t' of the 'Symbol' instance that is next
  //  in the symbol stream.  No parameters.
  symbol_t peek () throw(const char*) {
    if (lastParsedPtr_ == NULL){
      lastParsedPtr_  = scanner();
    }
    return(lastParsedPtr_->getType());
  }

  //  PURPOSE:  To return the pointer to the old Symbol at that was at the
  //  front of the symbol stream, and then to internally advance to the next
  //  Symbol instance (if not already at the end).  No parameters.
  Symbol* advance () throw(const char*) {
    Symbol* toReturn = lastParsedPtr_;
    lastParsedPtr_ = scanner();
    return(toReturn);
  }
};



/*

START STUDENT WRITTEN CONTENT

*/



// PURPOSE: To print the next token via tokenizer.peek() to the terminal
void checkTokenizerPeek(TokenStream&  tokenizer) {
  switch(tokenizer.peek()){
    case END_OF_INPUT_SYM :
      std::cout << "End of input" << std::endl;
      break;
    case STRING_CONST_SYM :
      std::cout << "String constant" << std::endl;
      break;
    case INTEGER_CONST_SYM :
      std::cout << "Integer constant" << std::endl;
      break;
    case BEGIN_PAREN_SYM :
      std::cout << "Begin parenthesis" << std::endl;
      break;
    case END_PAREN_SYM :
      std::cout << "End parenthesis" << std::endl;
      break;
    case CONCAT_SYM :
      std::cout << "Concat (+)" << std::endl;
      break;
    case REPEAT_SYM :
      std::cout << "Repeat (*)" << std::endl;
      break;
    default:
      std::cout << "Unrecognized symbol in peek";
      break;
  }
}

// PURPOSE: Prevent compile error where "parseSentence" is called before it is defined.
Node* parseSentence (TokenStream& tokenizer) throw(const char*);

// PURPOSE: To return a node containing a fully constructed tree
// containing a legal expression in the string languag
Node* parseExpression (TokenStream& tokenizer) throw(const char*) {

  if(tokenizer.peek() == STRING_CONST_SYM) {
    // since a solo string is considered an expression, we dont do much
    // a variable stores the value of the current (string) token
    // and then creates a node to return for parseExpression
    std::string string = tokenizer.advance()->getString();
    return new StringNode(string);
  }

  if(tokenizer.peek() == INTEGER_CONST_SYM) {
    // find the number of times to repeat the expression
    int repeatCount = tokenizer.advance()->getInteger();

    // handle the * sign, if it exists
    if(tokenizer.peek() == REPEAT_SYM){
      tokenizer.advance(); // clear * from the stack
    } else {
      throw "Expected * after integer";
    }

    // find what to multiply (another expression)
    Node* nextExpression = parseExpression(tokenizer);
    return new RepeatNode (repeatCount, nextExpression);
  }

  if(tokenizer.peek() == BEGIN_PAREN_SYM){

    tokenizer.advance(); // clear ( from the stack

    Node* nextSentence = parseSentence(tokenizer);

    if (tokenizer.peek() != END_PAREN_SYM){
      throw "Expected end parenthesis";
    } else {
      return nextSentence;
    }
  }

  return NULL;
}


//  PURPOSE:  To return a pointer to a heap-allocated Node instance
//  representing a sentence (non-terminal 'S') in String language.
Node* parseSentence (TokenStream& tokenizer) throw(const char*) {

  // each sentence contains at least one expression
  Node* leftHandSide = parseExpression(tokenizer);

  if(tokenizer.peek() == CONCAT_SYM){
    tokenizer.advance(); // clear + from the stack
    // call function again to compute additional expressions
    Node* rightHandSide = parseSentence(tokenizer);
    return new ConcatNode(leftHandSide, rightHandSide);
  }

  if(tokenizer.peek() == END_OF_INPUT_SYM || tokenizer.peek() == END_PAREN_SYM) {
    return leftHandSide;
  } else {
    throw "Illegal token in input";
  }
}



/*

END STUDENT WRITTEN CONTENT

*/



//  PURPOSE:  To return a string with the expression to compute, either from
//  the command line or the keyboard.  'argc' tells how many arguments
//  were on the command line and 'argv[]' points to those arguments.
std::string getInput (int argc, char* argv[]) {
  if (argc > 1)
    return(std::string(argv[1]));

  std::string input;
  std::cout << "Expression to compute: ";
  std::getline(std::cin,input);

  return(input);
}


//  PURPOSE:  To get, and attempt to compute, the expression.  The expression
//  may either come from the command line or the keyboard.  'argc' tells
//  how many arguments were on the command line and 'argv[]' points to
//  those arguments.  Returns 'EXIT_SUCCESS' if the expression was
//  successfully parsed and computed or 'EXIT_FAILURE' otherwise.
int main (int argc, char* argv[]) {
  std::string input(getInput(argc,argv));
  InputCharStream charStream(input);
  int status = EXIT_SUCCESS;

  try {
    TokenStream tokenizer(charStream);
    Node* nodePtr = parseSentence(tokenizer);
    std::cout << nodePtr->getValue() << std::endl;
    delete(nodePtr);

  } catch (const char* messageCPtr) {
    std::cerr << messageCPtr << std::endl;
    status  = EXIT_FAILURE;
  }

  return(status);
}
