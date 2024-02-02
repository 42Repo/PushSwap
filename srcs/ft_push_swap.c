/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:28:20 by asuc              #+#    #+#             */
/*   Updated: 2024/02/02 20:43:16 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	lis_and_sort(t_stack *stack_a, t_stack *stack_b, int *tab, int range)
{
	int		*lis_array;

	lis_array = find_lis(stack_a, tab, range);
	if (lis_array == NULL)
	{
		free_stack_final(stack_a, stack_b);
		return (-1);
	}
	if (fill_stack_from_array(stack_a, tab, range))
	{
		free(lis_array);
		clear_stack(stack_b);
		return (-1);
	}
	if (main_sort(stack_a, stack_b, range, lis_array) == -1)
	{
		free(lis_array);
		free_stack_final(stack_a, stack_b);
		return (-1);
	}
	free(lis_array);
	return (0);
}

int	push_swap_with_lis(int print, int *tab, int range)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;

	i = 0;
	init_stack(&stack_a, &stack_b, range);
	if (stack_a.moves == NULL)
		return (-1);
	lis_and_sort(&stack_a, &stack_b, tab, range);
	while (i < stack_a.nb_moves && print == 1)
		final_print(stack_a.moves[i++]);
	range = stack_a.nb_moves;
	free_stack_final(&stack_a, &stack_b);
	return (range);
}

int	fill_and_sort(t_stack *stack_a, t_stack *stack_b, int *tab, int range)
{
	int	*lis_array;

	lis_array = NULL;
	stack_a->size_lis = 0;
	if (fill_stack_from_array(stack_a, tab, range) == -1)
	{
		clear_stack(stack_b);
		return (-1);
	}
	if (main_sort(stack_a, stack_b, range, lis_array) == -1)
	{
		free_stack_final(stack_a, stack_b);
		return (-1);
	}
	return (0);
}

int	push_swap_without_lis(int print, int *tab, int range)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;

	init_stack(&stack_a, &stack_b, range);
	if (stack_a.moves == NULL)
		return (-1);
	if (fill_and_sort(&stack_a, &stack_b, tab, range) == -1)
		return (-1);
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
		return (-1);
	res_bis = push_swap_without_lis(0, tab, range);
	if (res_bis == -1)
		return (free_error(&tab));
	res = push_swap_with_lis(0, tab, range);
	if (res == -1)
		return (free_error(&tab));
	if (res > res_bis)
		push_swap_without_lis(1, tab, range);
	else
		push_swap_with_lis(1, tab, range);
	free_tab(&tab);
	return (0);
}
