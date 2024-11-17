#include "push_swap.h"

void	swap(t_stack *stack, char stack_name)
{
	int	old_top;
	int	new_top;

	if (stack->current_size < 2)
		return ;
	if (!pop(stack, &old_top))
		return ;
	if (!pop(stack, &new_top))
		return ;
	push(stack, old_top);
	push(stack, new_top);
	swap_ideal_indexes(stack, 0, 1);
	write(1, "s", 1);
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}

//TODO: I dont like this bullshit, it smells.... :D
void	push_from(t_stack *dst_s, t_stack *src_s, char dst_name)
{
	int	value;
	int	src_ideal_index;
	int	i;

	src_ideal_index = src_s->ideal_indexes[0];
	i = 0;
	while (i + 1 < src_s->current_size)
	{
		swap_ideal_indexes(src_s, i, i + 1);
		i++;
	}
	if (!pop(src_s, &value))
		return ;
	if (!push(dst_s, value))
		return ;
	i = dst_s->current_size - 1;
	while (i > 0)
	{
		swap_ideal_indexes(dst_s, i, i - 1);
		i--;
	}
	dst_s->ideal_indexes[0] = src_ideal_index;
	write(1, "p", 1);
	write(1, &dst_name, 1);
	write(1, "\n", 1);
}

void	rotate(t_stack *stack, char stack_name, int print_it)
{
	int	new_bottom;
	int	i;

	if (!pop(stack, &new_bottom))
		return ;
	push_back(stack, new_bottom);
	i = 0;
	while (i + 1 < stack->current_size)
	{
		swap_ideal_indexes(stack, i, i + 1);
		i++;
	}
	if (print_it)
	{
		write(1, "r", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	rrotate(t_stack *stack, char stack_name, int print_it)
{
	int	new_top;
	int	i;

	if (!pop_back(stack, &new_top))
		return ;
	push(stack, new_top);
	i = stack->current_size - 1;
	while (i > 0)
	{
		swap_ideal_indexes(stack, i, i - 1);
		i--;
	}
	if (print_it)
	{
		write(1, "rr", 2);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}
