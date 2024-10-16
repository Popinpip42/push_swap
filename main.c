#include "push_swap.h"

void  clean_stack(t_stack *stack)
{
  if (stack)
  {
    if (!stack->items)
      free(stack->items);
    if (!stack->ideal_indexes)
      free(stack->ideal_indexes);
  }
}

void clean_all(t_stack *stack1, t_stack *stack2)
{
  clean_stack(stack1);
  clean_stack(stack2);
}

int main(int argc, char **argv)
{
  t_stack stack_a;
  t_stack stack_b;
  int     valid_args_len;
  int     *valid_args;

  if (argc < 3)
    exit(EXIT_FAILURE);

  printf("Arguments Size : %i \n", argc - 1);
  //TODO: could pass transformation function, in this case (ft_atoi()). or (strdup())
  valid_args = get_valid_args(argc, argv, &is_valid_num, &valid_args_len);
  printf("Numbers counted, valid ones, from argv : %i\n", valid_args_len);
  valid_args = filter_(valid_args, &valid_args_len, &is_num_repeated);
  printf("Numbers counted, filtered ones, from argv : %i\n", valid_args_len);

  if (!valid_args)
  {
    printf("Error getting valids_args vector\n");
    exit(EXIT_FAILURE);
  }

  if (valid_args_len == 0 || valid_args_len == 1)
  {
    printf("Not enought valid arguments or only 1 element\n");
    exit(EXIT_FAILURE);
  }
  printf("Numbers counted, valid ones, from argv : %i\n", valid_args_len);
  for (int j = 0; j < valid_args_len; j++)
  {
    printf("items %d - %d\n", j+1, valid_args[j]);
  }
/*
  if (!init_stack(&stack_a, valid_args_len) || !init_stack(&stack_b, valid_args_len)))
  {
    clean_all(&stack_a, &stack_b);
    printf("Error: init stack a\n");
    exit(EXIT_FAILURE);
  }
  if ((fill_stacks(&stack_a, &stack_b, valid_args_len, argv, argc)) == -1)
  {
    clean_all(&stack_a, &stack_b);
    printf("Error\n");
    exit(EXIT_FAILURE);
  }

  //solve_stacks(&stack_a, &stack_b);
  clean_all(&stack_a, &stack_b);
  return (0);
  */
}
//TODO: Simple compilation w/o Makefile 26/Sept/2024
// gcc -fsanitize=address -g main.c get_valid_args.c fill_stack.c stack_methods.c split_on.c is_valid.c solve_stacks.c stack_methods_utils.c instructions.c str_functions.c filter_functions.c

//TODO: Tested with
//1 - ./a.out "aefa" asdfa 11 22a12 "2223 123a1 asdf 33 aa" "adf- as 44" " " "adsfadzxc_ asfd _ 55 a " 55
//  - Expect : items 1 - 11, items 2 - 2223, items 3 - 33, items 4 - 44, items 5 - 55
//2 - ./a.out "2147483647" 2147483648 "--+-2147483648" -2147483649
//  - Expect : items 1 - 2147483647, items 2 - -2147483648

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

