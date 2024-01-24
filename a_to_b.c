/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:23:03 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/24 16:25:41 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_cheapest_in_b(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	t_node	*tmp2;
	t_node	*cheap;

	tmp = a->head;
	cheap = tmp;
	while (tmp)
	{
		if (tmp->index <= a->size / 2)
			tmp->cost = tmp->index;
		else
			tmp->cost = a->size - tmp->index + 1;
		tmp2 = b->head;
		tmp->target = tmp;
		while (tmp2)
		{
			if (tmp2->value < tmp->value && tmp->value == tmp->target->value)
				tmp->target = tmp2;
			if (tmp2->value < tmp->value && tmp2->value > tmp->target->value)
				tmp->target = tmp2;
			tmp2 = tmp2->next;
		}
		if (tmp->value != tmp->target->value && tmp->target->index != 1)
		{
			if (tmp->target->index <= b->size / 2)
				tmp->cost += tmp->target->index;
			else
				tmp->cost += (b->size - tmp->target->index + 1);
		}
		else if (tmp->value == tmp->target->value && tmp->index > a->size / 2)
			tmp->cost++;
		if (tmp->cost < cheap->cost)
			cheap = tmp;
		tmp = tmp->next;
	}
	return (cheap);
}

void	rotate_no_target(t_stack **a, t_node *cheap)
{
	int		i;
	int		j;
	
	i = cheap->index;
	j = cheap->target->index;
	if (cheap->index <= (*a)->size / 2)
	{
		while (i > 1)
		{
			ra(&(*a)->head, 'n');
			i--;
		}
	}
	else
	{
		while (((*a)->size - i) > 0)
		{
			rra(&(*a)->head, 'n');
			i--;
		}
	}
}

void	rotate_both(t_stack **a, t_stack **b, t_node *cheap)
{
	int		i;
	int		j;
	
	i = cheap->index;
	j = cheap->target->index;
	while (i > 1 && j > 1)
	{
		rr(&(*a)->head, &(*b)->head);
		i--;
		j--;
	}
	while (i > 1)
	{
		ra(&(*a)->head, 'n');
		i--;
	}
	while (j > 1)
	{
		rb(&(*a)->head, 'n');
		j--;
	}
}

void	rrotate_both(t_stack **a, t_stack **b, t_node *cheap)
{
	int		i;
	int		j;
	
	i = (*a)->size - cheap->index + 1;
	j = (*b)->size - cheap->target->index + 1;
	while (i > 0 && j > 0)
	{
		rrr(&(*a)->head, &(*b)->head);
		i--;
		j--;
	}
	while (i > 0)
	{
		rra(&(*a)->head, 'n');
		i--;
	}
	while (j > 0)
	{
		rrb(&(*a)->head, 'n');
		j--;
	}
}

void	ra_rrb(t_stack **a, t_stack **b, t_node *cheap)
{
	int		i;
	
	i = cheap->index;
	while (i > 1)
	{
		ra(&(*a)->head, 'n');
		i--;
	}
	i = (*b)->size - cheap->target->index + 1;
	while (i > 0)
	{
		rrb(&(*b)->head, 'n');
		i--;
	}
}

void	rra_rb(t_stack **a, t_stack **b, t_node *cheap)
{
	int		i;
	i = (*a)->size - cheap->index + 1;
	while (i >  0)
	{
		rra(&(*a)->head, 'a');
		i--;
	}
	i = cheap->target->index;
	while (i > 1)
	{
		rb(&(*b)->head, 'n');
		i--;
	}
}

void	find_place_in_b(t_stack **a, t_stack **b)
{
	t_node	*tmp;

	tmp = find_cheapest_in_b(*a, *b);
	if (tmp->value == tmp->target->value)
		rotate_no_target(a, tmp);
	else if (tmp->index <= (*a)->size / 2 && tmp->target->index <= (*b)->size / 2)
		rotate_both(a, b, tmp);
	else if (tmp->index > (*a)->size / 2 && tmp->target->index > (*b)->size / 2)
		rrotate_both(a, b, tmp);
	else if (tmp->index <= (*a)->size / 2 && tmp->target->index > (*b)->size / 2)
		ra_rrb(a, b, tmp);
	else if (tmp->index > (*a)->size / 2 && tmp->target->index <= (*b)->size / 2)
		rra_rb(a, b, tmp);
	index_stack(*a);
	index_stack(*b);
	pb(&(*a)->head, &(*b)->head);
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
	pb(&(*a)->head, &(*b)->head);
	pb(&(*a)->head, &(*b)->head);
	index_stack(*a);
	index_stack(*b);
	while ((*a)->size > 3)
	{
		find_place_in_b(a, b);
		index_stack(*a);
		index_stack(*b);
	}
	sort_stack3(a);
	index_stack(*a);
}

void	find_cheapest_in_a(t_stack *a, t_node *node)
{
	t_node	*tmp;

	tmp = a->head;
	node->target = node;
	while (tmp)
	{
		if (tmp->value > node->value && node->value == node->target->value)
			node->target = tmp;
		if (tmp->value > node->value && tmp->value < node->target->value)
			node->target = tmp;
		tmp = tmp->next;
	}	
}

void	rotate_a(t_stack **a, t_node *node)
{
	int	i;

	i = node->index;
	if (i <= (*a)->size / 2)
	{
		while (i > 1)
		{
			ra(&(*a)->head, 'n');
			i--;
		}
	}
	else
	{
		i = (*a)->size - i + 1;
		while (i > 0)
		{
			rra(&(*a)->head, 'n');
			i--;
		}
	}
}

void	push_to_a(t_stack **a, t_stack **b)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		should_ra;

	should_ra = 0;
	while ((*b)->head && (*b)->size > 0)
	{
		tmp = (*b)->head;
		find_cheapest_in_a(*a, tmp);
		if (tmp->value == tmp->target->value)
		printf("%d, %d\n", tmp->value, tmp->target->value);
		tmp2 = tmp->target;
		rotate_a(a, tmp2);
		pa(&(*a)->head, &(*b)->head);
		index_stack(*a);
		index_stack(*b);
	}
}
