#include "push_swap.h"

int  init_stack(t_stack *stack, int len)
{
  if (len <= 0)
    return (0);
  else if (len < 10)
    len = 10;
  stack->items = (int *)malloc(len * sizeof(int));
  if (!(stack->items))
    return (0);
  stack->threshold = (len / 2) - 1;
  stack->top = len / 2;
  stack->bottom = (len / 2) - 1;
  stack->current_size = 0;
  stack->fixed_size = len;
  return (1);
}

int push(t_stack *stack, int value)
{
    stack->current_size++;
    if (stack->current_size > stack->threshold)
    {
        if (!resize_stack(stack))
            return (0);
    }
    stack->items[stack->top++] = value;
    return (1);
}

int push_back(t_stack *stack, int value)
{
  stack->current_size++;
  if (stack->current_size > stack->threshold)
  {
    if (!resize_stack(stack))
      return (0);
  }
  stack->items[stack->bottom--] = value;
  return (1);
}

int pop(t_stack *stack, int *value)
{
  if (stack->current_size == 0 || stack->top <= stack->bottom)
      return (0);
  *value = stack->items[--(stack->top)];
  stack->current_size--;
  return (1);
}

int pop_back(t_stack *stack, int *value)
{
  if (stack->current_size == 0 || stack->top <= stack->bottom)
      return (0);
  *value = stack->items[++(stack->bottom)];
  stack->current_size--;
  return (1);
}

/* int peek(t_stack *stack) {
  if (stack->top == -1)
    return (-1);
  return (stack->items[stack->top]);
}
*/
