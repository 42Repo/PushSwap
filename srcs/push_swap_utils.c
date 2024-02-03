/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:06:57 by asuc              #+#    #+#             */
/*   Updated: 2024/02/03 00:03:25 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	init_stack(t_stack *stack_a, t_stack *stack_b, int range)
{
	stack_a->top = NULL;
	stack_a->bottom = NULL;
	stack_b->top = NULL;
	stack_b->bottom = NULL;
	stack_a->range = range;
	stack_b->range = 0;
	stack_a->median = stack_a->range / 2;
	stack_b->median = stack_b->range / 2;
	stack_a->nb_moves = 0;
	stack_a->moves = ft_calloc(sizeof(enum e_instru), (range * range));
	if (stack_a->moves == NULL)
		return (-1);
	return (0);
}

int	final_print(enum e_instru instru)
{
	if (instru == i_ra)
		ft_printf("ra\n");
	else if (instru == i_rb)
		ft_printf("rb\n");
	else if (instru == i_rr)
		ft_printf("rr\n");
	else if (instru == i_rra)
		ft_printf("rra\n");
	else if (instru == i_rrb)
		ft_printf("rrb\n");
	else if (instru == i_rrr)
		ft_printf("rrr\n");
	else if (instru == i_sa)
		ft_printf("sa\n");
	else if (instru == i_sb)
		ft_printf("sb\n");
	else if (instru == i_ss)
		ft_printf("ss\n");
	else if (instru == i_pa)
		ft_printf("pa\n");
	else if (instru == i_pb)
		ft_printf("pb\n");
	return (0);
}
