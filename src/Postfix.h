# pragma once   
#include <stdlib.h>
#include "String.h"
void insertImpliedMultiplicationSigns(String& input);

//Returns the size of the array
int createPostfixExpression(String input,  String* outputStack /*needed becuase if created in the function it will go out of scope*/); 
void insertImpliedMultiplicationSigns(String& input);

void testStack();
String findFullNumber(String input); 

