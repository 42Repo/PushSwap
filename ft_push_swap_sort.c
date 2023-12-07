/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:48:34 by asuc              #+#    #+#             */
/*   Updated: 2023/12/07 23:20:25 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_node	*find_closer_to(int nb, t_stack *stack)
{
	t_node	*tmp;
	t_node	*target;
	int		max;

	tmp = stack->top;
	target = NULL;
	while (tmp != NULL)
	{
		if (tmp->content < nb && (target == NULL
				|| tmp->content > target->content))
			target = tmp;
		tmp = tmp->next;
	}
	if (target == NULL)
	{
		tmp = stack->top;
		max = stack->top->content;
		target = stack->top;
		while (tmp != NULL)
		{
			if (max < tmp->content)
			{
				max = tmp->content;
				target = tmp;
			}
			tmp = tmp->next;
		}
	}
	return (target);
}

void	init_tab_instruction(enum e_instru ***tab, int range)
{
	(*tab) = ft_calloc(2, sizeof(enum e_instru *));
	(*tab)[0] = ft_calloc(range, sizeof(enum e_instru));
	(*tab)[1] = ft_calloc(range, sizeof(enum e_instru));
}

/* on calcule le nombre de coups min pour chaque nombre de stack_a pour mettre
	le nombre de stack_a au top de stack_a + mettre le nombre target de
	stack_a au top de stack_b
*/
t_node	*min_lenght(t_stack *stack_a, t_stack *stack_b,
		enum e_instru ***tab_instruction)
{
	t_node				*tmp;
	t_node				*target;
	int					i;
	int					rank_tmp;
	int					moves;
	int					max_moves;
	enum e_instru		**tab_instruction_tmp;

	tab_instruction_tmp = malloc(3 * sizeof(enum e_instru *));
	tab_instruction_tmp[0] = ft_calloc(stack_a->range, sizeof(enum e_instru));
	tab_instruction_tmp[1] = ft_calloc(stack_a->range, sizeof(enum e_instru));
	tab_instruction_tmp[2] = NULL;
	tmp = stack_a->top;
	i = 0;
	moves = 0;
	target = NULL;
	max_moves = stack_a->range * 2;
	while (tmp != NULL)
	{
		rank_tmp = tmp->rank;
		while (rank_tmp != 0)
		{
			if (rank_tmp <= stack_a->median)
			{
				rank_tmp--;
				tab_instruction_tmp[0][i] = i_ra;
				moves++;
			}
			else
			{
				rank_tmp++;
				tab_instruction_tmp[0][i] = i_rra;
				moves++;
			}
			if (rank_tmp == stack_a->range)
				rank_tmp = 0;
			i++;
		}
		rank_tmp = tmp->target->rank;
		i = 0;
		while (rank_tmp != 0)
		{
			if (rank_tmp <= stack_b->median)
			{
				rank_tmp--;
				tab_instruction_tmp[1][i] = i_rb;
				moves++;
			}
			else
			{
				rank_tmp++;
				tab_instruction_tmp[1][i] = i_rrb;
				moves++;
			}
			if (rank_tmp == stack_b->range)
				rank_tmp = 0;
			i++;
		}
		i = 0;
		if (moves < max_moves)
		{
			max_moves = moves;
			while (i < stack_a->range)
			{
				(*tab_instruction)[0][i] = tab_instruction_tmp[0][i];
				(*tab_instruction)[1][i] = tab_instruction_tmp[1][i];
				i++;
			}
			target = tmp;
		}
		i = 0;
		tmp = tmp->next;
	}
	free(tab_instruction_tmp[1]);
	free(tab_instruction_tmp[0]);
	free(tab_instruction_tmp);
	return (target);
}

void	update_stack(t_stack *stk_a, int range_a, t_stack *stk_b, int range_b)
{
	t_node	*tmp;
	int		rank;

	rank = 0;
	stk_a->range = range_a;
	stk_a->median = range_a / 2;
	stk_b->range = range_b;
	stk_b->median = range_b / 2;
	tmp = stk_a->top;
	while (tmp != NULL)
	{
		tmp->rank = rank;
		tmp = tmp->next;
		rank++;
	}
	tmp = stk_b->top;
	rank = 0;
	while (tmp != NULL)
	{
		tmp->rank = rank;
		tmp = tmp->next;
		rank++;
	}
}

void	push_cheapeast(t_stack *stack_a, t_stack *stack_b, t_node *target,
		enum e_instru **tab_instruction_a)
{
	int	i;

	i = 0;
	while (i < target->rank)
	{
		if (tab_instruction_a[0][i] == i_ra)
			ra(stack_a);
		else
			rra(stack_a);
		i++;
	}
	i = 0;
	while (i < target->target->rank)
	{
		if (tab_instruction_a[1][i] == i_rb)
			rb(stack_b);
		else
			rrb(stack_b);
		i++;
	}
	pb(stack_a, stack_b);
}

int	push_cheapeast_number(t_stack *stack_a, t_stack *stack_b)
{
	t_node			*tmp;
	enum e_instru	**tab_instru;

	init_tab_instruction(&tab_instru, stack_a->range);
	tmp = stack_a->top;
	while (stack_a->top != NULL)
	{
		stack_a->top->target = find_closer_to(stack_a->top->content, stack_b);
		stack_a->top = stack_a->top->next;
	}
	stack_a->top = tmp;
	tmp = min_lenght(stack_a, stack_b, &tab_instru);
	push_cheapeast(stack_a, stack_b, tmp, tab_instru);
	free(tab_instru[1]);
	free(tab_instru[0]);
	free(tab_instru);
	return (0);
}



int	sort_stack(t_stack *stack_a, t_stack *stack_b, int range)
{
	(void)range;
	if (stack_is_sorted(stack_a) == 0 && stack_a->range > 3)
	{
		pb(stack_a, stack_b);
		update_stack(stack_a, stack_a->range - 1, stack_b, stack_b->range + 1);
	}
	if (stack_is_sorted(stack_a) == 0 && stack_a->range > 3)
	{
		pb(stack_a, stack_b);
		update_stack(stack_a, stack_a->range - 1, stack_b, stack_b->range + 1);
	}
	while (stack_a->range > 3)
	{
		push_cheapeast_number(stack_a, stack_b);
		update_stack(stack_a, stack_a->range - 1, stack_b, stack_b->range + 1);
	}
	sort_three(stack_a);
	update_stack(stack_a, stack_a->range, stack_b, stack_b->range);
	return (0);
}
