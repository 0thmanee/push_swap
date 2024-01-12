/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:55:25 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/12 06:32:44 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_nbr(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
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
	t_node	*tmp;

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

int	valid_args(int ac, char *av[], t_stack **a)
{
	int		i;
	int		j;
	int		k;
	char	**strings;
	t_list	*node;
	int		nbr;
	
	if (ac == 1)
		return (ft_printf("Error\n"), 0);
	i = 0;
	k = 0;
	while (++i < ac)
	{
		strings = ft_split(av[i], ' ');
		if (!strings || !strings[0])
		{
			j = 0;
			while (strings[j])
			{
				if (!valid_nbr(strings[j]) || not_int(strings[j]))
					return (ft_printf("Error\n"), 0);
				if (!add_to_stack(a, ft_atoi(strings[j]), k))
					return (ft_printf("Error\n"), free_lomor(strings), 0);
				k++;
				j++;
			}
		}
		free_lomor(strings);
	}
	return (1);
}
int	main(int ac, char *av[])
{
	int	i;
	t_stack	*a;
	
	a = NULL;
	if (!valid_args(ac, av, &a))
        return (1);
    else
        ft_printf("All Valid\n");

    t_node *tmp = a ? a->head : NULL;
	ft_printf("%d\n", a == NULL ? 0 : a->size);
    while (tmp)
    {
        ft_printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
	return (0);
}