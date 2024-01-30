/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:30:47 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/30 23:08:50 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack **stack)
{
	t_node	*node;

	node = (*stack)->head;
	if (node->value == stack_s_max(node))
		ra(&(*stack)->head, 'n');
	node = (*stack)->head;
	if (node->next->value == stack_s_max(node))
		rra(&(*stack)->head, 'n');
	node = (*stack)->head;
	if (node->value > node->next->value)
		sa(&(*stack)->head, 'n');
}

static void	sort_5(t_stack **a, t_stack **b)
{
	index_stack_sorted(*a);
	while (calc_size((*a)->head) > 3)
	{
		if ((*a)->head->index == 0 || (*a)->head->index == 1)
			pb(&(*a)->head, &(*b)->head);
		else
			ra(&(*a)->head, 'n');
	}
	sort_3(a);
	if ((*b)->head->value < (*b)->head->next->value)
		rb(&(*b)->head, 'n');
	pa(&(*a)->head, &(*b)->head);
	pa(&(*a)->head, &(*b)->head);
}

void	magic_sort(t_stack **a, t_stack **b)
{
	if ((*a)->size == 1)
		return ;
	if ((*a)->size == 2)
	{
		if ((*a)->head->value > (*a)->head->next->value)
			sa(&(*a)->head, 'n');
		return ;
	}
	else if ((*a)->size == 3)
		sort_3(a);
	else if ((*a)->size == 5)
		sort_5(a, b);
	index_stack(*a);
}

void	split_stack(t_stack **a, t_stack **b)
{
	int	half;
	int	i;

	while (calc_size((*a)->head) > 3)
	{
		half = calc_size((*a)->head) / 2;
		i = 1;
		while (i < half && calc_size((*a)->head) > 3)
		{
			if ((*a)->head->index <= (half / 2) + calc_size((*b)->head))
			{
				pb(&(*a)->head, &(*b)->head);
				i++;
			}
			else if ((*a)->head->index <= half + calc_size((*b)->head))
			{
				pb(&(*a)->head, &(*b)->head);
				rb(&(*b)->head, 'n');
				i++;
			}
			else
				ra(&(*a)->head, 'n');
		}
	}
}
