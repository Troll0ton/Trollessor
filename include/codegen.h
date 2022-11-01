CMD_(CMD_PUSH,
{
    stack_push (stk, arg_d);
    ip++;
})

CMD_(CMD_POP,
{
    stack_pop (stk);
    ip++;
})

CMD_(CMD_ADD,
{
    stack_push (stk, stack_pop (stk) + stack_pop (stk));
})

CMD_(CMD_SUB,
{
    stack_push (stk, -(stack_pop (stk) - stack_pop (stk)));
})

CMD_(CMD_MUL,
{
    stack_push (stk, stack_pop (stk) * stack_pop (stk));
})

CMD_(CMD_DIV,
{
    stack_push (stk, 1 / stack_pop (stk) * stack_pop (stk));
})

CMD_(CMD_HLT,
{
    printf ("");
})

CMD_(CMD_OUT,
{
    printf ("result: %lg\n", stack_pop (stk));
})

CMD_(CMD_DUMP,
{
    stack_dumps (stk, file_log);
})

CMD_(CMD_JB,
{
    f2 = stack_pop (stk);
    f1 = stack_pop (stk);
    if(f1 < f2)
    {
        int pos_ch = arg_d;
        ip = data.labels[pos_ch] - 2;
    }
    else ip++;
    stack_push (stk, f1);
    stack_push (stk, f2);
})

CMD_(CMD_JBE,
{
    f2 = stack_pop (stk);
    f1 = stack_pop (stk);
    if(f1 <= f2)
    {
        int pos_ch = arg_d;
        ip = data.labels[pos_ch] - 2;
    }
    else ip++;
    stack_push (stk, f1);
    stack_push (stk, f2);
})

CMD_(CMD_JA,
{
    f2 = stack_pop (stk);
    f1 = stack_pop (stk);
    if(f1 > f2)
    {
        int pos_ch = arg_d;
        ip = data.labels[pos_ch] - 2;
    }
    else ip++;
    stack_push (stk, f1);
    stack_push (stk, f2);
})

CMD_(CMD_JAE,
{
    f2 = stack_pop (stk);
    f1 = stack_pop (stk);
    if(f1 >= f2)
    {
        int pos_ch = arg_d;
        ip = data.labels[pos_ch] - 2;
    }
    else ip++;
    stack_push (stk, f1);
    stack_push (stk, f2);
})

CMD_(CMD_JE,
{
    f2 = stack_pop (stk);
    f1 = stack_pop (stk);
    if(is_equal(f1,f2))
    {
        int pos_ch = arg_d;
        ip = data.labels[pos_ch] - 2;
    }
    else ip++;
    stack_push (stk, f1);
    stack_push (stk, f2);
})

CMD_(CMD_JNE,
{
    f2 = stack_pop (stk);
    f1 = stack_pop (stk);
    if(!is_equal(f1,f2))
    {
        int pos_ch = arg_d;
        ip = data.labels[pos_ch] - 2;
    }
    else ip++;
    stack_push (stk, f1);
    stack_push (stk, f2);
})
