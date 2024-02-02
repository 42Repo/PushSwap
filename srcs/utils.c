/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:36:44 by asuc              #+#    #+#             */
/*   Updated: 2024/02/02 20:16:55 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	putstr_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (-1);
}

t_node	*find_max(t_stack *stack)
{
	t_node	*tmp;
	t_node	*max;

	tmp = stack->top;
	max = tmp;
	while (tmp != NULL)
	{
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_node	*find_min(t_stack *stack)
{
	t_node	*tmp;
	t_node	*min;

	tmp = stack->top;
	min = tmp;
	while (tmp != NULL)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

int	stack_is_sorted(t_stack *stack)
{
	t_node	*tmp;

	if (stack->top == NULL)
		return (-1);
	tmp = stack->top;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
