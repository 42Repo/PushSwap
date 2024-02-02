/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:24:36 by asuc              #+#    #+#             */
/*   Updated: 2024/02/02 01:32:38 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_node	*find_target_max(t_stack *stack, int nb)
{
	t_node	*tmp;
	t_node	*target;

	tmp = stack->top;
	target = NULL;
	while (tmp != NULL)
	{
		if (tmp->content > nb && (target == NULL
				|| tmp->content < target->content))
			target = tmp;
		tmp = tmp->next;
	}
	return (target);
}

t_node	*find_min_max(t_stack *stack)
{
	t_node	*tmp;
	t_node	*target;
	int		min;

	tmp = stack->top;
	min = stack->top->content;
	target = stack->top;
	while (tmp != NULL)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
			target = tmp;
		}
		tmp = tmp->next;
	}
	return (target);
}

t_node	*find_closer_to_sup(int nb, t_stack *stack)
{
	t_node	*target;

	target = find_target_max(stack, nb);
	if (target == NULL)
	{
		target = find_min_max(stack);
	}
	return (target);
}

void	push_cheapeast_a(t_stack *stack_b, t_stack *stack_a)
{
	int	i;

	i = 0;
	while (i < (stack_a->range))
	{
		if (stack_a->tab_instru[0][i] == i_rb)
			rb(stack_b, stack_a);
		else if (stack_a->tab_instru[0][i] == i_rrb)
			rrb(stack_b, stack_a);
		i++;
	}
	i = 0;
	while (i < stack_a->range)
	{
		if (stack_a->tab_instru[1][i] == i_ra)
			ra(stack_a);
		else if (stack_a->tab_instru[1][i] == i_rra)
			rra(stack_a);
		i++;
	}
	pa(stack_a, stack_b);
}

int	push_cheapeast_number_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node			*tmp;

	if (set_init_tab_construction(stack_a, stack_b) == -1)
		return (-1);
	tmp = stack_b->top;
	while (stack_b->top != NULL)
	{
		stack_b->top->target = find_closer_to_sup(stack_b->top->content,
				stack_a);
		stack_b->top = stack_b->top->next;
	}
	stack_b->top = tmp;
	tmp = min_lenght_a(stack_b, stack_a);
	if (tmp == NULL && check_lis(stack_b, 2) == -1)
	{
		free_tab_instruction(&(stack_a->tab_instru));
		return (-1);
	}
	push_cheapeast_a(stack_b, stack_a);
	free_tab_instruction(&(stack_a->tab_instru));
	return (0);
}
