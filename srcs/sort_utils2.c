/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:27:03 by asuc              #+#    #+#             */
/*   Updated: 2024/02/01 20:27:27 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	final_rotate(t_stack *stack_a)
{
	t_node	*tmp;

	tmp = find_min(stack_a);
	while (stack_is_sorted(stack_a) == 0)
	{
		if (tmp->rank < stack_a->median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	free_tab_instruction(enum e_instru ***tab)
{
	free((*tab)[1]);
	free((*tab)[0]);
	free((*tab));
}
