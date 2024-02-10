/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_and_create_tab_utils.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:36:03 by asuc              #+#    #+#             */
/*   Updated: 2024/02/10 15:27:31 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

void	skip_initial_chars(char *arg, int *j)
{
	if (arg[*j] == ' ' || arg[*j] == '\t')
		(*j)++;
	if (arg[*j] == '-' || arg[*j] == '+')
		(*j)++;
}

int	check_max_length(char **argv)
{
	int	i;
	int	j;
	int	count;
	int	bol;

	i = 0;
	while (argv[i])
	{
		j = 0;
		count = 0;
		bol = 0;
		skip_initial_chars(argv[i], &j);
		while (ft_isdigit(argv[i][j]))
		{
			if (argv[i][j] != '0' && bol == 0)
				bol = 1;
			else if (bol == 1)
				count++;
			j++;
		}
		if (count > 11)
			return (-1);
		i++;
	}
	return (0);
}

int	check_input_nothing(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] == ' ' || argv[i][j] == '\t')
			j++;
		if (argv[i][j] == '\0')
			return (-1);
		i++;
	}
	if (i == 0)
		return (-1);
	return (0);
}
