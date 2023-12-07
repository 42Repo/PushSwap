/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:36:26 by asuc              #+#    #+#             */
/*   Updated: 2023/12/07 18:51:04 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

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

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
}

int	main(int argc, char **argv)
{
	int		i;
	int		range;
	int		*tab;
	t_stack	stack_a;
	t_stack	stack_b;
	// TEST
	(void)argv;
	char *fake_argv[] = {"624", "6546", "66", "65", "213", "45", "6", "634", "62444", "9", NULL};
	// TEST
	init_stack(&stack_a);
	init_stack(&stack_b);
	argc = 11; // TEST
	i = 0;
	if (argc < 2)
		return (0);
	range = main_check_input_and_fill_tab(fake_argv, &tab);
	if (range == -1)
		return (-1);
	stack_a.range = range;
	stack_b.range = 0;
	stack_a.median = stack_a.range / 2;
	stack_b.median = stack_b.range / 2;
	fill_stack_from_array(&stack_a, tab, range);
	while (stack_is_sorted(&stack_a) == 0)
	{
		if (range == 2)
			swap(&stack_a);
		else if (range == 3)
			sort_three(&stack_a);
		else
			sort_stack(&stack_a, &stack_b, range);
	}
	// TEST
	t_node *tmp = stack_a.top;
	while (i < range)
	{
		ft_printf("%d\n", stack_a.top->content);
		stack_a.top = stack_a.top->next;
		i++;
	}
	stack_a.top = tmp;
	// TEST
	free_tab(&tab);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
