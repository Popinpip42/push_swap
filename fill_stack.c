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
  i = 0;
  while (i < words_count)
  {
    if (is_valid(args[i], stack))
      push_back(stack, (int)ft_atoi(args[i]));
    else
      printf("Error at : %s\n", args[i]);
    i++;
  }
  clean_matrix(args, words_count);
  return (nums_added);
}

int fill_stack(t_stack *stack, int stack_len, char **argv, int argc)
{
  int numbers_added;
  int i;

  i = 1;
  while (i < argc && stack_len > 0)
  {
    numbers_added = add_numbers(stack, argv[i]);
    if (numbers_added == -1)
      return (free(stack->items), -1);
    stack_len -= numbers_added;
    i++;
  }
  return (stack_len);
}
