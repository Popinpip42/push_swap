#include "push_swap.h"

//TODO: REVIEW THIS FUNCION - MAYBE WE DONT NEED TO RETURN LONG
long ft_atoi(const char *str)
{
  long  num;
  int sign;

  sign = 1;
  while (*str == ' ' || (*str >= 9 && *str <= 13))
    str++;
  while (*str == '+' || *str == '-')
  {
    if (*str == '-')
      sign = -1;
    str++;
  }
  num = 0;
  while (ft_isdigit(*str))
  {
    num = num * 10 + (*str - '0');
    str++;
    if (sign == 1 && num > (long)INT_MAX)
      return (LONG_MAX);
    if (sign == -1 && num > -(long)INT_MIN)
      return (LONG_MIN);
  }
  return (num * sign);
}

int is_numeric(char *str)
{
  int is_numeric;
  int i;

  i = 0;
  is_numeric = 1;
  while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
    i++;
  while (str[i] == '+' || str[i] == '-')
    i++;
  while (str[i])
  {
    if (!ft_isdigit(str[i]))
      is_numeric = 0;
    i++;
  }
  return (is_numeric);
}

int is_repeated(int value, t_stack stack)
{
  int i;

  i = 0;
  while ((stack.top - i) > (stack.bottom + 1))
  {
    if (stack.items[stack.top - 1 - i] == value)
      return (1);
    i++;
  }
  return (0);
}

int is_valid(char *str, t_stack *stack)
{
  long num;

  if (is_numeric(str))
  {
    num = ft_atoi(str);
    if (num == LONG_MAX || num == LONG_MIN || is_repeated((int)num, *stack))
      return (0);
    return (1);
  }
  return (0);
}
