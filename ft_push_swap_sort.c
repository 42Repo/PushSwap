/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:48:34 by asuc              #+#    #+#             */
/*   Updated: 2024/01/08 23:39:14 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	final_rotate(t_stack *stack_a)
{
	t_node	*tmp;

	tmp = find_min(stack_a);
	while (stack_is_sorted(stack_a) == 0)
	{
		if (tmp->rank < stack_a->median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

int	find_max_range(t_stack *stack_a, t_stack *stack_b)
{
	int	max;

	if (stack_a->range > stack_b->range)
		max = stack_a->range;
	else
		max = stack_b->range;
	return (max);
}

t_node	*find_closer_min(int nb, t_stack *stack)
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
	(*tab) = malloc(3 * sizeof(enum e_instru *));
	(*tab)[0] = ft_calloc(range * 100, sizeof(enum e_instru));
	(*tab)[1] = ft_calloc(range * 100, sizeof(enum e_instru));
	(*tab)[2] = NULL;
}

void	set_tab_instruction(enum e_instru *tab, int range)
{
	int	i;

	i = 0;
	while (i < range)
	{
		tab[i] = 0;
		i++;
	}
}

int	optimize_moves(enum e_instru ***tab_instruction_tmp)
{
	int	i;
	int	moves;

	i = 0;
	moves = 0;
	while ((*tab_instruction_tmp)[0][i] != i_nothing
		|| (*tab_instruction_tmp)[1][i] != i_nothing)
	{
		if ((*tab_instruction_tmp)[0][i] == i_ra
			&& (*tab_instruction_tmp)[1][i] == i_rb)
		{
			((*tab_instruction_tmp)[0][i] = i_rr);
			((*tab_instruction_tmp)[1][i] = i_nothing);
			moves++;
		}
		else if ((*tab_instruction_tmp)[0][i] == i_rra
			&& (*tab_instruction_tmp)[1][i] == i_rrb)
		{
			((*tab_instruction_tmp)[0][i] = i_rrr);
			((*tab_instruction_tmp)[1][i] = i_nothing);
			moves++;
		}
		else
		{
			if ((*tab_instruction_tmp)[0][i] != i_nothing)
				moves++;
			if ((*tab_instruction_tmp)[1][i] != i_nothing)
				moves++;
		}
		i++;
	}
	return (moves);
}

int	is_in_tab(int *tab, int nb, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

t_node	*min_lenght(t_stack *stack_a, t_stack *stack_b,
		enum e_instru ***tab_instruction, int *tab)
{
	t_node			*tmp;
	t_node			*target;
	int				i;
	int				rank_tmp;
	int				moves;
	int				max_moves;
	enum e_instru	**tab_instruction_tmp;
	int				max;

	max = find_max_range(stack_a, stack_b);
	init_tab_instruction(&tab_instruction_tmp, max);
	tmp = stack_a->top;
	target = NULL;
	max_moves = stack_b->range * 4;
	while (tmp != NULL)
	{
		moves = 0;
		i = 0;
		set_tab_instruction(tab_instruction_tmp[0], max);
		set_tab_instruction(tab_instruction_tmp[1], max);
		rank_tmp = tmp->rank;
		if (rank_tmp <= stack_a->median)
		{
			while (i < tmp->rank)
			{
				tab_instruction_tmp[0][i] = i_ra;
				i++;
			}
		}
		else
		{
			while (i <= (stack_a->range - tmp->rank) - 1)
			{
				tab_instruction_tmp[0][i] = i_rra;
				i++;
			}
		}
		rank_tmp = tmp->target->rank;
		i = 0;
		if (rank_tmp <= stack_b->median)
		{
			while (i < tmp->target->rank)
			{
				tab_instruction_tmp[1][i] = i_rb;
				i++;
			}
		}
		else
		{
			while (i <= (stack_b->range - tmp->target->rank) - 1)
			{
				tab_instruction_tmp[1][i] = i_rrb;
				i++;
			}
		}
		i = 0;
		moves = optimize_moves(&tab_instruction_tmp);
		if (moves < max_moves && is_in_tab(tab, tmp->content,
				stack_a->size_lis) == 0)
		{
			max_moves = moves;
			set_tab_instruction((*tab_instruction)[0], max);
			set_tab_instruction((*tab_instruction)[1], max);
			while (i < max)
			{
				(*tab_instruction)[0][i] = tab_instruction_tmp[0][i];
				(*tab_instruction)[1][i] = tab_instruction_tmp[1][i];
				i++;
			}
			target = tmp;
		}
		if (max_moves <= 1)
			break ;
		tmp = tmp->next;
	}
	free(tab_instruction_tmp[1]);
	free(tab_instruction_tmp[0]);
	free(tab_instruction_tmp);
	return (target);
}

void	update_stack(t_stack *stk_a, t_stack *stk_b)
{
	t_node	*tmp;
	int		rank;

	rank = 0;
	tmp = stk_a->top;
	while (tmp != NULL)
	{
		tmp->rank = rank;
		tmp = tmp->next;
		rank++;
	}
	stk_a->range = rank;
	stk_a->median = stk_a->range / 2;
	tmp = stk_b->top;
	rank = 0;
	while (tmp != NULL)
	{
		tmp->rank = rank;
		tmp = tmp->next;
		rank++;
	}
	stk_b->range = rank;
	stk_b->median = stk_b->range / 2;
}

void	push_cheapeast(t_stack *stack_a, t_stack *stack_b,
		enum e_instru **tab_instruction)
{
	int	i;
	int	max;

	i = 0;
	max = find_max_range(stack_a, stack_b);
	while (i < max)
	{
		if (tab_instruction[0][i] == i_ra)
			ra(stack_a);
		else if (tab_instruction[0][i] == i_rra)
			rra(stack_a);
		else if (tab_instruction[0][i] == i_rr)
			rr(stack_a, stack_b);
		else if (tab_instruction[0][i] == i_rrr)
			rrr(stack_a, stack_b);
		i++;
	}
	i = 0;
	while (i < max)
	{
		if (tab_instruction[1][i] == i_rb)
			rb(stack_b, stack_a);
		else if (tab_instruction[1][i] == i_rrb)
			rrb(stack_b, stack_a);
		i++;
	}
	pb(stack_a, stack_b);
}

int	push_cheapeast_number_to_b(t_stack *stack_a, t_stack *stack_b, int *tab)
{
	t_node			*tmp;
	enum e_instru	**tab_instru;

	if (stack_a->range > stack_b->range)
	{
		init_tab_instruction(&tab_instru, stack_a->range);
	}
	else
	{
		init_tab_instruction(&tab_instru, stack_b->range);
	}
	tmp = stack_a->top;
	while (stack_a->top != NULL)
	{
		stack_a->top->target = find_closer_min(stack_a->top->content, stack_b);
		stack_a->top = stack_a->top->next;
	}
	stack_a->top = tmp;
	tmp = min_lenght(stack_a, stack_b, &tab_instru, tab);
	if (tmp == NULL)
	{
		final_rotate(stack_a);
		free(tab_instru[1]);
		free(tab_instru[0]);
		free(tab_instru);
		return (0);
	}
	push_cheapeast(stack_a, stack_b, tab_instru);
	free(tab_instru[1]);
	free(tab_instru[0]);
	free(tab_instru);
	return (0);
}

t_node	*find_closer_to_sup(int nb, t_stack *stack)
{
	t_node	*tmp;
	t_node	*target;
	int		min;

	tmp = stack->top;
	target = NULL;
	while (tmp != NULL)
	{
		if (tmp->content > nb && (target == NULL
				|| tmp->content < target->content))
			target = tmp;
		tmp = tmp->next;
	}
	if (target == NULL)
	{
		tmp = stack->top;
		min = stack->top->content;
		target = stack->top;
		while (tmp != NULL)
		{
			if (min > tmp->content)
			{
				min = tmp->content;
				target = tmp;
			}
			tmp = tmp->next;
		}
	}
	return (target);
}

t_node	*min_lenght_a(t_stack *stack_b, t_stack *stack_a,
		enum e_instru ***tab_instruction)
{
	t_node			*tmp;
	t_node			*target;
	int				i;
	int				rank_tmp;
	int				moves;
	int				max_moves;
	enum e_instru	**tab_instruction_tmp;
	int				max;

	max = find_max_range(stack_a, stack_b);
	init_tab_instruction(&tab_instruction_tmp, max);
	tmp = stack_b->top;
	target = NULL;
	max_moves = max * 4;
	while (tmp != NULL)
	{
		moves = 0;
		i = 0;
		set_tab_instruction(tab_instruction_tmp[0], max);
		set_tab_instruction(tab_instruction_tmp[1], max);
		rank_tmp = tmp->rank;
		while (rank_tmp != 0)
		{
			if (rank_tmp <= stack_b->median)
			{
				rank_tmp--;
				tab_instruction_tmp[0][i] = i_rb;
				moves++;
			}
			else
			{
				rank_tmp++;
				tab_instruction_tmp[0][i] = i_rrb;
				moves++;
			}
			if (rank_tmp == stack_b->range)
				rank_tmp = 0;
			i++;
		}
		rank_tmp = tmp->target->rank;
		i = 0;
		while (rank_tmp != 0)
		{
			if (rank_tmp <= stack_a->median)
			{
				rank_tmp--;
				tab_instruction_tmp[1][i] = i_ra;
				moves++;
			}
			else
			{
				rank_tmp++;
				tab_instruction_tmp[1][i] = i_rra;
				moves++;
			}
			if (rank_tmp == stack_a->range)
				rank_tmp = 0;
			i++;
		}
		i = 0;
		moves = optimize_moves(&tab_instruction_tmp);
		if (moves < max_moves)
		{
			max_moves = moves;
			set_tab_instruction((*tab_instruction)[0], max);
			set_tab_instruction((*tab_instruction)[1], max);
			while (i < max)
			{
				(*tab_instruction)[0][i] = tab_instruction_tmp[0][i];
				(*tab_instruction)[1][i] = tab_instruction_tmp[1][i];
				i++;
			}
			target = tmp;
		}
		if (max_moves == 0)
			break ;
		tmp = tmp->next;
	}
	free(tab_instruction_tmp[1]);
	free(tab_instruction_tmp[0]);
	free(tab_instruction_tmp);
	return (target);
}

void	push_cheapeast_a(t_stack *stack_b, t_stack *stack_a,
		enum e_instru **tab_instruction)
{
	int	i;

	i = 0;
	while (i < (stack_a->range))
	{
		if (tab_instruction[0][i] == i_rb)
			rb(stack_b, stack_a);
		else if (tab_instruction[0][i] == i_rrb)
			rrb(stack_b, stack_a);
		i++;
	}
	i = 0;
	while (i < stack_a->range)
	{
		if (tab_instruction[1][i] == i_ra)
			ra(stack_a);
		else if (tab_instruction[1][i] == i_rra)
			rra(stack_a);
		i++;
	}
	pa(stack_a, stack_b);
}

void	push_cheapeast_number_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node			*tmp;
	enum e_instru	**tab_instru;

	if (stack_a->range > stack_b->range)
	{
		init_tab_instruction(&tab_instru, stack_a->range);
	}
	else
	{
		init_tab_instruction(&tab_instru, stack_b->range);
	}
	tmp = stack_b->top;
	while (stack_b->top != NULL)
	{
		stack_b->top->target = find_closer_to_sup(stack_b->top->content,
				stack_a);
		stack_b->top = stack_b->top->next;
	}
	stack_b->top = tmp;
	tmp = min_lenght_a(stack_b, stack_a, &tab_instru);
	push_cheapeast_a(stack_b, stack_a, tab_instru);
	free(tab_instru[1]);
	free(tab_instru[0]);
	free(tab_instru);
}

int	sort_stack(t_stack *stack_a, t_stack *stack_b, int *tab_lis)
{
	if (stack_is_sorted(stack_a) == 0 && stack_a->range > 3)
	{
		pb(stack_a, stack_b);
		update_stack(stack_a, stack_b);
	}
	if (stack_is_sorted(stack_a) == 0 && stack_a->range > 3)
	{
		pb(stack_a, stack_b);
		update_stack(stack_a, stack_b);
	}
	while (stack_a->range > 3 && stack_is_sorted(stack_a) == 0)
	{
		push_cheapeast_number_to_b(stack_a, stack_b, tab_lis);
		update_stack(stack_a, stack_b);
	}
	if (stack_is_sorted(stack_a) == 0)
		sort_three(stack_a);
	update_stack(stack_a, stack_b);
	while (stack_b->range > 0)
	{
		push_cheapeast_number_to_a(stack_a, stack_b);
		update_stack(stack_a, stack_b);
	}
	final_rotate(stack_a);
	return (0);
}

int	main_sort(t_stack *stack_a, t_stack	*stack_b, int range, int *lis_array)
{
	while (stack_is_sorted(stack_a) == 0)
	{
		if (range == 2)
			ra(stack_a);
		else if (range == 3)
			sort_three(stack_a);
		else
		{
			sort_stack(stack_a, stack_b, lis_array);
		}
	}
	return (0);
}
