#include "push_swap.h"

int main(int argc, char **argv)
{
  t_stack stack_a;
  t_stack stack_b;
  int stack_len;

  if (argc < 3)
    return (0);
  printf("Arguments Size : %i \n", argc - 1);
  stack_len = get_args_len(argc, argv);
  if (stack_len < 0 || stack_len == 1)
    return (printf("Not enought valid arguments or only 1 element\n"), 0);
  printf("Numbers counted from argv : %i\n", stack_len);
  if (!init_stack(&stack_a, stack_len))
  {
    printf("Error: init stack a\n");
    return (-1);
  }
  if ((fill_stack(&stack_a, stack_len, argv, argc)) == -1)
    return (-1);
  if (!init_stack(&stack_b, stack_len))
  {
    printf("Error: init stack b\n");
    return (free(stack_a.items), -1);
  }

  //TODO: 1- Instantiate stack b; 2- Apply any algorithm to sort stack a

  solve_stacks(&stack_a, &stack_b);
}

//TODO: Tested with
//1 - ./a.out "aefa" asdfa 11 22a12 "2223 123a1 asdf 33 aa" "adf- as 44" " " "adsfadzxc_ asfd _ 55 a " 55
//2 - ./a.out "2147483647" 2147483648 "--+-2147483648" -2147483649
