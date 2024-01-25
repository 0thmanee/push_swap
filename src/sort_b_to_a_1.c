/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:35:29 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/25 19:48:18 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_target(t_stack *a, t_stack *b, t_node *tmp)
{
	t_node	*tmp2;
	
	if (tmp->index <= b->size / 2)
		tmp->cost = tmp->index;
	else
		tmp->cost = b->size - tmp->index;
	tmp2 = a->head;
	tmp->target = tmp;
	while (tmp2)
	{
		if (tmp2->value > tmp->value && tmp->value == tmp->target->value)
			tmp->target = tmp2;
		if (tmp2->value > tmp->value && tmp2->value < tmp->target->value)
			tmp->target = tmp2;
		tmp2 = tmp2->next;
	}
}

t_node	*find_cheapest_in_a(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	t_node	*cheap;

	tmp = b->head;
	cheap = tmp;
	while (tmp)
	{
		find_target(a, b, tmp);
		if (tmp->value != tmp->target->value && tmp->target->index != 1)
		{
			if (tmp->target->index <= a->size / 2)
				tmp->cost += tmp->target->index;
			else
				tmp->cost += (a->size - tmp->target->index);
		}
		else if (tmp->value == tmp->target->value && tmp->index > b->size / 2)
			tmp->cost++;
		if (tmp->cost < cheap->cost)
			cheap = tmp;
		tmp = tmp->next;
	}
	return (cheap);
}

void	find_cheapest_for_no_targ(t_stack *a, t_stack *b, t_node *tmp)
{
	t_node	*tmp2;

	tmp2 = a->head;
	tmp->target = tmp2;
	while (tmp2)
	{
		if (tmp2->value < tmp->target->value)
			tmp->target = tmp2;
		tmp2 = tmp2->next;
	}
	if (tmp->value != tmp->target->value && tmp->target->index != 1)
	{
		if (tmp->target->index <= a->size / 2)
			tmp->cost += tmp->target->index;
		else
			tmp->cost += (a->size - tmp->target->index);
	}
	else if (tmp->value == tmp->target->value && tmp->index > b->size / 2)
		tmp->cost++;
}

t_node	*get_min_node(t_node *stack)
{
	t_node	*min_node;
	t_node	*tmp;

	tmp = stack;
	min_node = tmp;
	while (tmp)
	{
		if (tmp->value < min_node->value)
			min_node = tmp;
		tmp = tmp->next;
	}
	return (min_node);
}

void	bring_smallest(t_stack **a)
{
	t_node	*tmp;
	int		i;
	
	tmp = get_min_node((*a)->head);
	if (tmp->index <= (*a)->size / 2)
	{
		i = tmp->index;
		while (i > 0)
		{
			ra(&(*a)->head, 'n');
			i--;
		}
	}
	else
	{
		i = (*a)->size - tmp->index;
		while (i > 0)
		{
			rra(&(*a)->head, 'n');
			i--;
		}
	}
}
