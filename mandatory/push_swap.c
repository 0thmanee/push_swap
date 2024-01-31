/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:03:01 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/31 20:21:11 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_both(char **strs, t_stack **a)
{
	free_nodes(a);
	free_strs(strs);
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
		magic_sort(a, b);
	index_stack(*a);
	index_stack(*b);
}

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
		exit(EXIT_FAILURE);
	b = malloc(sizeof(t_stack));
	if (!b)
		exit(EXIT_FAILURE);
	if (ac == 1)
		exit(EXIT_FAILURE);
	if (!valid_args(ac, av, &a))
		exit(EXIT_FAILURE);
	index_stack(a);
	if (stack_sorted(a->head) || a->size <= 3 || a->size == 5)
	{
		magic_sort(&a, &b);
		exit(EXIT_SUCCESS);
	}
	push_to_b(&a, &b);
	push_to_a(&a, &b);
	bring_smallest(&a);
	exit(EXIT_SUCCESS);
}
