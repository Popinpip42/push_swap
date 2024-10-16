#include "push_swap.h"

int is_space_char(int c)
{
  return c == ' ';
}

int add_numbers(t_stack *stack, char *str)
{
  int i;
  int nums_added;
  int words_count;
  char  **args;

  nums_added = 0;
  words_count = calc_words(str, &is_space_char);
  args = split_on(str, &is_space_char);
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
  clean_matrix(args);
  return (nums_added);
}

int get_ideal_index(int *sorted_nbs, int value)
{
  int i;

  i = 0;
  while (value != sorted_nbs[i])
    i++;
  //TODO: stack->top will always be or (Origin) for sorting
  //TODO: The stack node, passed as value, wants to be at (stack->top + i) 
  return (i);
}

int  get_ideal_indexes(t_stack *stack, int size, int *sorted_nums)
{
  int *ideal_indexes;
  int current_value;
  int j;

  ideal_indexes = (int *)malloc(size * sizeof(int));
  if (!ideal_indexes)
    return (0);
  stack->ideal_indexes = ideal_indexes;
  j = 0;
  while (stack->items[stack->top - j] > stack->items[stack->bottom + 1])
  {
    current_value = stack->items[stack->top - j];
    stack->ideal_indexes[j] = get_ideal_index(sorted_nums, current_value);
    j++;
  }
  return (1);
}

void  sort_(int *nums, int n)
{
  int key;
	int i;
	int j;

	i = 1;
	while (i < n)
	{
		key = nums[i];
		j = i - 1;
		while (j >= 0 && nums[j] > key)
		{
			nums[j + 1] = nums[j];
			j = j - 1;
		}
		nums[j + 1] = key;
		i++;
	}
}

int fill_stacks(t_stack *stack_a, t_stack *stack_b, int arg_count, char **argv, int argc)
{
  int numbers_added;
  int *sorted_numbers;
  int i;

  sorted_numbers = (int *)malloc(arg_count * sizeof(int));
  if (!sorted_numbers)
    return (-1);
  i = 1;
  while (i < argc && arg_count > 0)
  {
    numbers_added = add_numbers(stack_a, argv[i]);
    if (numbers_added == -1)
      return (free(sorted_numbers), -1);
    arg_count -= numbers_added;
    i++;
  }
  //COPY stack_a items to sorted_nums
  printf("%d - %d\n", stack_a->top, stack_a->bottom);
  int aux = 0;
  while (stack_a->top - aux > stack_a->bottom +1)
  {
    sorted_numbers[aux] = stack_a->items[stack_a->top - 1 - aux];
    aux++;
  }
  if (stack_a->current_size > 0)
  {
    //sort_(sorted_numbers, arg_count);
    for (int i = 0; i < arg_count; i++)
      printf("Sorted nums ITEM[%d] - %d\n", i+1, sorted_numbers[i]);
    sort_(sorted_numbers, arg_count);
    /*
    if (!get_ideal_indexes(stack_a, arg_count, sorted_numbers)
        || !get_ideal_indexes(stack_b, arg_count, sorted_numbers))
      return (free(sorted_numbers), -1);
    */
  }
  //TODO: change the return value for a valid erorr or success value
  return (free(sorted_numbers), arg_count);
}
