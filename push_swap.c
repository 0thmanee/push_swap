/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:03:01 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/24 23:10:56 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **b)
{
	int	avg;
	
	if (!(*a)->head || !(*a)->head->next)
		return ;
	if (!(*b))
	{
		*b = malloc(sizeof(t_stack));
		if (!*b)
			return ;
	}
	avg = stack_s_max((*a)->head) + stack_s_min((*a)->head) / 2;
	while ((*a)->size > 3 && !stack_sorted((*a)->head))
	{
		pb(&(*a)->head, &(*b)->head);
		index_stack(*a);
		index_stack(*b);
		if ((*b)->head->value < avg)
		{
			rrb(&(*b)->head, 'n');
			index_stack(*b);
		}
	}
	if ((*a)->size <= 3)
		sort_stack3(a);
}

// void a_2_b(t_stack **a, t_stack **b, int p)
// {
// 	t_node *na = (*a)->head;
// 	t_node *nb = (*b)->head;
//     int    part;
//     int count;
//     count = 0;
//     int len;

//     len = 0;
//     len = (*a)->size;
//     if ((*a)->size > 3)
//     {
//         part = ((*a)->size / 3);
//         count = part;
//         while (count > 0)
//         {
//             if ((*a)->size == 3)
//                 return ;
//             if (na->index <= (part / 2) + p )
//             {
//                 pb(&na, &na);
//                 count--;
//             }
//             else if (na->index <= part + p)
//             {
//                 pb(&na, &na);
//                 rb(&nb, 'n');
//                 count--;
//             }
//             else if (na->index > part + p)
//                 ra(&na, 'n');
//         }
//     }
//     if ((*a)->size > 3)
//         a_2_b(a, b, (*b)->size);
// }

t_node	*find_cheapest_in_a(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	t_node	*tmp2;
	t_node	*cheap;

	tmp = b->head;
	cheap = tmp;
	while (tmp)
	{
		if (tmp->index <= b->size / 2)
			tmp->cost = tmp->index;
		else
			tmp->cost = b->size - tmp->index;
		tmp2 = a->head;
		tmp->target = tmp;
		while (tmp2)
		{
			if (tmp2->value > tmp->value && tmp->value == tmp->target->value)
				tmp->target = tmp2;
			if (tmp2->value > tmp->value && tmp2->value < tmp->target->value)
				tmp->target = tmp2;
			tmp2 = tmp2->next;
		}
		if (tmp->value != tmp->target->value && tmp->target->index != 1)
		{
			if (tmp->target->index <= a->size / 2)
				tmp->cost += tmp->target->index;
			else
				tmp->cost += (a->size - tmp->target->index);
		}
		else if (tmp->value == tmp->target->value && tmp->index > b->size / 2)
			tmp->cost++;
		if (tmp->cost < cheap->cost)
			cheap = tmp;
		tmp = tmp->next;
	}
	return (cheap);
}

void	find_cheapest_for_no_targ(t_stack *a, t_stack *b, t_node *tmp)
{
	t_node	*tmp2;

	tmp2 = a->head;
	tmp->target = tmp2;
	while (tmp2)
	{
		if (tmp2->value < tmp->target->value)
			tmp->target = tmp2;
		tmp2 = tmp2->next;
	}
	if (tmp->value != tmp->target->value && tmp->target->index != 1)
	{
		if (tmp->target->index <= a->size / 2)
			tmp->cost += tmp->target->index;
		else
			tmp->cost += (a->size - tmp->target->index);
	}
	else if (tmp->value == tmp->target->value && tmp->index > b->size / 2)
		tmp->cost++;
}

void	rotate_both_2(t_stack **a, t_stack **b, t_node *cheap)
{
	int		i;
	int		j;
	
	i = cheap->index;
	j = cheap->target->index;
	while (i > 0 && j > 0)
	{
		rr(&(*a)->head, &(*b)->head);
		i--;
		j--;
	}
	while (i > 0)
	{
		rb(&(*b)->head, 'n');
		i--;
	}
	while (j > 0)
	{
		ra(&(*a)->head, 'n');
		j--;
	}
}

void	rrotate_both_2(t_stack **a, t_stack **b, t_node *cheap)
{
	int		i;
	int		j;
	
	i = (*b)->size - cheap->index;
	j = (*a)->size - cheap->target->index;
	while (i > 0 && j > 0)
	{
		rrr(&(*a)->head, &(*b)->head);
		i--;
		j--;
	}
	while (i > 0)
	{
		rrb(&(*b)->head, 'n');
		i--;
	}
	while (j > 0)
	{
		rra(&(*a)->head, 'n');
		j--;
	}
}

void	rb_rra(t_stack **a, t_stack **b, t_node *cheap)
{
	int		i;
	
	i = cheap->index;
	while (i > 0)
	{
		rb(&(*b)->head, 'n');
		i--;
	}
	i = (*a)->size - cheap->target->index;
	while (i > 0)
	{
		rra(&(*a)->head, 'n');
		i--;
	}
}

void	rrb_ra(t_stack **a, t_stack **b, t_node *cheap)
{
	int		i;
	i = (*b)->size - cheap->index;
	while (i > 0)
	{
		rrb(&(*b)->head, 'a');
		i--;
	}
	i = cheap->target->index;
	while (i > 0)
	{
		ra(&(*a)->head, 'n');
		i--;
	}
}

void	find_place_in_a(t_stack **a, t_stack **b)
{
	t_node	*tmp;

	tmp = find_cheapest_in_a(*a, *b);
	if (tmp->value == tmp->target->value)
		find_cheapest_for_no_targ(*a, *b, tmp);
	if (tmp->index <= (*b)->size / 2 && tmp->target->index <= (*a)->size / 2)
		rotate_both_2(a, b, tmp);
	else if (tmp->index > (*b)->size / 2 && tmp->target->index > (*a)->size / 2)
		rrotate_both_2(a, b, tmp);
	else if (tmp->index <= (*b)->size / 2 && tmp->target->index > (*a)->size / 2)
		rb_rra(a, b, tmp);
	else if (tmp->index > (*b)->size / 2 && tmp->target->index <= (*a)->size / 2)
		rrb_ra(a, b, tmp);
	index_stack(*a);
	index_stack(*b);
	pa(&(*a)->head, &(*b)->head);
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

t_node	*get_min_node(t_node *stack)
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

void	bring_smallest(t_stack **a)
{
	t_node	*tmp;
	int		i;
	
	tmp = get_min_node((*a)->head);
	if (tmp->index <= (*a)->size / 2)
	{
		i = tmp->index;
		while (i > 0)
		{
			ra(&(*a)->head, 'n');
			i--;
		}
	}
	else
	{
		i = (*a)->size - tmp->index;
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
	// print_stack1(a, "a");
	index_stack(a);
	index_stack(b);
	exit(EXIT_SUCCESS);
	return (0);
}