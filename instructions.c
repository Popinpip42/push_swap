#include "push_swap.h"

void  swap(t_stack *stack)
{
  int old_top;
  int new_top;

  if (stack->current_size < 2)
    return ;
  if (!pop(stack, &old_top))
    return ;
  if (!pop(stack, &new_top))
    return ;
  push(stack, old_top);
  push(stack, new_top);
}

void  push_from(t_stack *dst_s, t_stack *src_s)
{
  int value;

  if (!pop(src_s, &value))
    return ;
  push(dst_s, value);
}

void  rotate(t_stack *stack)
{
  int new_bottom;

  if (!pop(stack, &new_bottom))
    return ;
  push_back(stack, new_bottom);
}

void  rrotate(t_stack *stack)
{
  int new_top;

  if (!pop_back(stack, &new_top))
    return ;
  push(stack, new_top);
}
