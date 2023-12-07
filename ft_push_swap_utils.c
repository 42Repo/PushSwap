/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:36:44 by asuc              #+#    #+#             */
/*   Updated: 2023/12/07 17:56:07 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
