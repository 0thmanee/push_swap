/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:55:25 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/10 06:30:05 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_nbr(char *nbr)
{
	int	i;

	i = 0;
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
	ft_printf("%d ", ft_atoi(nbr));
	if (ft_atoi(nbr) < INT_MIN || ft_atoi(nbr) > INT_MAX)
		return (1);
	return (0);
}

int	valid_args(int ac, char *av[])
{
	int		i;
	int		j;
	char	**strings;
	t_list	*node;
	int		nbr;
	
	if (ac == 1)
		return (ft_printf("Error\n"), 0);
	i = 1;
	while (i < ac)
	{
		strings = ft_split(av[i], ' ');
		j = 0;
		while (strings[j])
		{
			if (!valid_nbr(strings[j]) || not_int(strings[j]))
				return (ft_printf("Error\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}
int	main(int ac, char *av[])
{
	int	i;
	t_list	*a;

	if (!valid_args(ac, av))
		exit(1);
	else ft_printf("All Valid");
	
	// nbr = ft_atoi(strings[j]);
	// node = ft_lstnew(&nbr);
	// ft_lstadd_back(a, node);
}