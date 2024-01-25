/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:35:29 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/25 19:48:15 by obouchta         ###   ########.fr       */
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
	t_node	*tmp;

	tmp = find_cheapest_in_a(*a, *b);
	if (tmp->value == tmp->target->value)
		find_cheapest_for_no_targ(*a, *b, tmp);
	if (tmp->index <= (*b)->size / 2 && tmp->target->index <= (*a)->size / 2)
		rotate_both(a, b, tmp);
	else if (tmp->index > (*b)->size / 2 && tmp->target->index > (*a)->size / 2)
		rrotate_both(a, b, tmp);
	else if (tmp->index <= (*b)->size / 2 && tmp->target->index > (*a)->size / 2)
		rb_rra(a, b, tmp);
	else if (tmp->index > (*b)->size / 2 && tmp->target->index <= (*a)->size / 2)
		rrb_ra(a, b, tmp);
	index_stack(*a);
	index_stack(*b);
	pa(&(*a)->head, &(*b)->head);
}

