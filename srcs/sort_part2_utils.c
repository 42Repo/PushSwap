/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part2_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:34:24 by asuc              #+#    #+#             */
/*   Updated: 2024/02/02 20:16:55 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	fill_tab_rb(t_node *tmp,
			t_stack *stack_b, enum e_instru ***tab_instruction_tmp)
{
	int	i;
	int	rank_tmp;

	i = 0;
	rank_tmp = tmp->rank;
	while (rank_tmp != 0)
	{
		if (rank_tmp <= stack_b->median)
		{
			rank_tmp--;
			(*tab_instruction_tmp)[0][i] = i_rb;
		}
		else
		{
			rank_tmp++;
			(*tab_instruction_tmp)[0][i] = i_rrb;
		}
		if (rank_tmp == stack_b->range)
			rank_tmp = 0;
		i++;
	}
}

void	fill_tab_ra(t_node *tmp,
			t_stack *stack_a, enum e_instru ***tab_instruction_tmp)
{
	int	i;
	int	rank_tmp;

	rank_tmp = tmp->target->rank;
	i = 0;
	while (rank_tmp != 0)
	{
		if (rank_tmp <= stack_a->median)
		{
			rank_tmp--;
			(*tab_instruction_tmp)[1][i] = i_ra;
		}
		else
		{
			rank_tmp++;
			(*tab_instruction_tmp)[1][i] = i_rra;
		}
		if (rank_tmp == stack_a->range)
			rank_tmp = 0;
		i++;
	}
}

void	fill_tab_instruction_tmp_a(t_node *tmp, t_stack *stack_a,
			t_stack *stack_b, enum e_instru ***tab_instruction_tmp)
{
	set_tab_instruction(&((*tab_instruction_tmp)[0]), stack_a->max);
	set_tab_instruction(&((*tab_instruction_tmp)[1]), stack_a->max);
	fill_tab_rb(tmp, stack_b, tab_instruction_tmp);
	fill_tab_ra(tmp, stack_a, tab_instruction_tmp);
}

t_node	*fill_tab_instruction_a(t_stack *stack_a,
		enum e_instru ***tab_instruction_tmp, t_node	**tmp)
{
	int		i;
	int		moves;
	t_node	*target;

	i = 0;
	target = NULL;
	moves = optimize_moves(tab_instruction_tmp);
	if (moves < stack_a->max_moves)
	{
		stack_a->max_moves = moves;
		set_tab_instruction(&((stack_a->tab_instru)[0]), stack_a->max);
		set_tab_instruction(&((stack_a->tab_instru)[1]), stack_a->max);
		while (i < stack_a->max)
		{
			((stack_a->tab_instru))[0][i] = (*tab_instruction_tmp)[0][i];
			((stack_a->tab_instru))[1][i] = (*tab_instruction_tmp)[1][i];
			i++;
		}
		target = (*tmp);
		return (target);
	}
	return (NULL);
}

t_node	*min_lenght_a(t_stack *stack_b, t_stack *stack_a)
{
	t_node			*tmp;
	t_node			*target;
	t_node			*target_tmp;
	enum e_instru	**tab_instruction_tmp;

	stack_a->max = find_max_range(stack_a, stack_b);
	init_tab_instruction(&tab_instruction_tmp, stack_a->max);
	if (tab_instruction_tmp == NULL)
		return (NULL);
	tmp = stack_b->top;
	target = NULL;
	stack_a->max_moves = stack_a->max * 4;
	while (tmp != NULL)
	{
		fill_tab_instruction_tmp_a(tmp, stack_a, stack_b, &tab_instruction_tmp);
		target_tmp = fill_tab_instruction_a(stack_a, &tab_instruction_tmp,
				&tmp);
		if (target_tmp != NULL)
			target = target_tmp;
		tmp = tmp->next;
	}
	free_tab_instruction(&(tab_instruction_tmp));
	return (target);
}
