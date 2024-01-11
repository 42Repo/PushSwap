/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:01:58 by asuc              #+#    #+#             */
/*   Updated: 2024/01/11 18:40:31 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	has_multiple_nb(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) == 1)
		i++;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1 || str[i] == '-' || str[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

int	len_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

char	**ft_join_argv(char **fake_argv, char **argv, int argc)
{
	int		i;
	int		j;
	char	**new_argv;
	int		len;

	len = len_argv(argv);
	new_argv = ft_calloc(sizeof(char *), argc + len + 1);
	i = 0;
	j = 0;
	while (fake_argv[i] != NULL)
	{
		new_argv[i] = ft_strdup(fake_argv[i]);
		i++;
	}
	while (argv[j] != NULL)
	{
		new_argv[i] = ft_strdup(argv[j]);
		i++;
		j++;
	}
	new_argv[i] = NULL;
	free_argv(&fake_argv);
	return (new_argv);
}
