/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:30:47 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/29 11:32:44 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	split_stack(t_stack **a, t_stack **b)
{
	int	part;
	int	i;

	while (calc_size((*a)->head) > 3)
	{
		part = calc_size((*a)->head) / 2;
		i = 0;
		while (i < part)
		{
			if (calc_size((*a)->head) <= 3)
				break ;
			if ((*a)->head->index <= (part / 2) + calc_size((*b)->head))
			{
				pb(&(*a)->head, &(*b)->head);
				i++;
			}
			else if ((*a)->head->index <= part + calc_size((*b)->head))
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

void	push_to_b(t_stack **a, t_stack **b)
{
	if (!(*a)->head || !(*a)->head->next)
		return ;
	if (!(*b))
	{
		*b = malloc(sizeof(t_stack));
		if (!*b)
			return ;
	}
	index_stack_sorted(*a);
	split_stack(a, b);
	index_stack(*a);
	index_stack(*b);
	if ((*a)->size <= 3)
		sort_stack3(a);
	index_stack(*a);
	index_stack(*b);
}
