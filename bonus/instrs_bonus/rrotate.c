/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:26:01 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/29 22:30:35 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	rrotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *stack;
	*stack = tmp2;
}

void	rra(t_node **stack, char c)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	rrotate(stack);
	if (c == 'y')
		return ;
}

void	rrb(t_node **stack, char c)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	rrotate(stack);
	if (c == 'y')
		return ;
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a && (*stack_a)->next) || (*stack_b && (*stack_b)->next))
	{
		rra(stack_a, 'y');
		rrb(stack_b, 'y');
	}
}
