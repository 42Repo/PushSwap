/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:09:04 by asuc              #+#    #+#             */
/*   Updated: 2023/12/04 14:09:42 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	update_links(t_stack *dest, t_list_node *tmp)
{
	if (dest->top == NULL)
	{
		dest->top = tmp;
		dest->bottom = tmp;
	}
	else if (dest->bottom == dest->top)
	{
		dest->top->next = tmp;
		dest->bottom = tmp;
		dest->bottom->previous = dest->top;
	}
	else
	{
		dest->top->previous = tmp;
		tmp->next = dest->top;
		dest->top = tmp;
	}
}

/* (push) : Prend le premier élément de src et le met au debut de dest*/
int	push(t_stack *dest, t_stack *src)
{
	t_list_node	*tmp;

	if (src == NULL || src->top == NULL)
		return (-1);
	tmp = src->top;
	src->top = src->top->next;
	if (src->top != NULL)
		src->top->previous = NULL;
	tmp->previous = NULL;
	tmp->next = NULL;
	update_links(dest, tmp);
	return (0);
}

int	pa(t_stack *stack_a, t_stack *stack_b)
{
	return (push(stack_b, stack_a));
}

int	pb(t_stack *stack_a, t_stack *stack_b)
{
	return (push(stack_a, stack_b));
}
