#pragma once
#include "String.h" 
#include <stdlib.h>
#include <ctype.h>

bool isVarible(char c);

bool isFunction(String func);
bool isOperator(char op);

int getPrecedence(const String& op);
bool isLeftAssociative(const String& op) ;

float performOperation(String operation, float a, float b);
float performFunction(String operation, float a);