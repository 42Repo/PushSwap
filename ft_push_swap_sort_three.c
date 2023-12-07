/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_sort_three.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:15:24 by asuc              #+#    #+#             */
/*   Updated: 2023/12/04 14:39:42 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	sort_three(t_stack *stack_a)
{
	t_list_node	*max;

	max = find_max(stack_a);
	if (max == stack_a->top)
	{
		ra(stack_a);
		if (stack_a->top->content > stack_a->top->next->content)
			sa(stack_a);
	}
	else if (max == stack_a->top->next)
	{
		rra(stack_a);
		if (stack_a->top->content > stack_a->top->next->content)
			sa(stack_a);
	}
	else
	{
		if (stack_a->top->content > stack_a->top->next->content)
			sa(stack_a);
	}
	return (0);
}
