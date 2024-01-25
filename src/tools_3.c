/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:25:57 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/25 19:48:36 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_sorted(t_node *stack)
{
	t_node	*tmp;
	int		curr;
	
	tmp = stack;
	curr = tmp->value;
	while (tmp)
	{
		if (tmp->value < curr)
			return (0);
		curr = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}

void ft_free_nodes(t_stack **stack)
{
	t_node	*tmp;

	if (!(*stack) || !(*stack)->head)
		return ;
	tmp = (*stack)->head;
	while (tmp)
	{
		tmp = tmp->next;
		free((*stack)->head);
		(*stack)->head = tmp;
	}
	free(*stack);
}

int	stack_s_max(t_node *stack)
{
	int		max_value;
	t_node	*tmp;

	tmp = stack;
	max_value = tmp->value;
	while (tmp)
	{
		if (tmp->value > max_value)
			max_value = tmp->value;
		tmp = tmp->next;
	}
	return (max_value);
}

int	stack_s_min(t_node *stack)
{
	int		min_value;
	t_node	*tmp;

	tmp = stack;
	min_value = tmp->value;
	while (tmp)
	{
		if (tmp->value < min_value)
			min_value = tmp->value;
		tmp = tmp->next;
	}
	return (min_value);
}

void	sort_stack3(t_stack **stack)
{
	t_node	*node;
	
	node = (*stack)->head;
	if ((*stack)->size == 1)
		return ;
	if ((*stack)->size == 2)
	{
		if (node->value > node->next->value)
			sa(&(*stack)->head, 'n');
		return ;
	}
	else if ((*stack)->size == 3)
	{	
		if (node->value == stack_s_max(node))
			ra(&(*stack)->head, 'n');
		node = (*stack)->head;
		if (node->next->value == stack_s_max(node))
			rra(&(*stack)->head, 'n');
		node = (*stack)->head;
		if (node->value > node->next->value)
			sa(&(*stack)->head, 'n');
	}
	index_stack(*stack);
}
