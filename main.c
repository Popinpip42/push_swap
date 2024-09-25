#include "push_swap.h"

void  print_stack(t_stack *stack)
{
  int num;

  while ((num = pop(stack)) != -1)
    printf("%d\n", num);
}

int main(int argc, char **argv)
{
  if (argc < 3)
    return (0);
  printf("Arguments Size : %i \n", argc - 1);
  int stack_len = 0;
  stack_len = get_args_len(argc, argv);
  printf("Numbers counted from argv : %i\n", stack_len);

  t_stack stack_a; //Intialize stack A;
  fill_stack(&stack_a, stack_len, argv, argc);

  printf("PRINTING STACK FROM MAIN \n");
  printf("\n");
  print_stack(&stack_a);
  //TODO: 1- Instantiate stack b; 2- Apply any algorithm to sort stack a
}

//TODO: Tested with
//1 - ./a.out "aefa" asdfa 11 22a12 "2223 123a1 asdf 33 aa" "adf- as 44" " " "adsfadzxc_ asfd _ 55 a " 55
//2 - ./a.out "2147483647" 2147483648 "--+-2147483648" -2147483649
