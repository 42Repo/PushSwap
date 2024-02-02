/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:01:41 by asuc              #+#    #+#             */
/*   Updated: 2024/02/01 21:48:08 by asuc             ###   ########.fr       */
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
	int	range;

	(*fake_argv) = ft_split(argv[1], ' ');
	if ((*fake_argv)[0] == NULL)
	{
		free_argv(fake_argv);
		return (putstr_error("Error\n"));
	}
	(*fake_argv) = ft_join_argv((*fake_argv), argv + 2, argc);
	range = main_check_input_and_fill_tab((*fake_argv), tab);
	if (range == -1)
	{
		free_argv(fake_argv);
		return (-1);
	}
	return (range);
}

int	check_input_main(char **argv, int argc, int **tab)
{
	char	**fake_argv;
	int		range;

	if (argc < 2)
		return (-1);
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

int	compare_line_len_3(char *line, t_stack *stack_a)
{
	if (ft_strncmp(line, "sa", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_sa;
	else if (ft_strncmp(line, "sb", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_sb;
	else if (ft_strncmp(line, "ss", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_ss;
	else if (ft_strncmp(line, "pa", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_pa;
	else if (ft_strncmp(line, "pb", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_pb;
	else if (ft_strncmp(line, "ra", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_ra;
	else if (ft_strncmp(line, "rb", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_rb;
	else if (ft_strncmp(line, "rr", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_rr;
	else
		return (-1);
	return (0);
}

int	parse_instru(char *line, t_stack *stack_a)
{
	if (ft_strlen(line) == 3)
	{
		if (compare_line_len_3(line, stack_a) == -1)
			return (-1);
	}
	else if (ft_strlen(line) == 4)
	{
		if (ft_strncmp(line, "rra", ft_strlen(line) - 1) == 0)
			stack_a->moves[stack_a->nb_moves++] = i_rra;
		else if (ft_strncmp(line, "rrb", ft_strlen(line) - 1) == 0)
			stack_a->moves[stack_a->nb_moves++] = i_rrb;
		else if (ft_strncmp(line, "rrr", ft_strlen(line) - 1) == 0)
			stack_a->moves[stack_a->nb_moves++] = i_rrr;
		else
			return (-1);
	}
	else
		return (-1);
	return (0);
}
