#include "../include/CPU.h"
#include "../include/stack.h"

//-----------------------------------------------------------------------------

void processor ()
{
    Stack stk1;
    stack_ctor (&stk1, 2);

    FILE *code_file  = fopen ("../files/code.txt", "rb");
    FILE *label_file = fopen ("../files/labels.txt", "rb");

    //-----------------------------------------------------------------------------

    int regs[5] = {99, 98, 97, 96, 95};

    //-----------------------------------------------------------------------------

    double ram[3] = {999,999,999};

    //-----------------------------------------------------------------------------

    int res_lab = 0;
    fseek (label_file, 0, SEEK_SET);
    fread (&res_lab, sizeof(int), 1, label_file);

    int *labels = (int*) calloc (res_lab, sizeof (int));

    int val1 = -1;

    for(int i = 1; i <= res_lab; i++)
    {
        fread (&val1, sizeof(int), 1, label_file);
        labels[i - 1] = val1;
    }

    //-----------------------------------------------------------------------------

    int res_sum = -1;

    fread (&res_sum, sizeof(int), 1, code_file);

    double *code = (double*) calloc (res_sum, sizeof (double));

    int cmd = -1;

    for(int ib = 0; ib < res_sum; ib++)
    {
        fread (&cmd, sizeof(int), 1, code_file);

        code[ib] = (double) cmd;

        for(int num_cmd = 0; num_cmd < num_sup_cmd; num_cmd++)
        {
            if(Cmd_cpu[num_cmd].num == cmd && Cmd_cpu[num_cmd].par == 1)
            {
                ib++;
                double val = 0;
                fread (&val, sizeof(double), 1, code_file);

                code[ib] = val;
            }

            else if(Cmd_cpu[num_cmd].num == cmd && Cmd_cpu[num_cmd].par > 1)
            {
                ib++;
                int val2 = 0;
                fread (&val2, sizeof(int), 1, code_file);

                code[ib] = (double) val2;
            }
        }
    }

    code_dump (code, res_sum);

    //-----------------------------------------------------------------------------

    for(int ip = 0; ip < res_sum; ip++)
    {
        int cmd_d = code[ip];
        double arg_d = -1;

        if(cmd_d & ARG_REG) arg_d = regs[(int)code[ip + 1]];

        else if(cmd_d & ARG_RAM) arg_d = ram[(int)code[ip + 1]];

        //if(cmd_d & ARG_IMMED)
        else arg_d = code[ip + 1];

        switch(cmd_d)
        {
            case CMD_PUSH_:
                stack_push (&stk1, arg_d);
                ip++;
                break;
            case CMD_RG_PUSH_:
                stack_push (&stk1, arg_d);
                ip++;
                break;
            case CMD_RM_PUSH_:
                stack_push (&stk1, arg_d);
                ip++;
                break;
            case CMD_ADD_:
                stack_push (&stk1, stack_pop (&stk1) + stack_pop (&stk1));
                break;
            case CMD_SUB_:
                stack_push (&stk1, stack_pop (&stk1) - stack_pop (&stk1));
                break;
            case CMD_MUL_:
                stack_push (&stk1, stack_pop (&stk1) * stack_pop (&stk1));
                break;
            case CMD_DIV_:
                stack_push (&stk1, stack_pop (&stk1) / stack_pop (&stk1));
                break;
            case CMD_HLT_:
                break;
            case CMD_OUT_:
                printf ("result: %lg\n", stack_pop (&stk1));
                break;
            case CMD_DUMP_:
                printf ("|dump|\n");
                break;
            case CMD_JUMP_:
                if(arg_d > 0)
                {
                    int pos_ch = arg_d;
                    code[ip + 1] = -1000;
                    ip = labels[pos_ch - 1] - 1;
                }
                else ip++;
                break;
            default:
                printf ("?%d ", cmd_d);
                break;
        }

        stack_dump_ (&stk1);
    }

    //-----------------------------------------------------------------------------

    stack_dtor (&stk1);

    fclose (code_file);
    fclose (label_file);
}

//-----------------------------------------------------------------------------

void code_dump (double *code, int size)
{
    printf ("\n________________________CODE_DUMP__________________________\n\n");

    for(int i = 0; i < size; i++)
    {
        int num_nul = 0;

        int pow = 1;

        while(i / pow != 0)
        {
            pow *= 10;
            num_nul++;
        }

        if(num_nul == 0)num_nul++;

        for(int j = 0; j < 5 - num_nul; j++)
        {
            printf ("0");
        }

        printf ("%d || %lg\n", i, code[i]);
    }

    printf ("___________________________________________________________\n\n");
}

//-----------------------------------------------------------------------------

int main()
{
    processor ();

    return 0;
}

//-----------------------------------------------------------------------------
