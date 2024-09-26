#include "push_swap.h"

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
  
}
//TODO: Currently testing with :
//./a.out "aefa" asdfa 11 22a12 "2223 123a1 asdf 33 aa" "adf- as 44" " " "adsfadzxc_ asfd _ 55 a " 44 55
//TODO: AND TESTING BY ADding NUM 100 items to the "stack" haha
