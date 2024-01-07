/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:28:52 by asuc              #+#    #+#             */
/*   Updated: 2024/01/07 23:42:58 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

int	get_instructions(t_stack *stack_a, t_stack *stack_b, char **line)
{
	if (parse_instru((*line), stack_a) == -1)
	{
		free((*line));
		free_stack_final(stack_a, stack_b);
		return (putstr_error("Error\n"));
	}
	free((*line));
	(*line) = get_next_line(0);
	if ((*line) != NULL && (*line)[ft_strlen((*line)) - 1] != '\n')
	{
		free((*line));
		free_stack_final(stack_a, stack_b);
		return (putstr_error("Error\n"));
	}
	return (0);
}

int	checker(int *tab, int range)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*line;

	init_stack(&stack_a, &stack_b, range);
	fill_stack_from_array(&stack_a, tab, range);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (get_instructions(&stack_a, &stack_b, &line) == -1)
			return (-1);
	}
	make_moves_loop(&stack_a, &stack_b);
	if (stack_is_sorted(&stack_a) == 1 && stack_b.top == NULL)
		ft_printf("OK\n");
	else
	{
		ft_printf("KO\n");
	}
	free_stack_final(&stack_a, &stack_b);
	return (range);
}

int	main(int argc, char **argv)
{
	int	res;
	int	range;
	int	*tab;

	if (argc < 2)
		return (0);
	range = check_input_main(argv, argc, &tab);
	if (range == -1)
		return (-1);
	res = checker(tab, range);
	if (res == -1)
	{
		free_tab(&tab);
		return (-1);
	}
	free_tab(&tab);
	return (0);
}
