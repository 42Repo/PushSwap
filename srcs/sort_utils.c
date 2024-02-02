/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:18:40 by asuc              #+#    #+#             */
/*   Updated: 2024/02/02 20:16:55 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	init_tab_instruction(enum e_instru ***tab, int range)
{
	(*tab) = malloc(3 * sizeof(enum e_instru *));
	if (!(*tab))
		return (-1);
	(*tab)[0] = ft_calloc((range * 10), sizeof(enum e_instru));
	if (!(*tab)[0])
	{
		free(*tab);
		return (-1);
	}
	(*tab)[1] = ft_calloc((range * 10), sizeof(enum e_instru));
	if (!(*tab)[1])
	{
		free(*tab);
		free((*tab)[0]);
		return (-1);
	}
	(*tab)[2] = NULL;
	return (0);
}

void	set_tab_instruction(enum e_instru **tab, int range)
{
	int	i;

	i = 0;
	while (i < range)
	{
		(*tab)[i] = 0;
		i++;
	}
}

int	optimize_moves_loop(enum e_instru ***tab_instruction_tmp, int i, int *moves)
{
	if ((*tab_instruction_tmp)[0][i] == i_ra
		&& (*tab_instruction_tmp)[1][i] == i_rb)
	{
		((*tab_instruction_tmp)[0][i] = i_rr);
		((*tab_instruction_tmp)[1][i] = i_nothing);
		(*moves)++;
	}
	else if ((*tab_instruction_tmp)[0][i] == i_rra
		&& (*tab_instruction_tmp)[1][i] == i_rrb)
	{
		((*tab_instruction_tmp)[0][i] = i_rrr);
		((*tab_instruction_tmp)[1][i] = i_nothing);
		(*moves)++;
	}
	else
	{
		if ((*tab_instruction_tmp)[0][i] != i_nothing)
			(*moves)++;
		if ((*tab_instruction_tmp)[1][i] != i_nothing)
			(*moves)++;
	}
	return (0);
}

int	optimize_moves(enum e_instru ***tab_instruction_tmp)
{
	int	i;
	int	moves;

	i = 0;
	moves = 0;
	while ((*tab_instruction_tmp)[0][i] != i_nothing
		|| (*tab_instruction_tmp)[1][i] != i_nothing)
	{
		optimize_moves_loop(tab_instruction_tmp, i, &moves);
		i++;
	}
	return (moves);
}

int	find_max_range(t_stack *stack_a, t_stack *stack_b)
{
	int	max;

	if (stack_a->range > stack_b->range)
		max = stack_a->range;
	else
		max = stack_b->range;
	return (max);
}
