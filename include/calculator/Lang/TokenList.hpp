#if !defined(CALCULATOR_TOKEN)
#error You must define CALCULATOR_TOKEN before including this file
#endif

#ifndef CALCULATOR_TOKEN_LAST
#define CALCULATOR_TOKEN_LAST(X) CALCULATOR_TOKEN(X)
#endif

CALCULATOR_TOKEN(Add)
CALCULATOR_TOKEN(Substract)
CALCULATOR_TOKEN(Divide)
CALCULATOR_TOKEN(Multiply)
CALCULATOR_TOKEN(Exponent)
CALCULATOR_TOKEN(Number)
CALCULATOR_TOKEN(OpenParenthesis)
CALCULATOR_TOKEN(CloseParenthesis)
CALCULATOR_TOKEN(Identifier)
CALCULATOR_TOKEN(Const)
CALCULATOR_TOKEN(Let)
CALCULATOR_TOKEN(Equal)
CALCULATOR_TOKEN(EOL)

#undef CALCULATOR_TOKEN
#undef CALCULATOR_TOKEN_LAST
