#include "push_swap.h"

void	rotate_a_in_order(t_n **a, t_n *min, size_t size)
{
	count_cost(*a, size);
	if (min->above == true)
	{
		while (*a != min)
			ra(a);
	}
	else
	{
		while (*a != min)
			rra(a);
	}
}
