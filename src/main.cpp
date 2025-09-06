#include <ti/screen.h>
#include <ti/getcsc.h>
#include <stdlib.h>
#include "String.h"
#include "Postfix.h"

void stringDebug(){
    String s("Test the code");

    s.print(true);
    s.insert(3, '?');
    s.print(true);

    s += "!!";
    s.print(true);
    s.erase(10,14);
    s.print(true);
    
    s.erase(0);
    s.print(true);

    s.substr(0,3).print(true);
    
}
void testPostfix(){
    String expression = String("3.2sin(X)+(2+1)*12.1");
    // String expression = String("sin(3+4)");
    const int STACK_MAX_SIZE = 255; 
    String outputStack[STACK_MAX_SIZE]; 

    
    insertImpliedMultiplicationSigns(expression); 
    
    int size = createPostfixExpression(expression, outputStack);
    String output = String();
    int i = 0;
    while (i < size){
        output = outputStack[i];
        output.print(false, false); 
        String(" ").print(false, false); 
        i++; 
    }
    String("").print(true);
}
int main()
{
    os_ClrHome();
    // stringDebug(); 
    // testStack();
    testPostfix();

    return 0;
}
