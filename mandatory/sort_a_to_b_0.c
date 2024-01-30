/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:30:47 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/30 23:07:45 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	all_indexed(t_node *node)
{
	t_node	*tmp;

	tmp = node;
	while (tmp)
	{
		if (tmp->index == -1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	calc_size(t_node *node)
{
	t_node	*tmp;
	int		len;

	tmp = node;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	stack_custom_min(t_node *stack)
{
	int		min_value;
	t_node	*tmp;

	tmp = stack;
	min_value = INT_MIN;
	while (tmp)
	{
		if (min_value == INT_MIN && tmp->index == -1)
			min_value = tmp->value;
		if (tmp->value <= min_value && tmp->index == -1)
			min_value = tmp->value;
		tmp = tmp->next;
	}
	return (min_value);
}

void	index_stack_sorted(t_stack *stack)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		ind;

	tmp = stack->head;
	while (tmp)
	{
		tmp2 = stack->head;
		ind = 0;
		while (tmp2)
		{
			if (tmp->value > tmp2->value)
				ind++;
			tmp2 = tmp2->next;
		}
		tmp->index = ind;
		tmp = tmp->next;
	}
}
