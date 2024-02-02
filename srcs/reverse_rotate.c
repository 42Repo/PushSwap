/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:45:18 by asuc              #+#    #+#             */
/*   Updated: 2024/02/02 20:16:55 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

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
	stack_a->moves[stack_a->nb_moves] = i_rra;
	stack_a->nb_moves++;
	return (reverse_rotate(stack_a));
}

int	rrb(t_stack *stack_b, t_stack *stack_a)
{
	stack_a->moves[stack_a->nb_moves] = i_rrb;
	stack_a->nb_moves++;
	return (reverse_rotate(stack_b));
}

/* (reverse rotate r) : rra et rrb en même temps.*/
int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (reverse_rotate(stack_a) == -1 || reverse_rotate(stack_b) == -1)
		return (-1);
	stack_a->moves[stack_a->nb_moves] = i_rrr;
	stack_a->nb_moves++;
	return (0);
}
