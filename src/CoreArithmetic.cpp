#include "CoreArithmetic.h"

bool isVarible(char c){
    return isupper(c);
}

bool isOperator(char op){
    return op == '+' ||
           op == '-' ||
           op == '*' ||
           op == '/' ||
           op == '^'; 
}

int getPrecedence(const String& op){
    if (op == '+' || op == '-'){
        return 2;
    }
    if(op == '*' || op == '/'){
        return 3;
    }
    if (op ==  '^'){
        return 4; 
    }
    if (op.getLength() != 1){
        return 5;
    }
    return 0;
}
bool isLeftAssociative(const String& op) {
    if (op == "^") return false;  // exponentiation is right-associative
    return true;                  // everything else is left-associative
}

// Functions should be lowercase for parsing
bool isFunction(String func){ // Need to make more functs included
    return func == "sin" ||
           func == "cos" ||
           func == "tan"; 
}
