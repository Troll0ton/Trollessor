#include "../include/ASM.h"
#include "../include/CPU.h"

//-----------------------------------------------------------------------------

int main (int argc, char *argv[])
{
    assembler (argv);
    processor ();

    return 0;
}

//-----------------------------------------------------------------------------
