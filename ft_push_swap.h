/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:34:20 by asuc              #+#    #+#             */
/*   Updated: 2024/01/08 23:35:24 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdio.h>

typedef struct s_node
{
	long long		content;
	int				rank;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;

typedef struct s_stack
{
	int				size_lis;
	int				range;
	int				median;
	t_node			*top;
	t_node			*bottom;
	enum e_instru	*moves;
	int				nb_moves;
}					t_stack;

typedef struct s_lis_data
{
	int				*arr;
	int				*prev;
	int				*result;
	int				pos;
}					t_lis_data;

enum				e_instru
{
	i_nothing,
	i_sa,
	i_sb,
	i_ss,
	i_pa,
	i_pb,
	i_ra,
	i_rb,
	i_rr,
	i_rra,
	i_rrb,
	i_rrr
};

int					check_input(char **argv);
int					putstr_error(char *str);
int					search_in_tab_int(int *tab, int nb);
int					fill_tab_and_check_double(int **tab, char **argv);
int					main_check_input_and_fill_tab(char **argv, int **tab);
void				fill_stack_from_array(t_stack *stack, int *array, int size);
void				clear_stack(t_stack *stack);
void				push_to_stack(t_stack *stack, t_node *new_node);
t_node				*create_new_node(int content);
int					stack_is_sorted(t_stack *stack);
int					sort_stack(t_stack *stack_a, t_stack *stack_b,
						int *tab_lis);
int					rotate(t_stack *stack);
int					push(t_stack *dest, t_stack *src);
void				update_links(t_stack *dest, t_node *tmp);
int					ss(t_stack *stack_a, t_stack *stack_b);
int					swap(t_stack *stack);
int					rr(t_stack *stack_a, t_stack *stack_b);
int					reverse_rotate(t_stack *stack);
int					rrr(t_stack *stack_a, t_stack *stack_b);
t_node				*find_max(t_stack *stack);
t_node				*find_min(t_stack *stack);
int					sort_three(t_stack *stack_a);
int					ra(t_stack *stack_a);
int					rb(t_stack *stack_b, t_stack *stack_a);
int					sa(t_stack *stack_a);
int					sb(t_stack *stack_b, t_stack *stack_a);
int					rra(t_stack *stack_a);
int					rrb(t_stack *stack_b, t_stack *stack_a);
int					pb(t_stack *stack_a, t_stack *stack_b);
int					pa(t_stack *stack_a, t_stack *stack_b);
int					*find_lis(t_stack *t_stack, int *arr, int n);
int					max(int a, int b);
void				free_stack(t_stack *stack);
void				free_tab(int **tab);
void				free_argv(char ***argv);
void				free_stack_final(t_stack *stack_a, t_stack *stack_b);
int					check_input_main(char **argv, int argc, int **tab);
int					main_sort(t_stack *stack_a, t_stack	*stack_b, int range,
						int *lis_array);
int					len_argv(char **argv);
char				**ft_join_argv(char **fake_argv, char **argv, int argc);
int					has_multiple_nb(char *str);

#endif
