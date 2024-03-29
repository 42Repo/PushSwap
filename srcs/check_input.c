/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:18:55 by asuc              #+#    #+#             */
/*   Updated: 2024/02/10 15:02:34 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	check_single_string(char ***argv, char ***fake_argv, int **tab, int *range)
{
	(*fake_argv) = ft_split((*argv)[1], ' ');
	if ((*fake_argv) == NULL)
		return (putstr_error("Error\n"));
	(*range) = main_check_input_and_fill_tab((*fake_argv), tab);
	if ((*range) == -1)
	{
		free_argv(fake_argv);
		return (-1);
	}
	free_argv(fake_argv);
	return (*range);
}

int	check_multiple_strings(char ***fake_argv, char **argv, int argc, int **tab)
{
	int	ret;

	(*fake_argv) = ft_split(argv[1], ' ');
	if ((*fake_argv) == NULL)
		return (putstr_error("Error\n"));
	(*fake_argv) = ft_join_argv((*fake_argv), argv + 2, argc);
	if ((*fake_argv) == NULL)
		return (putstr_error("Error\n"));
	ret = main_check_input_and_fill_tab((*fake_argv), tab);
	if (ret == -1)
	{
		free_argv(fake_argv);
		return (-1);
	}
	return (ret);
}

int	check_input_main(char **argv, int argc, int **tab)
{
	char	**fake_argv;
	int		range;

	if (argc != 2 && has_multiple_nb(argv[1]) == 1)
	{
		range = check_multiple_strings(&fake_argv, argv, argc, tab);
		if (range == -1)
			return (-1);
		free_argv(&fake_argv);
	}
	else if (argc == 2)
	{
		range = check_single_string(&argv, &fake_argv, tab, &range);
		if (range == -1)
			return (-1);
	}
	else
		range = main_check_input_and_fill_tab(argv + 1, tab);
	if (range == -1)
		return (-1);
	return (range);
}
