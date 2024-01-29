/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:35:05 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/28 18:45:25 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (stack_sorted(a->head) || a->size <= 3)
	{
		sort_stack3(&a);
		exit(EXIT_SUCCESS);
	}
	push_to_b(&a, &b);
	push_to_a(&a, &b);
	bring_smallest(&a);
	(free_nodes(&a), free_nodes(&b), exit(EXIT_SUCCESS));
}
