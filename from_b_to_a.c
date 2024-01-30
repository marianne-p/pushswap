#include "push_swap.h"

static void	find_bigger_target_in_a(t_n *a, t_n *b, size_t i, t_n **a_cpy)
{
	while (b)
	{
		while (a)
		{
			if ((a->i - b->i) > 0 && (a->i - b->i) < i)
			{
				i = a->i - b->i;
				b->bigger_target = a;
			}
			a = a->next;
		}
		b = b->next;
		a = *a_cpy;
		i = SIZE_MAX;
	}				
}
/*
static void	find_smaller_target_in_a(t_n *a, t_n *b, size_t i, t_n **a_cpy)
{
	while (b)
	{
		while (a)
		{
			if ((b->i - a->i) > 0 && (b->i - a->i) < i)
			{
				i = b->i - a->i;
				b->smaller_target = a;
			}
			a = a->next;
		}
		b = b->next;
		a = *a_cpy;
		i = SIZE_MAX;
	}					
}*/

static t_n	*pick_cheapest_b_to_a(t_n **b_cpy, t_n *b, t_n *cheapest, size_t lowest)
{
	while (b)
	{
		b->total_cost = b->cost + b->bigger_target->cost;
		b->smaller_target = NULL;
		b = b->next;
	}
	b = *b_cpy;
	while (b)
	{
		if (b->total_cost < lowest)
		{
			lowest = b->total_cost;
			cheapest = b;
		}
		b = b->next;
	}
	return (cheapest);
}

void	from_b_to_a(t_n **a, t_n **b, t_n *cheapest_b)
{
	while (*b != NULL)
	{
		count_cost(*a, count_nodes(*a, 0));
		count_cost(*b, count_nodes(*b, 0));
		find_bigger_target_in_a(*a, *b, SIZE_MAX, a);
		put_nulls(*b, 's');
		if (!(*b)->next)
			cheapest_b = *b;
		else
			cheapest_b = pick_cheapest_b_to_a(b, *b, NULL, SIZE_MAX);
		move_to_a(a, b, cheapest_b);
	}
}
