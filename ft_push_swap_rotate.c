/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:09:47 by asuc              #+#    #+#             */
/*   Updated: 2023/12/07 17:56:07 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* (rotate) : Décale d’une position vers le haut tous les élements de la pile :
	Pour ca on a juste a mettre le bottom au top et decaler le top de 1 */
int	rotate(t_stack *stack)
{
	t_node	*tmp;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return (-1);
	tmp = stack->top;
	stack->top = stack->top->next;
	stack->top->previous = NULL;
	tmp->next = NULL;
	tmp->previous = stack->bottom;
	stack->bottom->next = tmp;
	stack->bottom = tmp;
	return (0);
}

/* (rotate r) : ra et rb en même temps.*/
int	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (ra(stack_a) == -1 || rb(stack_b) == -1)
		return (-1);
	ft_printf("rr\n");
	return (0);
}

int	ra(t_stack *stack_a)
{
	ft_printf("ra\n");
	return (rotate(stack_a));
}

int	rb(t_stack *stack_b)
{
	ft_printf("rb\n");
	return (rotate(stack_b));
}
