/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:03:54 by asuc              #+#    #+#             */
/*   Updated: 2024/01/07 23:12:25 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

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
		return (putstr_error("Error\n"));
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

void	make_moves(t_stack *stack_a, t_stack *stack_b, int i)
{
	if (stack_a->moves[i] == i_sa)
		sa(stack_a);
	else if (stack_a->moves[i] == i_sb)
		sb(stack_b);
	else if (stack_a->moves[i] == i_ss)
		ss(stack_a, stack_b);
	else if (stack_a->moves[i] == i_pa)
		pa(stack_a, stack_b);
	else if (stack_a->moves[i] == i_pb)
		pb(stack_a, stack_b);
	else if (stack_a->moves[i] == i_ra)
		ra(stack_a);
	else if (stack_a->moves[i] == i_rb)
		rb(stack_b);
	else if (stack_a->moves[i] == i_rr)
		rr(stack_a, stack_b);
	else if (stack_a->moves[i] == i_rra)
		rra(stack_a);
	else if (stack_a->moves[i] == i_rrb)
		rrb(stack_b);
	else if (stack_a->moves[i] == i_rrr)
		rrr(stack_a, stack_b);
}

void	make_moves_loop(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < stack_a->nb_moves)
	{
		make_moves(stack_a, stack_b, i);
		i++;
	}
}
