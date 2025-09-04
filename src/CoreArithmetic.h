#pragma once
#include <stdlib.h>
#include <string>   
#include <vector> // note to future andrew CE C++ doesnt have these libraries dont be lazy and create these (itll make it eaiser)   
using namespace std;

extern const vector<string> operations;
extern const vector<string> functions;

bool isFunction(string func);
bool isOperator(string operator);

int getPresendence(string operator);

float performOperation(string operation, float a, float b);
float performFunction(string operation, float a);