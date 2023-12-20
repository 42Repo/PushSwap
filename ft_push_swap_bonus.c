/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:28:52 by asuc              #+#    #+#             */
/*   Updated: 2023/12/19 23:08:06 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

int	check_input(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (argc != 2 && has_multiple_nb(argv[1]) == 1)
	{
		fake_argv = ft_split(argv[1], ' ');
		if (fake_argv[0] == NULL)
		{
			free_argv(&fake_argv);
			return (putstr_error("Error\n"));
		}
		fake_argv = ft_join_argv(fake_argv, argv + 2, argc);
		range = main_check_input_and_fill_tab(fake_argv, &tab);
		free_argv(&fake_argv);
	}
	else if (argc == 2)
	{
		fake_argv = ft_split(argv[1], ' ');
		if (fake_argv[0] == NULL)
		{
			free_argv(&fake_argv);
			return (putstr_error("Error\n"));
		}
		range = main_check_input_and_fill_tab(fake_argv, &tab);
		free_argv(&fake_argv);
	}
	else
	{
		range = main_check_input_and_fill_tab(argv + 1, &tab);
	}
	if (range == -1)
	{
		return (-1);
	}
	stack_a.range = range;
	stack_b.range = 0;
	stack_a.median = stack_a.range / 2;
	stack_b.median = stack_b.range / 2;
	stack_a.nb_moves = 0;
	stack_a.moves = ft_calloc(sizeof(enum e_instru), (range * range));
	n = range;
	lis_array = find_lis(&stack_a, tab, n);
	fill_stack_from_array(&stack_a, tab, range);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*tab;
	
	while ()
	{

	}

}
