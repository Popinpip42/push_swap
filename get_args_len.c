#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}

int ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int ft_isdigit(int c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int count_nums (char *arg)
{
  int i;
  int count;

  count= 0;
  i = 0;
  while (arg[i])
  {
    if (ft_isdigit(arg[i]))
    {
      while (ft_isdigit(arg[i]))
        i++;
      if (arg[i] == ' ' || arg[i] == '\0')
        count ++;
      else
        while (arg[i] && arg[i] != ' ')
          i++;
    }
    else
      i++;
  }
  return (count);
}

int get_args_len(int argc, char **argv)
{
  int total_count;
  int nums;
  int i;

  i = 0;
  total_count = 0;
  while (i < argc)
  {
    if ((nums = count_nums(argv[i])))
      total_count += nums;
    i++;
  }
  return (total_count);
}
