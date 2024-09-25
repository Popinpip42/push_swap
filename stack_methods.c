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

void  print_stack(t_stack stack)
{
  int i;

  i = 1;
  while (((stack.top) - i) > stack.bottom)
  {
    printf("Item[%d] - %d\n", stack.top - i, stack.items[(stack.top) - i]);
    i++;
  }
}

void  copy_stack_items(int *dest, t_stack *stack)
{
  int i;
  int new_top;
  int new_bottom;
  int half_size;

  half_size = (stack->current_size - 1) / 2;
  new_bottom = ((stack->fixed_size / 2) - 1) - ((stack->current_size - 1) / 2); 
  new_top = (stack->fixed_size / 2);
  i = 0;
  while (i < half_size)
  {
      dest[new_bottom + i + 1] = stack->items[(stack->bottom + 1 + i) % stack->fixed_size];
      i++;
  }
  while (i < stack->current_size - 1)
  {
      dest[new_top++] = stack->items[(stack->bottom + 1 + i) % stack->fixed_size];
      i++;
  }
  stack->top = new_top;
  stack->bottom = new_bottom;
  free(stack->items);
  stack->items = dest;
}

int push(t_stack *stack, int value)
{
  int *resized_items;
  int new_size;

  stack->current_size++;
  if (stack->current_size > stack->threshold)
  {
    printf("BEFORE PUSH RESIZE - LEN : %d\n", stack->current_size);
    print_stack(*stack);
    new_size = stack->fixed_size * 2;
    resized_items = (int *)malloc(new_size * sizeof(int));
    if (!resized_items)
      return (0);
    stack->fixed_size = new_size;
    copy_stack_items(resized_items, stack);
    stack->threshold = (stack->fixed_size / 2) - 1;
  }
  stack->items[(stack->top)++] = value;
  return (1);
}

int push_back(t_stack *stack, int value)
{
  int *resized_items;
  int new_size;

  stack->current_size++;
  if (stack->current_size > stack->threshold)
  {
    printf("BEFORE PUSH_BACK RESIZE - LEN : %d\n", stack->current_size);
    print_stack(*stack);
    new_size = stack->fixed_size * 2;
    resized_items = (int *)malloc(new_size * sizeof(int));
    if (!resized_items)
      return (0);
    stack->fixed_size = new_size;
    copy_stack_items(resized_items, stack);
    stack->threshold = (stack->fixed_size / 2) - 1;
  }
  stack->items[(stack->bottom)--] = value;
  return (1);
}


int pop(t_stack *stack)
{
  if (stack->top == -1)
    return (-1);
  stack->current_size--;
  return (stack->items[(stack->top)--]);
}
/*
int peek(t_stack *stack)
{
  if (stack->top == -1)
    return (-1);
  return (stack->items[stack->top]);
}
*/
