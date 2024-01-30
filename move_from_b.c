#include "push_swap.h"

/* Moves the nodes from stack B into A in the correct order, 
 * picking the cheapest node from the available */

void	move_to_top(t_n **a, t_n **b, t_n *cheapest)
{
	if (cheapest->above == true && cheapest->target->above == true)
	{
		while (*b != cheapest && *a != cheapest->target)
			rr(a, b);
	}
	else if (cheapest->above == false && cheapest->target->above == false)
	{
		while (*b != cheapest && *a != cheapest->target)
			rrr(a, b);
	}
	while (*b != cheapest)
	{
		if (cheapest->above == true)
			rb(b);
		else
			rrb(b);
	}
	while (*a != cheapest->target)
	{
		if (cheapest->target->above == true)
			ra(a);
		else
			rra(a);
	}
}	
