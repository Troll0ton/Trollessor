//! @file CPU.h

#ifndef   CPU_H
#define   CPU_H

//-----------------------------------------------------------------------------

#define num_sup_cmd 9

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
    CMD_RPUSH,
};

//-----------------------------------------------------------------------------

typedef struct Cmd_got
{
    int num;
    char par;
} Cmd_got;

//-----------------------------------------------------------------------------

const Cmd_got Cmd_cpu[] =
{
    {CMD_HLT,   0},
    {CMD_PUSH,  1},
    {CMD_ADD,   0},
    {CMD_SUB,   0},
    {CMD_MUL,   0},
    {CMD_DIV,   0},
    {CMD_OUT,   0},
    {CMD_DUMP,  0},
    {CMD_JUMP,  2},
    {CMD_RPUSH, 3},
};

//-----------------------------------------------------------------------------

void processor ();

void code_dump (double *code, int size);

//-----------------------------------------------------------------------------

#endif //CPU_H
