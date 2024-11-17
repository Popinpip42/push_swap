#include "push_swap.h"

void	rrotate_stacks(t_stack *stack_a, t_stack *stack_b)
{
	rrotate(stack_a, 'a', 0);
	rrotate(stack_b, 'b', 0);
	write(1, "rrr\n", 3);
}

void	rotate_stacks(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, 'a', 0);
	rotate(stack_b, 'b', 0);
	write(1, "rr\n", 3);
}
