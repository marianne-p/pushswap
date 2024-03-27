/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_to_b_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:06:22 by mpihur            #+#    #+#             */
/*   Updated: 2024/03/27 17:06:30 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_both_above(t_n **a, t_n **b, t_n *cheapest)
{
	if (cheapest->cost <= cheapest->smaller_target->cost)
	{
		while (cheapest->cost > 0)
		{
			rr(a, b);
			cheapest->cost--;
		}
		while (*b != cheapest->smaller_target)
			rb(b);
	}
	else
	{
		while (cheapest->smaller_target->cost > 0)
		{
			rr(a, b);
			cheapest->smaller_target->cost--;
		}
		while (*a != cheapest)
			ra(a);
	}
}

void	rrr_both_below(t_n **a, t_n **b, t_n *cheapest)
{
	if (cheapest->cost <= cheapest->smaller_target->cost)
	{
		while (cheapest->cost > 0)
		{
			rrr(a, b);
			cheapest->cost--;
		}
		while (*b != cheapest->smaller_target)
			rrb(b);
	}
	else
	{
		while (cheapest->smaller_target->cost > 0)
		{
			rrr(a, b);
			cheapest->smaller_target->cost--;
		}
		while (*a != cheapest)
			rra(a);
	}
}

void	rr_above_big_target(t_n **a, t_n **b, t_n *cheapest)
{
	if (cheapest->cost <= cheapest->bigger_target->cost)
	{
		while (cheapest->cost > 0)
		{
			rr(a, b);
			cheapest->cost--;
		}
		while (find_last_node(*b) != cheapest->bigger_target)
			rb(b);
	}
	else
	{
		while (cheapest->bigger_target->cost > 0)
		{
			rr(a, b);
			cheapest->bigger_target->cost--;
		}
		rb(b);
		while (*a != cheapest)
			ra(a);
	}
}

void	rrr_below_big_target(t_n **a, t_n **b, t_n *cheapest)
{
	if (cheapest->cost <= cheapest->bigger_target->cost - 1)
	{
		while (cheapest->cost > 0)
		{
			rrr(a, b);
			cheapest->cost--;
		}
		while (find_last_node(*b) != cheapest->bigger_target)
			rrb(b);
	}
	else
	{
		while (cheapest->bigger_target->cost > 0)
		{
			rrr(a, b);
			cheapest->bigger_target->cost--;
		}
		rb(b);
		while (*a != cheapest)
			rra(a);
	}
}

void	move_to_b(t_n **a, t_n **b, t_n *cheapest)
{
	if (cheapest->above == true && cheapest->bigger_target == NULL
		&& cheapest->smaller_target->above == true)
		rr_both_above(a, b, cheapest);
	else if (cheapest->above == false && cheapest->bigger_target == NULL
		&& cheapest->smaller_target->above == false)
		rrr_both_below(a, b, cheapest);
	else if (cheapest->smaller_target == NULL && cheapest->above == true
		&& cheapest->bigger_target->above == true)
		rr_above_big_target(a, b, cheapest);
	else if (cheapest->smaller_target == NULL && cheapest->above == false
		&& cheapest->bigger_target->above == false)
		rrr_below_big_target(a, b, cheapest);
	else
		rotate_separately(a, b, cheapest);
	pb(a, b);
}
