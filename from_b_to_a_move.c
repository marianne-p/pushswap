/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_to_a_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:09:23 by mpihur            #+#    #+#             */
/*   Updated: 2024/03/27 17:09:26 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrr_move_to_bigger_in_a(t_n **a, t_n **b, t_n *cheapest)
{
	if (cheapest->cost <= cheapest->bigger_target->cost)
	{
		while (cheapest->cost > 0)
		{
			rrr(a, b);
			cheapest->cost--;
		}
	}
	else
	{
		while (cheapest->bigger_target->cost > 0)
		{
			rrr(a, b);
			cheapest->bigger_target->cost--;
		}
	}
}

static void	rr_move_to_bigger_in_a(t_n **a, t_n **b, t_n *cheapest)
{
	if (cheapest->cost <= cheapest->bigger_target->cost)
	{
		while (cheapest->cost > 0)
		{
			rr(a, b);
			cheapest->cost--;
		}
	}
	else
	{
		while (cheapest->bigger_target->cost > 0)
		{
			rr(a, b);
			cheapest->bigger_target->cost--;
		}
	}
}

static void	rrr_move_to_smaller_in_a(t_n **a, t_n **b, t_n *cheapest)
{
	if (cheapest->cost <= (cheapest->smaller_target->cost - 1))
	{
		while (cheapest->cost > 0)
		{
			rrr(a, b);
			cheapest->cost--;
		}
	}
	else
	{
		cheapest->smaller_target->cost--;
		while (cheapest->smaller_target->cost > 0)
		{
			rrr(a, b);
			cheapest->smaller_target->cost--;
		}
	}
}

/* Is the smaller node at the end of list after rr's? 
 * Check the edge cases!! */
static void	rr_move_to_smaller_in_a(t_n **a, t_n **b, t_n *cheapest)
{
	if (cheapest->cost <= (cheapest->smaller_target->cost + 1))
	{
		while (cheapest->cost > 0)
		{
			rr(a, b);
			cheapest->cost--;
		}
	}
	else
	{
		while (cheapest->smaller_target->cost > 0)
		{
			rr(a, b);
			cheapest->smaller_target->cost--;
		}
	}
}

void	move_to_a(t_n **a, t_n **b, t_n *cheapest)
{
	if (cheapest->smaller_target == NULL && cheapest->above == true
		&& cheapest->bigger_target->above == true)
		rr_move_to_bigger_in_a(a, b, cheapest);
	else if (cheapest->smaller_target == NULL && cheapest->above == false
		&& cheapest->bigger_target->above == false)
		rrr_move_to_bigger_in_a(a, b, cheapest);
	else if (cheapest->bigger_target == NULL && cheapest->above == true
		&& cheapest->smaller_target->above == true)
		rr_move_to_smaller_in_a(a, b, cheapest);
	else if (cheapest->bigger_target == NULL && cheapest->above == false
		&& cheapest->smaller_target->above == false)
		rrr_move_to_smaller_in_a(a, b, cheapest);
	rotate_separately_target_a(a, b, cheapest);
	pa(a, b);
}
