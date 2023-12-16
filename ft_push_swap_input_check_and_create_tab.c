/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_input_check_and_create_tab.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:26:33 by asuc              #+#    #+#             */
/*   Updated: 2023/12/16 22:19:54 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// check tout les argument de argv pour etre sur que ce ne soit que des chiffres
int	check_input(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

// check si il y a des
int	range_tab(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	search_in_tab_int(int *tab, int nb)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		if (tab[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

int	fill_tab_and_check_double(int **tab, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (search_in_tab_int((*tab), ft_atoi(argv[i])) == 1)
		{
			free((*tab));
			return (-1);
		}
		(*tab)[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	return (0);
}

int	main_check_input_and_fill_tab(char **argv, int **tab)
{
	int	range;

	if (check_input(argv) == -1)
		return (putstr_error("Error\n"));
	range = range_tab(argv);
	(*tab) = ft_calloc(range, sizeof(int));
	if (!(*tab))
		return (putstr_error("Error\n"));
	if (fill_tab_and_check_double(tab, argv) == -1)
		return (putstr_error("Error\n"));
	return (range);
}
