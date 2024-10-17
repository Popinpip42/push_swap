#include "push_swap.h"

void  print_stack(t_stack stack)
{
  int i;

  i = 0;
  while ((stack.top - i) > (stack.bottom + 1))
  {
    printf("Item[%d] - %d\n", stack.top - 1 - i, stack.items[stack.top - 1 -i]);
    i++;
  }
}

void  swap_ideal_indexes(t_stack *stack, int index_1, int index_2)
{
  stack->ideal_indexes[index_1] = stack->ideal_indexes[index_1] ^ stack->ideal_indexes[index_2];
  stack->ideal_indexes[index_2] = stack->ideal_indexes[index_1] ^ stack->ideal_indexes[index_2];
  stack->ideal_indexes[index_1] = stack->ideal_indexes[index_1] ^ stack->ideal_indexes[index_2];
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

int resize_stack(t_stack *stack)
{
  int *resized_items;
  int new_size;

  printf("Resizing Stack - Current Size: %d, Threshold: %d\n", stack->current_size, stack->threshold);
  new_size = stack->fixed_size * 2;
  resized_items = (int *)malloc(new_size * sizeof(int));
  if (!resized_items)
    return (0);
  stack->fixed_size = new_size;
  copy_stack_items(resized_items, stack);
  stack->threshold = (stack->fixed_size / 2) - 1;
  printf("Resizing Stack - Current Size: %d, Threshold: %d\n", stack->current_size, stack->threshold);
  return (1);
}
