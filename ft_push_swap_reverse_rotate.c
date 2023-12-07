/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:45:18 by asuc              #+#    #+#             */
/*   Updated: 2023/12/07 17:56:07 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* (reverse rotate) : Décale d’une position vers le bas tous les élements
	Le dernier élément devient le premier.*/
int	reverse_rotate(t_stack *stack)
{
	t_node	*tmp;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return (-1);
	tmp = stack->bottom;
	stack->bottom = stack->bottom->previous;
	stack->bottom->next = NULL;
	tmp->next = stack->top;
	tmp->previous = NULL;
	stack->top->previous = tmp;
	stack->top = tmp;
	return (0);
}

int	rra(t_stack *stack_a)
{
	ft_printf("rra\n");
	return (reverse_rotate(stack_a));
}

int	rrb(t_stack *stack_b)
{
	ft_printf("rrb\n");
	return (reverse_rotate(stack_b));
}

/* (reverse rotate r) : rra et rrb en même temps.*/
int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (reverse_rotate(stack_a) == -1 || reverse_rotate(stack_b) == -1)
		return (-1);
	ft_printf("rrr\n");
	return (0);
}
