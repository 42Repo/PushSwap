/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:36:26 by asuc              #+#    #+#             */
/*   Updated: 2023/12/01 20:00:14 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	free_stack(t_stack *stack)
{
	t_list_node	*tmp;

	while (stack->top != NULL)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
}

void	free_tab(int **tab)
{
	free(*tab);
	*tab = NULL;
}

int	main(int argc, char **argv)
{
	int		i;
	int		range;
	int		*tab;
	t_stack	stack_a;
	t_stack	stack_b;

	i = 0;
	if (argc < 2)
		return (0);
	range = main_check_input_and_fill_tab(argv + 1, &tab);
	if (range == -1)
		return (-1);
	fill_stack_from_array(&stack_a, tab, range);
	while (i < range)
	{
		ft_printf("%d\n", stack_a.top->content);
		stack_a.top = stack_a.top->next;
		i++;
	}
	free_tab(&tab);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
