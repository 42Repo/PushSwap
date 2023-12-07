/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:34:20 by asuc              #+#    #+#             */
/*   Updated: 2023/12/04 15:02:58 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_list_node
{
	long long			content;
	int					index;
	struct s_list_node	*next;
	struct s_list_node	*previous;
}	t_list_node;

typedef struct s_stack
{
	t_list_node	*top;
	t_list_node	*bottom;
}	t_stack;

int				check_input(char **argv);
int				putstr_error(char *str);
int				range_tab(char **argv);
int				search_in_tab_int(int *tab, int nb);
int				fill_tab_and_check_double(int **tab, char **argv);
int				main_check_input_and_fill_tab(char **argv, int **tab);
void			fill_stack_from_array(t_stack *stack, int *array, int size);
void			clear_stack(t_stack *stack);
void			push_to_stack(t_stack *stack, t_list_node *new_node);
t_list_node		*create_new_node(int content);
int				stack_is_sorted(t_stack *stack);
int				sort_stack(t_stack *stack_a, t_stack *stack_b, int range);
int				rotate(t_stack *stack);
int				push(t_stack *dest, t_stack *src);
void			update_links(t_stack *dest, t_list_node *tmp);
int				ss(t_stack *stack_a, t_stack *stack_b);
int				swap(t_stack *stack);
int				rr(t_stack *stack_a, t_stack *stack_b);
int				reverse_rotate(t_stack *stack);
int				rrr(t_stack *stack_a, t_stack *stack_b);
t_list_node		*find_max(t_stack *stack);
t_list_node		*find_min(t_stack *stack);
int				sort_three(t_stack *stack_a);
int				ra(t_stack *stack_a);
int				rb(t_stack *stack_b);
int				sa(t_stack *stack_a);
int				sb(t_stack *stack_b);
int				rra(t_stack *stack_a);
int				rrb(t_stack *stack_b);

#endif
