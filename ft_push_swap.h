/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:34:20 by asuc              #+#    #+#             */
/*   Updated: 2023/11/17 03:48:01 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_list_stack
{
	long long			content;
	struct s_list_stack	*next;
	struct s_list_stack	*previous;
}	t_list_stack;

typedef struct s_stack
{
	t_list_stack	*top;
	t_list_stack	*bottom;
}	t_stack;

int				check_input(char **argv);
int				putstr_error(char *str);
int				range_tab(char **argv);
int				search_in_tab_int(int *tab, int nb);
int				fill_tab_and_check_double(int **tab, char **argv);
int				main_check_input_and_fill_tab(char **argv, int **tab);
void			fill_stack_from_array(t_stack *stack, int *array, int size);
void			clear_stack(t_stack *stack);
void			push_to_stack(t_stack *stack, t_list_stack *new_node);
t_list_stack	*create_new_node(int content);


#endif
