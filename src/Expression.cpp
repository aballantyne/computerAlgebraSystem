#include "Expression.h"
#include "CoreArithmetic.h"
#include <ti/screen.h>
#include <ti/getcsc.h>
#include <stdlib.h>
Expression::Expression()
{
    /* Clear the homescreen */
    os_ClrHome();

    /* Print a string */
    os_PutStrFull("Hello, World.");

    /* Waits for a key */
    while (!os_GetCSC());
}