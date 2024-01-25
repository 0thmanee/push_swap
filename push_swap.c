/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:03:01 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/25 19:39:32 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_stack **a, t_stack **b)
{
	while ((*b)->size > 0)
	{
		find_place_in_a(a, b);
		index_stack(*a);
		index_stack(*b);
	}
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	a = malloc(sizeof(t_stack));
	if (!a)
		return (1);
	b = malloc(sizeof(t_stack));
	if (!b)
		return (1);
	if (ac == 1)
		exit(EXIT_FAILURE);
	if (!valid_args(ac, av, &a))
		exit(EXIT_FAILURE);
	index_stack(a);
	if (stack_sorted(a->head) || a->size <= 3)
	{
		sort_stack3(&a);
		exit(EXIT_SUCCESS);
	}
	push_to_b(&a, &b);
	push_to_a(&a, &b);
	bring_smallest(&a);
	exit(EXIT_SUCCESS);
	return (0);
}