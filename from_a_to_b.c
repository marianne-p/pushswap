#include "push_swap.h"

void	put_nulls(t_n *head, char c)
{
	if (c == 'b')
	{
		while (head)
		{
			head->bigger_target = NULL;
			head = head->next;
		}
	}
	else if (c == 's')
	{
		while (head)
		{
			head->smaller_target = NULL;
			head = head->next;
		}
	}
}

/* Looks for closest smaller node inside stack B
 * to place the newly pushed node on top of it (pb) */
static void	find_smaller_target_in_b(t_n *a, t_n *b, size_t i, t_n **b_cpy)
{
	while (a)
	{
		while (b)
		{
			if ((a->i - b->i) > 0 && (a->i - b->i) < i)
			{
				i = a->i - b->i;
				a->smaller_target = b;
			}
			b = b->next;
		}
		a = a->next;
		b = *b_cpy;
		i = SIZE_MAX;
	}					
}

/* Counts total cost of moves to find the optimal move from stack A to B*/
static t_n	*pick_cheapest(t_n **a_cpy, t_n *a, t_n *cheapest, size_t lowest)
{
	while (a)
	{
		a->total_cost = a->cost + a->smaller_target->cost;
		a->bigger_target = NULL;
		a = a->next;
	}
	a = *a_cpy;
	while (a)
	{
		if (a->total_cost < lowest)
		{
			lowest = a->total_cost;
			cheapest = a;
		}
		a = a->next;
	}
	return (cheapest);
}

/* Stack B contains 3 nodes sorted in descending order (3 to 1).
 * This function pushes nodes from A to B preserving the order.
 * It counts the cheapest way to do it by:
 * 	1) Counting the cost to bring node up (a->price)
 * 	2) Finding the two closest nodes (smaller and bigger)
 * Then it calculates total operations count and chooses 
 * the optimal way  to push into stack B
 *
 * Note:
 * 	3, 2, 1 is descending order
 * rrb	1, 3, 2
 * rrb	2, 1, 3 
 * rrb	3, 2, 1 is descending order
 * rb	2, 1, 3
 * rb	1, 3, 2
 * rb	3, 2, 1 is descending order
 * ! Smallest shold be followed by Biggest !
 * Ascending = {...Big-1, Biggest, Smallest, Sm+1,...} */

void	from_a_to_b(t_n **a, t_n **b, t_n *cheapest_a)
{
	while (count_nodes(*a, 0) > 3)
	{
		count_cost(*a, count_nodes(*a, 0));
		count_cost(*b, count_nodes(*b, 0));
		//find_bigger_target_in_b(*a, *b, SIZE_MAX, b);
		put_nulls(*a, 'b');
		find_smaller_target_in_b(*a, *b, SIZE_MAX, b);
		cheapest_a = pick_cheapest(a, *a, NULL, SIZE_MAX);
		move_to_b(a, b, cheapest_a);
	}
}
