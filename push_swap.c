/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:03:01 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/24 16:30:18 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_smallest(t_stack **a)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		i;

	tmp = (*a)->head;
	tmp2 = stack_s_min((*a)->head);
	if (tmp2->index <= (*a)->size / 2)
	{
		i = tmp2->index;
		while (i > 1)
		{
			ra(&(*a)->head, 'n');
			i--;
		}
	}
	else
	{
		i = (*a)->size - tmp2->index + 1;
		while (i > 0)
		{
			rra(&(*a)->head, 'n');
			i--;
		}
	}
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	// (void)b;
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
		printf("^^");
		sort_stack3(&a);
		exit(EXIT_SUCCESS);
	}
	push_to_b(&a, &b);
	// print_stack2(a, "a");
	// print_stack1(b, "b");
	// push_to_a(&a, &b);
	// bring_smallest(&a);
	index_stack(a);
	index_stack(b);
	exit(EXIT_SUCCESS);
	return (0);
}