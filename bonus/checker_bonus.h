/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:37:26 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/28 18:44:13 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	struct s_node	*next;
	struct s_node	*target;
}					t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

int		valid_nbr(char *nbr);
int		not_int(char *nbr);
int		check_duplicated(t_stack *stack, int data);
int		add_to_stack(t_stack **stack, int data);
void	free_strs(char **strings);

#endif