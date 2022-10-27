//! @file ASM.h

#ifndef   ASM_H
#define   ASM_H

//-----------------------------------------------------------------------------

#include "../include/lines_handle.h"
#include "../include/input_output.h"

//-----------------------------------------------------------------------------

#include <stdint.h>

//-----------------------------------------------------------------------------

#define Num_sup_cmd 10
#define Num_sup_jmps 6
#define Max_cmd_size 15
#define Arg_max_len 100
#define Jump_num 10
#define push_len 6
#define FAILED_OPEN 1
#define ERROR_ASM 1

#define MASK_IMMED 0x20
#define MASK_REG   0x40
#define MASK_RAM   0x80

//-----------------------------------------------------------------------------

#define Cor_signature   0xBACAFE
#define Incor_signature 0xDEADAC

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
    CMD_RG_PUSH,
    CMD_RM_PUSH,
    CMD_JBE,
    CMD_JAE,
    CMD_JA,
    CMD_JB,
    CMD_JE,
    CMD_JNE,
};

//-----------------------------------------------------------------------------

typedef struct Cmd
{
    char *name;
    int num;
    char par;
} Cmd;

//-----------------------------------------------------------------------------

typedef struct Asm_data_
{
    FILE *file_in;
    FILE *code_file;
    FILE *label_file;
    Line Cur_line;
    int res_sum;
    int32_t code_sgntr;
    int num_of_labels;
} Asm_data_;

//-----------------------------------------------------------------------------

const Cmd Cmd_asm[] =
{
    {"hlt",  CMD_HLT,                0},
    {"push", CMD_PUSH + MASK_IMMED,  1},
    {"add",  CMD_ADD,                0},
    {"sub",  CMD_SUB,                0},
    {"mul",  CMD_MUL,                0},
    {"div",  CMD_DIV,                0},
    {"out",  CMD_OUT,                0},
    {"dump", CMD_DUMP,               0},
    {"push", CMD_PUSH + MASK_REG,    3},
    {"push", CMD_PUSH + MASK_RAM,    4},
    {"jbe",  CMD_JBE  + MASK_IMMED,  3},
    {"jae",  CMD_JAE  + MASK_IMMED,  3},
    {"ja",   CMD_JB   + MASK_IMMED,  2},
    {"jb",   CMD_JA   + MASK_IMMED,  2},
    {"je",   CMD_JE   + MASK_IMMED,  2},
    {"jne",  CMD_JNE  + MASK_IMMED,  3},
};

//-----------------------------------------------------------------------------

int assembler          (char *argv[]);

void label_utility     (Asm_data_ *data, char *cmd_);

void handle_label      (Asm_data_ *data);

void handle_jump       (Asm_data_ *data, char *cmd_);

bool found_label       (Asm_data_ *data);

bool found_arg_funct   (char *cmd_);

void handle_arg_functs (Asm_data_ *data);

void handle_regs       (Asm_data_ *data, char *arg_);

void handle_ram_args   (Asm_data_ *data, char *arg_);

void handle_com_functs (Asm_data_ *data, char *cmd_);

void Asm_data_ctor     (Asm_data_ *data);

void files_ctor        (Asm_data_ *data);

void write_res_sums    (Asm_data_ *data);

void close_files       (Asm_data_ *data);

int  open_files        (Asm_data_ *data, char *argv[]);

//-----------------------------------------------------------------------------

#endif //ASM_H
