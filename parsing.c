/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:55:25 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/14 21:57:26 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_nbr(char *nbr)
{
	int	i;

	i = 0;
	if (ft_strlen(nbr) == 1 && (nbr[0] == '-' || nbr[0] == '+'))
		return (0);
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	if (!nbr[i])
		return (0);
	while(nbr[i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	not_int(char *nbr)
{
	if (ft_strlen(nbr) >= 19)
		return (0);
	if (ft_atoi(nbr) < -2147483648 || ft_atoi(nbr) > 2147483647)
		return (1);
	return (0);
}

int	check_duplicated(t_stack *stack, int data)
{
	t_node	*tmp;

	if (!stack || !stack->head)
		return (0);
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->data == data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int add_to_stack(t_stack **stack, int data, int index)
{
	t_node	*node;
	t_node	*tmp;
	
	if (check_duplicated(*stack, data))
		return (0);
	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->data = data;
	node->index = index;
	node->next = NULL;
	if (!(*stack))
	{
		*stack = malloc(sizeof(t_stack));
		if (!*stack)
			return (0);
		(*stack)->head = node;
		(*stack)->size = 1;
		return (1);
	}
	// add back
	tmp = (*stack)->head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	(*stack)->size++;
	return (1);
}

void	free_lomor(char **strings)
{
	int		i;

	if (!strings)
		return ;
	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	// if (!(*a) || !(*a)->head)
	// 	return ;
	// tmp = (*a)->head;
	// while (tmp)
	// {
	// 	tmp = tmp->next;
	// 	free((*a)->head);
	// 	(*a)->head = tmp;
	// }
}
void	v()
{
	system("leaks a.out");
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
int	valid_args(int ac, char *av[], t_stack **a)
{
	int		i;
	int		j;
	int		k;
	char	**strings;
	
	i = 0;
	k = 0;
	while (++i < ac)
	{
		strings = ft_split(av[i], ' ');
		if (strings)
		{
			j = 0;
			while (strings[j])
			{
				if (!strings[j] || !valid_nbr(strings[j]) || not_int(strings[j]))
					(ft_printf("Error\n"), free_lomor(strings), exit(EXIT_FAILURE));
				if (!add_to_stack(a, ft_atoi(strings[j]), k))
					(ft_printf("Error\n"), free_lomor(strings), exit(EXIT_FAILURE));
				k++;
				j++;
			}
		}
		else
			(ft_printf("Error\n"), free_lomor(strings), exit(EXIT_FAILURE));
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	(void)b;
	
	//atexit(v);
	a = NULL;
	if (ac == 1 || (ac == 2 && !ft_strncmp(av[1], "", 1)))
		(ft_printf("Error\n"), exit(EXIT_FAILURE));
	if (!valid_args(ac, av, &a))
        exit(EXIT_FAILURE);
		
    ft_printf("All Valid\n");
    t_node *tmp = a->head;
	ft_printf("(%d)\n", a == NULL ? 0 : a->size);
    while (tmp)
    {
        ft_printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
	ft_free_nodes(&a);
	exit(EXIT_SUCCESS);
	return (0);
}