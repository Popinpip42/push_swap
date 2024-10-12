#include "push_swap.h"

int get_msb(int n)
{
  int msb;

  if (n == 0)
    return (0);
  msb = 0;
  while (n >>= 1)
    msb++;
  return (msb);
}

int m_sqrt(int n)
{
  int a;
  int result;

  a = 1 << get_msb(n);
  result = 0;
  while (a != 0)
  {
    if ((result + a) * (result + a) <= n)
        result += a;
    a >>= 1;
  }
  return (result);
}

void  print_stacks(t_stack *stack1, t_stack *stack2)
{
  printf("STACK_A\n");
  print_stack(*stack1);
  printf("STACK_B\n");
  print_stack(*stack2);
}

void  solve_stacks(t_stack *stack_a, t_stack *stack_b)
{
  printf("\nPRINTING STACK_A - LEN : %d \n", stack_a->current_size);

  print_stack(*stack_a);
  print_stack(*stack_b);
  //TODO: DIVIDE AND CONQUER

  printf("\nInitializing SORTING\n");
  //Kort-1
  int s_index;
  int range = m_sqrt(stack_a->current_size);
  printf("Stack_a size : %d - Range %d\n", stack_a->current_size, range);
  //Distribution of elements
  printf("Boottom pointer %d - Top pointer %d\n", stack_a->bottom, stack_a->top);
  int j = 0;
  while ((stack_a->top - j) > (stack_a->bottom + 1))
  {
    printf("Item[%d] - %d\n", stack_a->top - 1 - j, stack_a->items[stack_a->top - 1 -j]);
    j++;
  }

  //Ksort-2

}
//TODO: Currently testing with :
//./a.out "aefa" asdfa 11 22a12 "2223 123a1 asdf 33 aa" "adf- as 44" " " "adsfadzxc_ asfd _ 55 a " 44 55
//TODO: AND TESTING BY ADding NUM 100 items to the "stack" haha
