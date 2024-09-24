#include "push_swap.h"

int ft_atoi(const char *str)
{
  int num;
  int sign;

  sign = 1;
  while (*str == ' ' || (*str >= 9 && *str <= 13))
    str++;
  if (*str == '-')
    sign = -1;
  if (*str == '+' || *str == '-')
    str++;
  num = 0;
  while (*str >= '0' && *str <= '9')
  {
    num = num * 10 + (*str - '0');
    str++;
  }
  return (num * sign);
}

int is_numeric(char *str)
{
  int is_numeric;
  int i;

  i = 0;
  is_numeric = 1;
  while (str[i])
  {
    if (!ft_isdigit(str[i]))
      is_numeric = 0;
    i++;
  }
  return (is_numeric);
}

void  print_stack(t_stack *stack)
{
  printf("PRINTING THE STACK\n");
  int num;
  while ((num = pop(stack)) != -1)
  {
    printf("%d\n", num);
  }
}

int add_numbers(t_stack *stack, char *str)
{
  int i;
  int nums_added;
  int words_count;
  char  **args;

  printf("WILL GET NUMBERS AND ADD TO STACK FROM : %s\n", str);
  nums_added = 0;
  words_count = calc_words(str, ' ');
  args = ft_split(str, ' ');
  while (words_count--)
  {
    printf("%s\n", args[words_count]);
    if (is_numeric(args[words_count]))
      push(stack, ft_atoi(args[words_count]));
    else
      printf("Error\n");
  }
  return (nums_added);
}

void  fill_stack(t_stack *stack, int stack_len, char **argv, int argc)
{
  int number;

  init(stack);
  while (argc-- > 1 && stack_len)
    stack_len -= add_numbers(stack, argv[argc]);
  print_stack(stack);
}

