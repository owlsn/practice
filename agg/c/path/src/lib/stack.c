#include "stack.h"
struct Stack *init_stack()
{
    struct Stack *init = (struct Stack *)malloc(sizeof(struct Stack));
    init->length = 0;
    init->top = NULL;
    init->bottom = NULL;
    return init;
}

void push(struct Stack *s, int data)
{
    struct StackNode *node = (struct StackNode *)malloc(sizeof(struct StackNode));
    node->data = data;
    node->next = s->top;
    if (s->length == 0)
    {
        s->bottom = node;
    }
    s->top = node;
    s->length++;
}

int pop(struct Stack *s)
{
    if (s->length)
    {
        struct StackNode *temp = s->top;
        int data = temp->data;
        s->top = temp->next;
        s->length--;
        free(temp);
        return data;
    }
    else
    {
        return -1;
    }
}

int stack_len(struct Stack *s)
{
    return s->length;
}

int top(struct Stack *s)
{
    return s->top->data;
}