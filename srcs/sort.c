/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:48:34 by asuc              #+#    #+#             */
/*   Updated: 2024/02/01 20:25:28 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	update_stack(t_stack *stk_a, t_stack *stk_b)
{
	t_node	*tmp;
	int		rank;

	rank = 0;
	tmp = stk_a->top;
	while (tmp != NULL)
	{
		tmp->rank = rank;
		tmp = tmp->next;
		rank++;
	}
	stk_a->range = rank;
	stk_a->median = stk_a->range / 2;
	tmp = stk_b->top;
	rank = 0;
	while (tmp != NULL)
	{
		tmp->rank = rank;
		tmp = tmp->next;
		rank++;
	}
	stk_b->range = rank;
	stk_b->median = stk_b->range / 2;
}

int	sort_stack(t_stack *stack_a, t_stack *stack_b, int *tab_lis)
{
	if (stack_is_sorted(stack_a) == 0 && stack_a->range > 3)
	{
		pb(stack_a, stack_b);
		update_stack(stack_a, stack_b);
	}
	if (stack_is_sorted(stack_a) == 0 && stack_a->range > 3)
	{
		pb(stack_a, stack_b);
		update_stack(stack_a, stack_b);
	}
	while (stack_a->range > 3 && stack_is_sorted(stack_a) == 0)
	{
		push_cheapeast_number_to_b(stack_a, stack_b, tab_lis);
		update_stack(stack_a, stack_b);
	}
	if (stack_is_sorted(stack_a) == 0)
		sort_three(stack_a);
	update_stack(stack_a, stack_b);
	while (stack_b->range > 0)
	{
		push_cheapeast_number_to_a(stack_a, stack_b);
		update_stack(stack_a, stack_b);
	}
	final_rotate(stack_a);
	return (0);
}

int	main_sort(t_stack *stack_a, t_stack	*stack_b, int range, int *lis_array)
{
	while (stack_is_sorted(stack_a) == 0)
	{
		if (range == 2)
			ra(stack_a);
		else if (range == 3)
			sort_three(stack_a);
		else
			sort_stack(stack_a, stack_b, lis_array);
	}
	return (0);
}
