#include "push_swap.h"

int	is_num_repeated(int index, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i != index && arr[i] == arr[index])
			return (1);
		i++;
	}
	return (0);
}

int	*filter_(int *int_arr, int *len, t_filter_func filter)
{
	int	temp[*len];
	int	count;
	int	*filtered_arr;
	int	i;

	count = 0;
	i = 0;
	while (i < *len)
	{
		if (!filter(i, int_arr, i))
			temp[count++] = int_arr[i];
		i++;
	}
	filtered_arr = malloc(count * sizeof(int));
	if (!filtered_arr)
		return (NULL);
	i = 0;
	while (i < count)
	{
		filtered_arr[i] = temp[i];
		i++;
	}
	*len = count;
	free(int_arr);
	return (filtered_arr);
}
