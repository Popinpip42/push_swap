#include "push_swap.h"

int main(int argc, char **argv)
{
  t_stack stack_a;
  t_stack stack_b;
  int stack_len;

  if (argc < 3)
    exit(EXIT_FAILURE);

  printf("Arguments Size : %i \n", argc - 1);
  stack_len = get_args_len(argc, argv);

  if (stack_len < 0 || stack_len == 1)
  {
    printf("Not enought valid arguments or only 1 element\n");
    exit(EXIT_FAILURE);
  }
  printf("Numbers counted from argv : %i\n", stack_len);

  if (!init_stack(&stack_a, stack_len))
  {
    printf("Error: init stack a\n");
    exit(EXIT_FAILURE);
  }
  if ((fill_stack(&stack_a, stack_len, argv, argc)) == -1)
  {
    printf("Error\n");
    exit(EXIT_FAILURE);
  }
  if (!init_stack(&stack_b, stack_len))
  {
    printf("Error: init stack b\n");
    exit(EXIT_FAILURE);
  }

  solve_stacks(&stack_a, &stack_b);
}
//TODO: Simple compilation w/o Makefile 26/Sept/2024
// gcc -fsanitize=address -g main.c get_args_len.c fill_stack.c stack_methods.c ft_split.c is_valid.c solve_stacks.c stack_methods_utils.c instructions.c

//TODO: Tested with
//1 - ./a.out "aefa" asdfa 11 22a12 "2223 123a1 asdf 33 aa" "adf- as 44" " " "adsfadzxc_ asfd _ 55 a " 55
//2 - ./a.out "2147483647" 2147483648 "--+-2147483648" -2147483649

//TODO: TEST CODE FOR RESIZING
  /*
  printf("\nTRYING IF RESIZING WORKS OUT\n");
  int i = 0;
  int num = 100;
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

//TODO: TEST CODE FOR POP FUNCTIONS
  /*
  printf("Trying pop function\n");
  int value;
  while (stack_a->current_size > 0)
  {
    pop_back(stack_a, &value);
    printf("Popped -> %d\n", value);
  }
  */

//TODO: TEST CODE FOR INSTRUCTIONS
  /*
  printf("Trying instructions based on push_swap PDF\n");
  printf("--- SA\n");
  swap(stack_a);
  print_stacks(stack_a, stack_b);
  printf("--- PB PB PB\n");
  push_from(stack_b, stack_a);
  push_from(stack_b, stack_a);
  push_from(stack_b, stack_a);
  print_stacks(stack_a, stack_b);
  printf("--- RA RB\n");
  rotate(stack_a);
  rotate(stack_b);
  print_stacks(stack_a, stack_b);
  printf("--- RRA RRB\n");
  rrotate(stack_a);
  rrotate(stack_b);
  print_stacks(stack_a, stack_b);
  printf("--- SA\n");
  swap(stack_a);
  print_stacks(stack_a, stack_b);
  printf("--- PA PA PA\n");
  push_from(stack_a, stack_b);
  push_from(stack_a, stack_b);
  push_from(stack_a, stack_b);
  print_stacks(stack_a, stack_b);
  */

