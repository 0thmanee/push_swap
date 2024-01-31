/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:40:34 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/31 20:40:15 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	while (nbr[i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	not_int(char *nbr)
{
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
		if (tmp->value == data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	add_to_stack(t_stack **stack, int data)
{
	t_node	*node;
	t_node	*tmp;

	if (check_duplicated(*stack, data))
		return (0);
	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->value = data;
	node->next = NULL;
	if (!(*stack)->head)
	{
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

void	free_strs(char **strings)
{
	int		i;

	if (!strings)
		return ;
	i = 0;
	while (strings[i])
	{
		if (strings[i])
			free(strings[i]);
		i++;
	}
	free(strings);
}
