//! @file CPU.h

#ifndef   CPU_H
#define   CPU_H

//-----------------------------------------------------------------------------

#include "../include/stack.h"
#include "../include/common.h"

//-----------------------------------------------------------------------------

enum REGS
{
    RAX,
    RBX,
    RCX,
    RDX,
    REX,
};

//-----------------------------------------------------------------------------

typedef struct Cpu_info
{
    FILE *code_file;
    FILE *label_file;
    FILE *log_file;
    int32_t code_sgntr;
} Cpu_info;

//-----------------------------------------------------------------------------

typedef struct Processor
{
    Cpu_info Info;
    int     *regs;
    int     *labels;
    double  *ram;
    double  *code;
    Stack    Stk;
} Assembler;

//-----------------------------------------------------------------------------

void processor       ();

void Cpu_data_ctor   (Cpu_data_ *data);

void code_dump       (double *code, int size, int32_t code_sgntr);

void read_label_file (FILE *label_file_, Cpu_data_ *data);

void read_code_file  (FILE *code_file_, Cpu_data_ *data);

void calculator      (Stack *stk_, Cpu_data_ data, FILE *file_log);

void label_dump      (int *labels, int size);

void fill_code_array (FILE *code_file_, int res_sum_, Cpu_data_ *data);

bool is_equal        (double a, double b);

void handle_cmds     (Stack *stk, int cmd_d, double arg_d, int *ipp, Cpu_data_ data, FILE *file_log);

void free_Cpu_info   (Cpu_data_ *data);

//-----------------------------------------------------------------------------

#endif //CPU_H
