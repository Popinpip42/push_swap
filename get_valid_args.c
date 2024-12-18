#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_overflowing(long result, int digit, int sign)
{
	if (sign == 1 && result > (INT_MAX - digit) / 10)
		return (1);
	if (sign == -1 && result > ((-1L * INT_MIN) - digit) / 10)
		return (1);
	return (0);
}

int	is_valid_num(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (!isdigit(*str))
		return (0);
	while (isdigit(*str))
	{
		if (is_overflowing(result, (*str - '0'), sign))
			return (0);
		result = result * 10 + (*str - '0');
		str++;
	}
	while (isspace(*str))
		str++;
	return (*str == '\0');
}

//TODO: This shit counts numbers. IDK What to do with it
int	count_arg(char *arg, t_validation_func validate)
{
	char	**split_arg;
	int		count;
	int		i;

	count = 0;
	split_arg = split_on(arg, &isspace);
	if (!split_arg)
		return (-1);
	i = 0;
	while (split_arg[i] != NULL)
	{
		if (validate(split_arg[i]))
			count++;
		i++;
	}
	clean_matrix(split_arg);
	return (count);
}

int	get_valid_args_count(int argc, char **argv, t_validation_func validate)
{
	int	i;
	int	total_count;
	int	validated_count;

	total_count = 0;
	i = 1;
	while (i < argc)
	{
		validated_count = count_arg(argv[i], validate);
		if (validated_count == -1)
			return (-1);
		total_count += validated_count;
		i++;
	}
	return (total_count);
}

//TODO: Reimplementing this sht...
//TODO: maybe we can pass the transformation function as well, in this case (atoi())
//Could also pass (strdup())
//TODO: REVIEW FT_ATOI FUNCTION
int	validate_and_get(char *arg, t_validation_func validate, int *valid_args)
{
	char	**split_arg;
	int		count;
	int		i;

	count = 0;
	split_arg = split_on(arg, &isspace);
	if (!split_arg)
		return (-1);
	i = 0;
	while (split_arg[i] != NULL)
	{
		if (validate(split_arg[i]))
		{
			valid_args[count] = ft_atoi(split_arg[i]);
			count++;
		}
		else
			printf("-- Error on args %s\n", split_arg[i]);
		i++;
	}
	clean_matrix(split_arg);
	return (count);
}

int	*get_valid_args(int argc, char **argv, t_validation_func validate, int *valid_args_size)
{
	int	*valid_args;
	int	count;
	int	i;
	int	total_count;

	//TODO: add a variable to control get_valid_args_count return value (-1)
	valid_args = malloc(get_valid_args_count(argc, argv, validate) * sizeof(int));
	if (!valid_args)
		return (NULL);
	total_count = 0;
	i = 1;
	while (i < argc)
	{
		count = validate_and_get(argv[i], validate, valid_args + total_count);
		if (count == -1)
			return (free(valid_args), NULL);
		total_count += count;
		i++;
	}
	*valid_args_size = total_count;
	return (valid_args);
}

/*
 * Functions that validates and argv_item, 
 * based on the function passed as argument
 * - Currently working only with spaces
 */
/*  CACA ---- :_D  CACA ---- :_D
int validate_arg(char *arg, int (*validation_func)(const char *))
{
  int   valid_count;
  char  **split_arg;
  int   i;

  valid_count = 0;
  split_arg = split_on(arg, &isspace);
  if (!split_arg)
    return (-1);
  i = 0;
  while (split_arg[i] != NULL)
  {
    if (validation_func(split_arg[i]))
      valid_count++;
    i++;
  }
  clean_matrix(split_arg);
  return (valid_count);
}

//TODO: is_valid_num funcitons is harcoded
int get_valid_args_count(int argc, char **argv, int (*validation_func)(const char *))
{
  int   total_count;
  int   nums;
  int   i;
  //TODO: Have an (void *) array that keeps track of the parsed args
  //We might want to return this array 
  //and cast it propperly ouside of this functions

  i = 1;
  total_count = 0;
  while (i < argc)
  {
    if ( (nums = validate_arg(argv[i], validation_func) == -1 ) )
      return (-1);
    total_count += nums;
    i++;
  }
  return (total_count);
}
*/

/*
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
*/
