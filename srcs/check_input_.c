/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_check_input_.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:18:55 by asuc              #+#    #+#             */
/*   Updated: 2024/01/11 18:18:00 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check_single_string(char ***argv, char ***fake_argv, int **tab, int *range)
{
	(*fake_argv) = ft_split((*argv)[1], ' ');
	if ((*fake_argv)[0] == NULL)
	{
		free_argv(fake_argv);
		return (putstr_error("Error\n"));
	}
	(*range) = main_check_input_and_fill_tab((*fake_argv), tab);
	free_argv(fake_argv);
	return (*range);
}

int	check_multiple_strings(char ***fake_argv, char **argv, int argc, int **tab)
{
	(*fake_argv) = ft_split(argv[1], ' ');
	if ((*fake_argv)[0] == NULL)
	{
		free_argv(fake_argv);
		return (putstr_error("Error\n"));
	}
	(*fake_argv) = ft_join_argv((*fake_argv), argv + 2, argc);
	return (main_check_input_and_fill_tab((*fake_argv), tab));
}

int	check_input_main(char **argv, int argc, int **tab)
{
	char	**fake_argv;
	int		range;

	if (argc < 2)
		return (0);
	if (argc != 2 && has_multiple_nb(argv[1]) == 1)
	{
		range = check_multiple_strings(&fake_argv, argv, argc, tab);
		if (range == -1)
			return (-1);
		free_argv(&fake_argv);
	}
	else if (argc == 2)
	{
		if (check_single_string(&argv, &fake_argv, tab, &range) == -1)
			return (-1);
	}
	else
		range = main_check_input_and_fill_tab(argv + 1, tab);
	if (range == -1)
		return (-1);
	return (range);
}
