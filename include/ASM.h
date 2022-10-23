//! @file ASM.h

#ifndef   ASM_H
#define   ASM_H

//-----------------------------------------------------------------------------

#include "../include/lines_handle.h"
#include "../include/input_output.h"

//-----------------------------------------------------------------------------

#define num_sup_cmd 11

//-----------------------------------------------------------------------------

enum CMD_CODES
{
    CMD_HLT,
    CMD_PUSH,
    CMD_ADD,
    CMD_SUB,
    CMD_MUL,
    CMD_DIV,
    CMD_OUT,
    CMD_DUMP,
    CMD_JUMP,
    CMD_RG_PUSH,
    CMD_RM_PUSH,
};

//-----------------------------------------------------------------------------

typedef struct Cmd
{
    char *name;
    int num;
    char par;
} Cmd;

//-----------------------------------------------------------------------------

const Cmd Cmd_asm[] =
{
    {"hlt",  CMD_HLT,  0},
    {"push", CMD_PUSH, 1},
    {"add",  CMD_ADD,  0},
    {"sub",  CMD_SUB,  0},
    {"mul",  CMD_MUL,  0},
    {"div",  CMD_DIV,  0},
    {"out",  CMD_OUT,  0},
    {"dump", CMD_DUMP, 0},
    {"jump", CMD_JUMP, 2},
    {"push", 0x11    , 3},
    {"push", 0x41    , 4},
};

//-----------------------------------------------------------------------------

void assembler ();

//-----------------------------------------------------------------------------

#endif //ASM_H