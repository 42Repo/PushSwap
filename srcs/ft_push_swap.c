/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:28:20 by asuc              #+#    #+#             */
/*   Updated: 2024/02/02 18:43:03 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

int	push_swap_with_lis(int print, int *tab, int range)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*lis_array;
	int		i;

	i = 0;
	init_stack(&stack_a, &stack_b, range);
	if (stack_a.moves == NULL)
		return (-1);
	lis_array = find_lis(&stack_a, tab, range);
	if (lis_array == NULL)
	{
		free_stack_final(&stack_a, &stack_b);
		return (-1);
	}
	if (fill_stack_from_array(&stack_a, tab, range))
	{
		free(lis_array);
		clear_stack(&stack_b);
		return (-1);
	}
	if (main_sort(&stack_a, &stack_b, range, lis_array) == -1)
	{
		free(lis_array);
		free_stack_final(&stack_a, &stack_b);
		return (-1);
	}
	free(lis_array);
	while (i < stack_a.nb_moves && print == 1)
		final_print(stack_a.moves[i++]);
	range = stack_a.nb_moves;
	free_stack_final(&stack_a, &stack_b);
	return (range);
}

int	push_swap_without_lis(int print, int *tab, int range)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*lis_array;
	int		i;

	init_stack(&stack_a, &stack_b, range);
	if (stack_a.moves == NULL)
		return (-1);
	lis_array = NULL;
	stack_a.size_lis = 0;
	if (fill_stack_from_array(&stack_a, tab, range) == -1)
	{
		clear_stack(&stack_b);
		return (-1);
	}
	if (main_sort(&stack_a, &stack_b, range, lis_array) == -1)
	{
		free_stack_final(&stack_a, &stack_b);
		return (-1);
	}
	i = 0;
	while (i < stack_a.nb_moves && print == 1)
	{
		final_print(stack_a.moves[i]);
		i++;
	}
	range = stack_a.nb_moves;
	free_stack_final(&stack_a, &stack_b);
	return (range);
}

int	main(int argc, char **argv)
{
	int	res;
	int	range;
	int	*tab;
	int	res_bis;

	if (argc < 2)
		return (ft_putstr_fd("Error\n", 2));
	tab = NULL;
	range = check_input_main(argv, argc, &tab);
	if (range == -1)
		return (ft_putstr_fd("Error1\n", 2));
	res_bis = push_swap_without_lis(0, tab, range);
	if (res_bis == -1)
	{
		free_tab(&tab);
		return (ft_putstr_fd("Error2\n", 2));
	}
	res = push_swap_with_lis(0, tab, range);
	if (res == -1)
	{
		free_tab(&tab);
		return (ft_putstr_fd("Error3\n", 2));
	}
	if (res > res_bis)
		push_swap_without_lis(1, tab, range);
	else
		push_swap_with_lis(1, tab, range);
	free_tab(&tab);
	return (0);
}
