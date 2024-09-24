#include "push_swap.h"

int main(int argc, char **argv)
{
  if (argc < 3)
    return (0);
  printf("Arguments Size : %i \n", argc);
  int stack_len = 0;
  stack_len = get_args_len(argc, argv);
  printf("Numbers counted from argv : %i\n", stack_len);

  t_stack stack_a; //Intialize stack A;
  fill_stack(&stack_a, stack_len, argv, argc);
}
