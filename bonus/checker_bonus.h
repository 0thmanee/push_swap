/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:37:26 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/30 23:16:55 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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

typedef struct s_data
{
	char	*total_str;
	int		end_file;
}	t_data;

int		valid_nbr(char *nbr);
int		not_int(char *nbr);
int		check_duplicated(t_stack *stack, int data);
int		add_to_stack(t_stack **stack, int data);
int		valid_args(int ac, char *av[], t_stack **a);
void	index_stack(t_stack *stack);
size_t	ft_strlen(const char *s);
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_strs(char **strings);
void	free_nodes(t_stack **stack);
void	free_both(char **strs, t_stack **a);
int		ft_strchr(char *buffer, int c);
size_t	ft_strlen(const char *s);
void	ft_strcpy(char *dest, char *src);
char	*ft_strjoin(char *total_str, char *buffer);
char	*read_file(char *total_str, int fd);
char	*extract_line(char *total_str);
char	*new_total(t_data *total_data);
void	free_total(char **total_str);
char	*get_next_line(int fd);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack, char c);
void	rb(t_node **stack, char c);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack, char c);
void	rrb(t_node **stack, char c);
void	rrr(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack, char c);
void	sb(t_node **stack, char c);
void	ss(t_node **stack_a, t_node **stack_b);

#endif