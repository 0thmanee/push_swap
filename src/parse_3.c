/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:25:57 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/30 00:21:52 by obouchta         ###   ########.fr       */
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

void	free_nodes(t_stack **stack)
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

static	void sort_3(t_stack **stack)
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

static	void sort_5(t_stack **a, t_stack **b)
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
