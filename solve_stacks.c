#include "push_swap.h"

int	get_msb(int n)
{
	int	msb;

	if (n == 0)
		return (0);
	msb = 0;
	while (n)
	{
		msb++;
		n >>= 1;
	}
	return (msb);
}

int	m_sqrt(int n)
{
	int	a;
	int	result;

	a = 1 << get_msb(n);
	result = 0;
	while (a != 0)
	{
		if ((result + a) * (result + a) <= n)
			result += a;
		a >>= 1;
	}
	return (result);
}

void	print_stacks(t_stack *stack1, t_stack *stack2)
{
	printf("STACK_A\n");
	print_stack(*stack1);
	printf("STACK_B\n");
	print_stack(*stack2);
}

int	count_r(t_stack *stack, int s_index)
{
	int	counter;
	int	current_ideal_index;

	counter = 0;
	while (counter < stack->current_size)
	{
		//This start comparing from the ideal_indexes array
		//-- The TOP ELEMENT CORRESPONDS TO (0) FROM IDEAL_INDEXES
		current_ideal_index = stack->ideal_indexes[counter];
		if (current_ideal_index == s_index)
			break ;
		counter++;
	}
	return (counter);
}

void  solve_stacks(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	s_index;
	int	range;
	int	j;
	int	current_value;

	range = m_sqrt(stack_a->current_size);
	//printf("Stack_a size : %d - Range %d\n", stack_a->current_size, range);

	//TODO: Ksort-1 --- (Move by chunks to the aux stack)
	//Distribution of elements from stack_a to stack_b
	s_index = 0;
	j = 0;
	while (stack_a->current_size > 0)
	{
		current_value = stack_a->ideal_indexes[0];
		if (current_value <= s_index)
		{
			push_from(stack_b, stack_a, 'b');
			s_index++;
		}
		else if (current_value <= s_index + range)
		{
			push_from(stack_b, stack_a, 'b');
			s_index++;
			if (!(current_value <= s_index + range))
				rotate_stacks(stack_a, stack_b);
			else
				rotate(stack_b, 'b', 1);
		}
		else
			rotate(stack_a, 'a', 1);
	}

	//TODO: Kosrt-2 --- (Move back to main stack depending on a cost function of nodes)
	int rb_count;
	int rrb_count;
	int curr_index;

	/*
  printf("\n==== Printing stacks_b ideal_indexes from ksort-2\n");
  for (int a = 0; a < stack_b->current_size; a++)
	printf("Ideal_Index_stack_a Item[%d] - %d\n", a+1, stack_b->ideal_indexes[a]);
  */
	while (length - 1 >= 0)
	{
		//length is our valid_args_len
		rb_count = count_r(stack_b, length - 1);
		rrb_count = (length + 3) - rb_count;
		curr_index = 0;
		//printf("rb_count %d, rrb_count %d\n", rb_count, rrb_count);
		if (rb_count <= rrb_count)
		{
			while (stack_b->ideal_indexes[curr_index] != length - 1)
				rotate(stack_b, 'b', 1);
			push_from(stack_a, stack_b, 'a');
			length--;
		}
		else
		{
			while (stack_b->ideal_indexes[curr_index] != length - 1)
				rrotate(stack_b, 'b', 1);
			push_from(stack_a, stack_b, 'a');
			length--;
		}
	}
}

//TODO: CODE FOR DEBUGGING Ksort-1
/*
  int s_index;
  int range = m_sqrt(stack_a->current_size);
  printf("Stack_a size : %d - Range %d\n", stack_a->current_size, range);

  s_index = 0;
  int current_value;
  //while (stack_a->top - 1 -j > stack_a->bottom + 1)
  //while (j < stack_a->current_size)
  while (stack_a->current_size > 0)
  {
    current_value = stack_a->ideal_indexes[0];
    printf("\n--- current_value %d - s_index %d - s_index+range %d\n", current_value, s_index, s_index + range);
    if (current_value <= s_index)
    {
      push_from(stack_b, stack_a);
      s_index++;
    }
    else if (current_value <= s_index + range)
    {
      push_from(stack_b, stack_a);
      s_index++;
      if (!(current_value <= s_index + range))
      {
        rotate(stack_a);
        rotate(stack_b);
      }
      else {
        rotate(stack_b);
      }
    }
    else
      rotate(stack_a);

    printf("\n==== stack_a size : %d\n", stack_a->current_size);
    printf("==== Printing stacks_a from main call \n");
    print_stack(*stack_a);
    printf("==== stack_b size : %d\n", stack_b->current_size);
    printf("==== Printing stacks_b from main call \n");
    print_stack(*stack_b);

    printf("==== Printing ideal_indexes stack_a\n");
    int q;
    for (q = 0; q < stack_a->current_size; q++)
      printf("Ideal index s_a : %d\n", stack_a->ideal_indexes[q]);
    printf("==== Printing ideal_indexes stack_b\n");
    for (q = 0; q < stack_b->current_size; q++)
      printf("Ideal index s_b : %d\n", stack_b->ideal_indexes[q]);
  }
*/

//TODO: Currently testing with :
//./a.out "aefa" asdfa 11 22a12 "2223 123a1 asdf 33 aa" "adf- as 44" " " "adsfadzxc_ asfd _ 55 a " 44 55
//TODO: AND TESTING BY ADding NUM 100 items to the "stack" haha
