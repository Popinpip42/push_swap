#include "push_swap.h"

int add_numbers(t_stack *stack, char *str)
{
  int i;
  int nums_added;
  int words_count;
  char  **args;

  nums_added = 0;
  words_count = calc_words(str, ' ');
  args = ft_split(str, ' ');
  if (args == NULL)
    return (-1);
  while (words_count--)
  {
    if (is_valid(args[words_count], stack))
      push(stack, (int)ft_atoi(args[words_count]));
    else
      printf("Error : %s \n", args[words_count]);
  }
  clean_matrix(args, words_count);
  return (nums_added);
}

int fill_stack(t_stack *stack, int stack_len, char **argv, int argc)
{
  int numbers_added;

  while (argc-- > 1 && stack_len > 0)
  {
    numbers_added = add_numbers(stack, argv[argc]);
    if (numbers_added == -1)
      return (free(stack->items), -1);
    stack_len -= numbers_added;
  }
  return (stack_len);
}
