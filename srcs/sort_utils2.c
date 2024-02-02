/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:27:03 by asuc              #+#    #+#             */
/*   Updated: 2024/02/02 20:16:55 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

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

int	check_lis(t_stack *stack, int range)
{
	t_node	*tmp;
	int		count;

	count = 0;
	tmp = stack->top;
	while (tmp->next != NULL)
	{
		if (tmp->content < tmp->next->content)
			count++;
		tmp = tmp->next;
	}
	if (count != range)
		return (-1);
	return (0);
}

int	free_tab_instruction_and_return(enum e_instru ***tab, int ret)
{
	free_tab_instruction(tab);
	return (ret);
}

int	set_init_tab_construction(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->range > stack_b->range)
	{
		init_tab_instruction(&(stack_a->tab_instru), stack_a->range);
		if (stack_a->tab_instru == NULL)
			return (-1);
	}
	else
	{
		init_tab_instruction(&(stack_a->tab_instru), stack_b->range);
		if (stack_a->tab_instru == NULL)
			return (-1);
	}
	return (0);
}
