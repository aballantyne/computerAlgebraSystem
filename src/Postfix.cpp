#include "Postfix.h"
#include "CoreArithmetic.h"
#include <stdlib.h>
#include <ctype.h>


void insertImpliedMultiplicationSigns(String& input){
    int i = 1; 
        input.print(true);

    while (i < input.getLength()){
        if ((isdigit(input[i-1]) && isVarible(input[i]))){
            input.insert(i, '*'); 
        }
        if ((isVarible(input[i-1]) && isdigit(input[i]))){
            input.insert(i, '*'); 
        }
        if (((isVarible(input[i-1]) || isdigit(input[i-1])) && input[i] == '(')){
            input.insert(i, '*'); 
        }
        if ((input[i-1] == ')' && (isVarible(input[i]) || isdigit(input[i])))){
            input.insert(i, '*'); 
        }
        i++; 
    }
}
String findFullNumber(String input){
    int i = 0;

    while (i < input.getLength()){
        if (input[i] == '.' || isdigit(input[i])){
            i++; 
        }else {
            break;
        }
    }
    return input.substr(0, i); 
}
String findFullFunction(String input){
    int i = 0;
    
    String fullFunction = String(); 
    while (i < input.getLength()){
        fullFunction += input[i];
        i++; 
        if (isFunction(fullFunction)){
            return fullFunction; 
        }
    }

    return String("Error Not A FUNC");
}   
void pushToStack(const String& item, String* stack,  int& size){
    stack[size] = item; 
    size++; 
}
void pushToStack(const char& item, String* stack,  int& size){
    pushToStack(String(item), stack, size); 
}
String popFromStack(String* stack, int& size){
    size--;
    return stack[size];
}
void testStack(){
    String stack[10];
    int size = 0;
    pushToStack(String("test"), stack, size);
    pushToStack(String("test1"), stack, size);
    stack[0].print();  
    stack[1].print(); 
    popFromStack(stack,size).print();
    stack[0].print(true); 
}

int  createPostfixExpression(String input,  String* outputStack /*needed becuase if created in the function it will go out of scope*/){
    
    int i = 0; 

    const int STACK_MAX_SIZE = 255; 
    String operatorStack[STACK_MAX_SIZE];

    int outputStackSize = 0;
    int operatorStackSize = 0; 
    while (i < input.getLength()){
        if(isdigit(input[i]) || input[i] == '.' /*for floating point numbers*/){
            String fullNumber = findFullNumber(input.substr(i, input.getLength()-i));
            pushToStack(fullNumber, outputStack, outputStackSize); 
            i += fullNumber.getLength();
            continue; // avoid incrementing i 
        }else if(isVarible(input[i])){
            pushToStack(input[i], outputStack, outputStackSize); 
        }else if (isOperator(input[i])) {
            while (
                operatorStackSize !=0 &&
                operatorStack[operatorStackSize-1] != "(" &&
                (getPrecedence(operatorStack[operatorStackSize-1]) > input[i] ||
                (getPrecedence(operatorStack[operatorStackSize - 1]) == getPrecedence(String(input[i])) &&
                isLeftAssociative(String(input[i]))))
            ){
                pushToStack(popFromStack(operatorStack, operatorStackSize), outputStack, outputStackSize);
            }
            pushToStack(input[i], operatorStack, operatorStackSize); 
        }else if(isalpha(input[i]) && islower(input[i])){ // All functions should be lowercase
            String fullFunction = findFullFunction(input.substr(i, input.getLength()-i));
            pushToStack(fullFunction, operatorStack, operatorStackSize); 
            i += fullFunction.getLength(); 
            continue;
        }else if (input[i] == '('){
            pushToStack(input[i], operatorStack, operatorStackSize); 

            if(i < input.getLength() && input[i+1] == '-'){
                String fullNumber = findFullNumber(input.substr(i, input.getLength()-i));
                pushToStack(fullNumber, outputStack, outputStackSize); 
                i += fullNumber.getLength();
                continue;
            }
        }else if(input[i] == ')'){
            String newOperator = popFromStack(operatorStack, operatorStackSize);  
            while(newOperator != "("){
                pushToStack(newOperator, outputStack, outputStackSize);
                newOperator = popFromStack(operatorStack, operatorStackSize);
            }
            if (isFunction(operatorStack[operatorStackSize - 1])){
                pushToStack(popFromStack(operatorStack, operatorStackSize), outputStack, outputStackSize);
            }
        }
        i++;
    }
    while(operatorStackSize != 0){
        pushToStack(popFromStack(operatorStack, operatorStackSize), outputStack, outputStackSize);
    }
    return outputStackSize;
}
