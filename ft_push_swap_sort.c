/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:48:34 by asuc              #+#    #+#             */
/*   Updated: 2023/12/06 10:41:55 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	t_list_node	*tmp;

	tmp = stack->top;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	sort_stack(t_stack *stack_a, t_stack *stack_b, int range)
{
	if (stack_is_sorted(stack_a) == 0 && range-- > 3)
		push(stack_a, stack_b);
	if (stack_is_sorted(stack_a) == 0 && range-- > 3)
		push(stack_a, stack_b);
	while (range-- > 3 && stack_is_sorted(stack_a) == 0)
	{
		
	}

	return (0);
}
