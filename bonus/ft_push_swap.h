/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:27:56 by asuc              #+#    #+#             */
/*   Updated: 2024/01/11 18:20:52 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../Libft/libft.h"
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

int					ss(t_stack *stack_a, t_stack *stack_b);
int					rr(t_stack *stack_a, t_stack *stack_b);
int					rrr(t_stack *stack_a, t_stack *stack_b);
int					ra(t_stack *stack_a);
int					rb(t_stack *stack_b);
int					sa(t_stack *stack_a);
int					sb(t_stack *stack_b);
int					rra(t_stack *stack_a);
int					rrb(t_stack *stack_b);
int					pb(t_stack *stack_a, t_stack *stack_b);
int					pa(t_stack *stack_a, t_stack *stack_b);
int					stack_is_sorted(t_stack *stack);
int					main_check_input_and_fill_tab(char **argv, int **tab);
int					fill_stack_from_array(t_stack *stack, int *array, int size);
int					putstr_error(char *str);
void				free_argv(char ***argv);
void				free_tab(int **tab);
void				free_stack(t_stack *stack);
void				free_stack_final(t_stack *stack_a, t_stack *stack_b);
int					check_input_main(char **argv, int argc, int **tab);
int					parse_instru(char *line, t_stack *stack_a);
int					has_multiple_nb(char *str);
int					len_argv(char **argv);
char				**ft_join_argv(char **fake_argv, char **argv, int argc);
void				make_moves_loop(t_stack *stack_a, t_stack *stack_b);
int					final_print(enum e_instru instru);
int					init_stack(t_stack *stack_a, t_stack *stack_b, int range);
int					search_in_tab_int(int *tab, int nb);
int					check_max_length(char **argv);
void				clear_stack(t_stack *stack);
int					check_input_nothing(char **argv);
enum e_instru		*ft_realloc_enum(enum e_instru *str, int size);
int					free_stack_and_moves(t_stack *stack_a, t_stack *stack_b);

#endif
