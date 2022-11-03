//! @file DASM.h

#ifndef   DASM_H
#define   DASM_H

//-----------------------------------------------------------------------------

#define Disassember      Processor
#define disassember_ctor processor_ctor
#define disassember_dtor processor_dtor

//-----------------------------------------------------------------------------

#include "../include/stack.h"
#include "../include/common.h"
#include "../include/CPU.h"

//-----------------------------------------------------------------------------

int  disassembling ();

void file_writer   (int cmd_d, double arg_d, int *ipp, Processor *Cpu);

//-----------------------------------------------------------------------------

#endif //DASM_H

