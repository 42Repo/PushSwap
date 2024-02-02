/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part1_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:32:07 by asuc              #+#    #+#             */
/*   Updated: 2024/02/02 20:16:55 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	is_in_tab(int *tab, int nb, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

void	fill_tab_instruction_tmp(t_node *tmp, t_stack *stack_a,
			t_stack *stack_b, enum e_instru ***tab_instruction_tmp)
{
	int	i;
	int	rank_tmp;

	i = 0;
	set_tab_instruction(&((*tab_instruction_tmp)[0]), stack_a->max);
	set_tab_instruction(&((*tab_instruction_tmp)[1]), stack_a->max);
	rank_tmp = tmp->rank;
	if (rank_tmp <= stack_a->median)
		while (i < tmp->rank)
			(*tab_instruction_tmp)[0][i++] = i_ra;
	else
		while (i <= (stack_a->range - tmp->rank) - 1)
			(*tab_instruction_tmp)[0][i++] = i_rra;
	rank_tmp = tmp->target->rank;
	i = 0;
	if (rank_tmp <= stack_b->median)
		while (i < tmp->target->rank)
			(*tab_instruction_tmp)[1][i++] = i_rb;
	else
		while (i <= (stack_b->range - tmp->target->rank) - 1)
			(*tab_instruction_tmp)[1][i++] = i_rrb;
}

t_node	*fill_tab_instruction(t_stack *stack_a,
		enum e_instru ***tab_instruction_tmp, int *tab, t_node	**tmp)
{
	int		i;
	int		moves;
	t_node	*target;

	i = 0;
	target = NULL;
	moves = optimize_moves(tab_instruction_tmp);
	if (moves < stack_a->max_moves && is_in_tab(tab, (*tmp)->content,
			stack_a->size_lis) == 0)
	{
		stack_a->max_moves = moves;
		set_tab_instruction(&(stack_a->tab_instru[0]), stack_a->max);
		set_tab_instruction(&(stack_a->tab_instru[1]), stack_a->max);
		while (i < stack_a->max)
		{
			(stack_a->tab_instru)[0][i] = (*tab_instruction_tmp)[0][i];
			(stack_a->tab_instru)[1][i] = (*tab_instruction_tmp)[1][i];
			i++;
		}
		target = (*tmp);
		return (target);
	}
	return (NULL);
}

t_node	*min_lenght(t_stack *stack_a, t_stack *stack_b, int *tab)
{
	t_node			*tmp;
	t_node			*target;
	enum e_instru	**tab_instruction_tmp;
	t_node			*target_tmp;

	stack_a->max = find_max_range(stack_a, stack_b);
	init_tab_instruction(&tab_instruction_tmp, stack_a->max);
	if (tab_instruction_tmp == NULL)
		return (NULL);
	tmp = stack_a->top;
	target = NULL;
	stack_a->max_moves = stack_a->max * 4;
	while (tmp != NULL)
	{
		fill_tab_instruction_tmp(tmp, stack_a, stack_b, &tab_instruction_tmp);
		target_tmp = fill_tab_instruction(stack_a, &tab_instruction_tmp,
				tab, &tmp);
		if (target_tmp != NULL)
			target = target_tmp;
		tmp = tmp->next;
	}
	free_tab_instruction(&tab_instruction_tmp);
	return (target);
}
