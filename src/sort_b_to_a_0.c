/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:35:29 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/25 20:56:46 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_node *cheap)
{
	int		i;
	int		j;

	i = cheap->index;
	j = cheap->target->index;
	while (i > 0 && j > 0)
	{
		rr(&(*a)->head, &(*b)->head);
		i--;
		j--;
	}
	while (i > 0)
	{
		rb(&(*b)->head, 'n');
		i--;
	}
	while (j > 0)
	{
		ra(&(*a)->head, 'n');
		j--;
	}
}

void	rrotate_both(t_stack **a, t_stack **b, t_node *cheap)
{
	int		i;
	int		j;

	i = (*b)->size - cheap->index;
	j = (*a)->size - cheap->target->index;
	while (i > 0 && j > 0)
	{
		rrr(&(*a)->head, &(*b)->head);
		i--;
		j--;
	}
	while (i > 0)
	{
		rrb(&(*b)->head, 'n');
		i--;
	}
	while (j > 0)
	{
		rra(&(*a)->head, 'n');
		j--;
	}
}

void	rb_rra(t_stack **a, t_stack **b, t_node *cheap)
{
	int		i;

	i = cheap->index;
	while (i > 0)
	{
		rb(&(*b)->head, 'n');
		i--;
	}
	i = (*a)->size - cheap->target->index;
	while (i > 0)
	{
		rra(&(*a)->head, 'n');
		i--;
	}
}

void	rrb_ra(t_stack **a, t_stack **b, t_node *cheap)
{
	int		i;

	i = (*b)->size - cheap->index;
	while (i > 0)
	{
		rrb(&(*b)->head, 'a');
		i--;
	}
	i = cheap->target->index;
	while (i > 0)
	{
		ra(&(*a)->head, 'n');
		i--;
	}
}

void	find_place_in_a(t_stack **a, t_stack **b)
{
	t_node	*nd;

	nd = find_cheapest_in_a(*a, *b);
	if (nd->value == nd->target->value)
		find_cheapest_for_no_targ(*a, *b, nd);
	if (nd->index <= (*b)->size / 2 && nd->target->index <= (*a)->size / 2)
		rotate_both(a, b, nd);
	else if (nd->index > (*b)->size / 2 && nd->target->index > (*a)->size / 2)
		rrotate_both(a, b, nd);
	else if (nd->index <= (*b)->size / 2 && nd->target->index > (*a)->size / 2)
		rb_rra(a, b, nd);
	else if (nd->index > (*b)->size / 2 && nd->target->index <= (*a)->size / 2)
		rrb_ra(a, b, nd);
	index_stack(*a);
	index_stack(*b);
	pa(&(*a)->head, &(*b)->head);
}
