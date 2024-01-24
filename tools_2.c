/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:24:58 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/24 16:29:28 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stack1(t_stack *stack, char *name)
{
    t_node    *current;

    printf("------ %s ------\n", name);
    current = stack->head;
	printf("Size: %d	      |\n", stack->size);
    printf("--------------- \n");
    while (current != NULL)
    {
        printf("|index: %d value: %d cost: %d\n", current->index, current->value, current->cost);
        current = current->next;
    }
    printf("---------------\n\n\n");
}

void    print_stack2(t_stack *stack, char *name)
{
    t_node    *current;

    printf("------ %s ------\n", name);
    current = stack->head;
	printf("Size: %d	      |\n", stack->size);
    printf("--------------- \n");
    while (current)
    {
        printf("|index: %d value: %d cost: %d target: %d\n", current->index, current->value, current->cost, current->target->value);
        current = current->next;
    }
    printf("---------------\n\n\n");
}

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

t_node	*stack_s_min(t_node *stack)
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
}

void free_nodes(t_node **node)
{
	t_node	*tmp;
	t_node	*next;

	tmp = *node;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	node = NULL;
}
