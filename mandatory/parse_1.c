/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:02:49 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/30 16:51:27 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_args(int ac, char *av[], t_stack **a)
{
	int		i;
	int		j;
	char	**strs;

	i = 0;
	while (++i < ac)
	{
		strs = ft_split(av[i], ' ');
		if (strs)
		{
			j = -1;
			while (strs[++j])
			{
				if (!strs[j] || !valid_nbr(strs[j]) || not_int(strs[j]))
					return (write(2, "Error\n", 6), free_both(strs, a), 0);
				if (!add_to_stack(a, ft_atoi(strs[j])))
					return (write(2, "Error\n", 6), free_both(strs, a), 0);
			}
			free_strs(strs);
		}
		else
			return (write(2, "Error\n", 6), free_both(strs, a), 0);
	}
	return (1);
}

void	index_stack(t_stack *stack)
{
	t_node	*tmp;
	int		i;

	if (!stack)
		return ;
	tmp = stack->head;
	if (!tmp)
	{
		stack->size = 0;
		return ;
	}
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		stack->size = i + 1;
		i++;
		tmp = tmp->next;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static long	calc_result(long tmp, long result, char c, int sign)
{
	tmp = (result * 10) + (c - 48);
	if (tmp < result && sign == 1)
		return (-1);
	else if (tmp < result && sign == -1)
		return (0);
	return (tmp);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;
	long	tmp;

	i = 0;
	sign = 1;
	result = 0;
	tmp = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = calc_result(tmp, result, str[i], sign);
		i++;
	}
	return (sign * result);
}
