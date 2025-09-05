#include <ti/screen.h>
#include <ti/getcsc.h>
#include <stdlib.h>
#include "String.h"

void stringDebug(){
    String s("Test the code");

    s.print(true);

    s += "!!";
    s.print(true);
    s.erase(9,13); 

    s.print(true);
    
    s.erase(0);
    s.print(true);

    s.substr(0,3).print(true);
    
}
int main()
{
    
    return 0;
}
