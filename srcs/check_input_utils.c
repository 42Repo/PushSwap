/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:30:17 by asuc              #+#    #+#             */
/*   Updated: 2024/02/10 20:46:50 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	len_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

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

char	**free_all(char **new_argv, int i, char **fake_argv)
{
	while (i >= 0)
	{
		free(new_argv[i]);
		i--;
	}
	free(new_argv);
	free_argv(&fake_argv);
	return (NULL);
}

char	**join_all_argv(char **fake_argv, char **argv, char **new_argv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (fake_argv[i] != NULL)
	{
		new_argv[i] = ft_strdup(fake_argv[i]);
		if (new_argv[i] == NULL)
			return (free_all(new_argv, i - 1, fake_argv));
		i++;
	}
	while (argv[j] != NULL)
	{
		new_argv[i] = ft_strdup(argv[j]);
		if (new_argv[i] == NULL)
			return (free_all(new_argv, i - 1, fake_argv));
		i++;
		j++;
	}
	new_argv[i] = NULL;
	free_argv(&fake_argv);
	return (new_argv);
}

char	**ft_join_argv(char **fake_argv, char **argv, int argc)
{
	int		len;
	char	**new_argv;

	len = len_argv((fake_argv));
	new_argv = ft_calloc(sizeof(char *), argc + len + 1);
	if (new_argv == NULL)
	{
		free_argv(&fake_argv);
		return (NULL);
	}
	new_argv = join_all_argv(fake_argv, argv, new_argv);
	if (new_argv == NULL)
		return (NULL);
	return (new_argv);
}
