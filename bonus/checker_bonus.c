/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:35:05 by obouchta          #+#    #+#             */
/*   Updated: 2024/02/03 11:06:28 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	read_instructions(char **s)
{
	char	*inp;
	int		i;

	inp = get_next_line(0);
	i = 0;
	while (inp)
	{
		(!ft_strncmp(inp, "sa\n", 4) && (i++, (*s = ft_strjoin(*s, "sa\n"))));
		(!ft_strncmp(inp, "sb\n", 4) && (i++, (*s = ft_strjoin(*s, "sb\n"))));
		(!ft_strncmp(inp, "pa\n", 4) && (i++, (*s = ft_strjoin(*s, "pa\n"))));
		(!ft_strncmp(inp, "pb\n", 4) && (i++, (*s = ft_strjoin(*s, "pb\n"))));
		(!ft_strncmp(inp, "ra\n", 4) && (i++, (*s = ft_strjoin(*s, "ra\n"))));
		(!ft_strncmp(inp, "rb\n", 4) && (i++, (*s = ft_strjoin(*s, "rb\n"))));
		(!ft_strncmp(inp, "rr\n", 4) && (i++, (*s = ft_strjoin(*s, "rr\n"))));
		(!ft_strncmp(inp, "ss\n", 4) && (i++, (*s = ft_strjoin(*s, "ss\n"))));
		(!ft_strncmp(inp, "rra\n", 5) && (i++, (*s = ft_strjoin(*s, "rra\n"))));
		(!ft_strncmp(inp, "rrb\n", 5) && (i++, (*s = ft_strjoin(*s, "rrb\n"))));
		(!ft_strncmp(inp, "rrr\n", 5) && (i++, (*s = ft_strjoin(*s, "rrr\n"))));
		free(inp);
		if (!i)
			(write(2, "Error\n", 6), exit(EXIT_FAILURE));
		inp = get_next_line(0);
		i = 0;
	}
}

void	ft_apply(char *s, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(s, "sa", 3))
		sa(&(*a)->head, 'n');
	else if (!ft_strncmp(s, "sb", 3))
		sb(&(*b)->head, 'n');
	else if (!ft_strncmp(s, "pa", 3))
		pa(&(*a)->head, &(*b)->head);
	else if (!ft_strncmp(s, "pb", 3))
		pb(&(*a)->head, &(*b)->head);
	else if (!ft_strncmp(s, "ra", 3))
		ra(&(*a)->head, 'n');
	else if (!ft_strncmp(s, "rb", 3))
		rb(&(*b)->head, 'n');
	else if (!ft_strncmp(s, "rr", 3))
		rr(&(*a)->head, &(*b)->head);
	else if (!ft_strncmp(s, "ss", 3))
		ss(&(*a)->head, &(*b)->head);
	else if (!ft_strncmp(s, "rra", 4))
		rra(&(*a)->head, 'n');
	else if (!ft_strncmp(s, "rrb", 4))
		rrb(&(*b)->head, 'n');
	else if (!ft_strncmp(s, "rrr", 4))
		rrr(&(*a)->head, &(*b)->head);
}

void	check_sorted(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	int		min;

	if (b->head)
		(write(1, "KO\n", 3), exit(EXIT_FAILURE));
	min = a->head->value;
	tmp = a->head->next;
	while (tmp)
	{
		if (tmp->value < min)
			(write(1, "KO\n", 3), exit(EXIT_FAILURE));
		min = tmp->value;
		tmp = tmp->next;
	}
	(write(1, "OK\n", 3), exit(EXIT_SUCCESS));
}

void	apply_instructions(char *s, t_stack **a, t_stack **b)
{
	char	**instrs;
	int		i;

	instrs = ft_split(s, '\n');
	if (!instrs)
	{
		if (!stack_sorted((*a)->head))
			(write(1, "KO\n", 3), exit(EXIT_FAILURE));
		else
			(write(1, "OK\n", 3), exit(EXIT_SUCCESS));
	}
	i = 0;
	while (instrs[i])
	{
		ft_apply(instrs[i], a, b);
		i++;
	}
	free_strs(instrs);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	char	*instrs;

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
	read_instructions(&instrs);
	apply_instructions(instrs, &a, &b);
	check_sorted(a, b);
	exit(EXIT_SUCCESS);
}
