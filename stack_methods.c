#include "push_swap.h"

void  init(t_stack *stack)
{
  stack->top = -1;
}

int push(t_stack *stack, int value)
{
  if (stack->top == MAX_SIZE - 1)
    return (-1);
  return (stack->items[++(stack->top)] = value);
}

int pop(t_stack *stack)
{
  if (stack->top == -1)
    return (-1);
  return (stack->items[(stack->top)--]);
}

int peek(t_stack *stack)
{
  if (stack->top == -1)
    return (-1);
  return (stack->items[stack->top]);
}
