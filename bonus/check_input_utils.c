/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:01:58 by asuc              #+#    #+#             */
/*   Updated: 2024/02/10 14:44:50 by asuc             ###   ########.fr       */
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

static char	**free_error_join(char **fake_argv)
{
	free_argv(&fake_argv);
	return (NULL);
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

char	**ft_join_argv(char **fake_argv, char **argv, int argc)
{
	int		i;
	int		j;
	int		len;
	char	**new_argv;

	i = 0;
	j = 0;
	len = len_argv((fake_argv));
	(void)argc;
	new_argv = ft_calloc(sizeof(char *), argc + len + 1);
	if (new_argv == NULL)
		return (free_error_join(fake_argv));
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
