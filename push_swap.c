/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:03:01 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/23 23:02:15 by obouchta         ###   ########.fr       */
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
	printf("(%d, %d)\n", tmp->value, tmp->target->value);
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

void check()
{
	system("leaks push_swap");
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
	print_stack2(a, "a");
	print_stack1(b, "b");
	// push_to_a(&a, &b);
	// bring_smallest(&a);
	index_stack(a);
	index_stack(b);
	exit(EXIT_SUCCESS);
	return (0);
}