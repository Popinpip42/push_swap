#include "push_swap.h"

void  solve_stacks(t_stack *stack_a, t_stack *stack_b)
{
  /*
  printf("\nSTACK_A - CURRENT_LEN: %d \n", stack_a->current_size);
  print_stack(*stack_a);
  printf("STACK_B - CURRENT_LEN: %d \n", stack_b->current_size);
  print_stack(*stack_b);
 */ 
  /*
  printf("\nTRYING IF RESIZING WORKS OUT\n");
  int i = 0;
  int num = 500;
  while (i < num / 2)
  {
    if (i < (num / 2) / 2)
      push_back(stack_a, i);
    else {
      push(stack_a, i);
    }
    i++;
  }
  */

  printf("PRINTING STACK_A - LEN : %d \n", stack_a->current_size);
  print_stack(*stack_a);


  //TODO: Implement algorithm (TURK, ...)
  printf("\nABOUT TO START SOLVING\n");
  
}
