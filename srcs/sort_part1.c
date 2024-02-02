/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:15:01 by asuc              #+#    #+#             */
/*   Updated: 2024/02/02 20:16:55 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

t_node	*find_target_min(t_stack *stack, int nb)
{
	t_node	*tmp;
	t_node	*target;

	tmp = stack->top;
	target = NULL;
	while (tmp != NULL)
	{
		if (tmp->content < nb && (target == NULL
				|| tmp->content > target->content))
			target = tmp;
		tmp = tmp->next;
	}
	return (target);
}

t_node	*find_max_min(t_stack *stack)
{
	t_node	*tmp;
	t_node	*max_node;
	int		max_value;

	tmp = stack->top;
	max_node = stack->top;
	max_value = stack->top->content;
	while (tmp != NULL)
	{
		if (max_value < tmp->content)
		{
			max_value = tmp->content;
			max_node = tmp;
		}
		tmp = tmp->next;
	}
	return (max_node);
}

t_node	*find_closer_min(int nb, t_stack *stack)
{
	t_node	*target;

	target = find_target_min(stack, nb);
	if (target == NULL)
		target = find_max_min(stack);
	return (target);
}

void	push_cheapeast(t_stack *stack_a, t_stack *stack_b,
		enum e_instru **tab_instruction)
{
	int	i;
	int	max;

	i = 0;
	max = find_max_range(stack_a, stack_b);
	while (i < max)
	{
		if (tab_instruction[0][i] == i_ra)
			ra(stack_a);
		else if (tab_instruction[0][i] == i_rra)
			rra(stack_a);
		else if (tab_instruction[0][i] == i_rr)
			rr(stack_a, stack_b);
		else if (tab_instruction[0][i] == i_rrr)
			rrr(stack_a, stack_b);
		if (tab_instruction[1][i] == i_rb)
			rb(stack_b, stack_a);
		else if (tab_instruction[1][i] == i_rrb)
			rrb(stack_b, stack_a);
		i++;
	}
	pb(stack_a, stack_b);
}

int	push_cheapeast_number_to_b(t_stack *stack_a, t_stack *stack_b, int *tab)
{
	t_node			*tmp;

	if (set_init_tab_construction(stack_a, stack_b) == -1)
		return (-1);
	tmp = stack_a->top;
	while (stack_a->top != NULL)
	{
		stack_a->top->target = find_closer_min(stack_a->top->content, stack_b);
		stack_a->top = stack_a->top->next;
	}
	stack_a->top = tmp;
	tmp = min_lenght(stack_a, stack_b, tab);
	if (tmp == NULL)
	{
		if (check_lis(stack_a, 2) == -1 && stack_a->size_lis == 0)
			return (free_tab_instruction_and_return(&(stack_a->tab_instru),
					-1));
		final_rotate(stack_a);
		free_tab_instruction(&(stack_a->tab_instru));
		return (0);
	}
	push_cheapeast(stack_a, stack_b, stack_a->tab_instru);
	free_tab_instruction(&(stack_a->tab_instru));
	return (0);
}
