/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_instruction.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:06:25 by asuc              #+#    #+#             */
/*   Updated: 2023/11/26 15:26:02 by asuc             ###   ########.fr       */
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
	if (swap(stack_a) == -1 || swap(stack_b) == -1)
		return (-1);
	return (0);
}

/* (push a) : Prend le premier élément au sommet de b et le met sur a.
	Ne fait rien si b est vide.*/
int	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_list_node	*tmp;

	if (stack_b->top == NULL)
		return (-1);
	tmp = stack_b->top;
	
	return (0);
}

/* (push b) : Prend le premier élément au sommet de a et le met sur b.
	Ne fait rien si a est vide.*/
int	pb(void)
{
	return (0);
}

/* (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
	Le premier élément devient le dernier.*/
int	ra(void)
{
	return (0);
}

/* (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
	Le premier élément devient le dernier.*/

int	rb(void)
{
	return (0);
}

/* (rotate r) : ra et rb en même temps.*/
int	rr(void)
{
	return (0);
}

/* (reverse rotate a) : Décale d’une position vers le bas tous les élements de
	la pile a. Le dernier élément devient le premier.*/
int	rra(void)
{
	return (0);
}

/* (reverse rotate b) : Décale d’une position vers le bas tous les élements de
	la pile b. Le dernier élément devient le premier.*/
int	rrb(void)
{
	return (0);
}

/* (reverse rotate r) : rra et rrb en même temps.*/

int	rrr(void)
{
	return (0);
}
