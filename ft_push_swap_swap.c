/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:06:25 by asuc              #+#    #+#             */
/*   Updated: 2023/12/17 02:42:23 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* (swap) : Intervertit les 2 premiers éléments au sommet de la pile.
	Ne fait rien s’il n’y en a qu’un ou aucun. */
int	swap(t_stack *stack)
{
	int	tmp;

	if (stack->top == NULL || stack->top->next == NULL)
		return (-1);
	tmp = stack->top->content;
	stack->top->content = stack->top->next->content;
	stack->top->next->content = tmp;
	return (0);
}

/* (swap ss) : sa et sb en même temps.*/
int	ss(t_stack *stack_a, t_stack *stack_b)
{
	// ft_printf("ss\n");
	stack_a->moves[stack_a->nb_moves] = i_ss;
	stack_a->nb_moves++;
	if (swap(stack_a) == -1 || swap(stack_b) == -1)
		return (-1);
	return (0);
}

int	sa(t_stack *stack_a)
{
	// ft_printf("sa\n");
	stack_a->moves[stack_a->nb_moves] = i_sa;
	stack_a->nb_moves++;
	return (swap(stack_a));
}

int	sb(t_stack *stack_b, t_stack *stack_a)
{
	// ft_printf("sb\n");
	stack_a->moves[stack_a->nb_moves] = i_sb;
	stack_a->nb_moves++;
	return (swap(stack_b));
}
