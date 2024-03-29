/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 07:34:36 by asuc              #+#    #+#             */
/*   Updated: 2024/02/03 00:10:33 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static void	update_lis(int *arr, int *lis, int *prev, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

static int	initialize_arrays(int *arr, int n, int **lis, int **prev)
{
	int	i;

	*lis = (int *)malloc(n * sizeof(int));
	if (!*lis)
		return (-1);
	*prev = (int *)malloc(n * sizeof(int));
	if (!*prev)
	{
		free(*lis);
		return (-1);
	}
	i = 0;
	while (i < n)
	{
		(*lis)[i] = 1;
		(*prev)[i] = -1;
		i++;
	}
	update_lis(arr, *lis, *prev, n);
	return (0);
}

static void	construct_lis(t_lis_data *data, int idx)
{
	if (data->prev[idx] != -1)
	{
		construct_lis(data, data->prev[idx]);
	}
	data->result[data->pos] = data->arr[idx];
	(data->pos)++;
}

static int	find_max_lis_index(int *lis, int n, int *max_lis)
{
	int	i;
	int	max_idx;

	(*max_lis) = 0;
	max_idx = 0;
	i = 0;
	while (i < n)
	{
		if ((*max_lis) < lis[i])
		{
			(*max_lis) = lis[i];
			max_idx = i;
		}
		i++;
	}
	return (max_idx);
}

int	*find_lis(t_stack *t_stack, int *arr, int n)
{
	int			*lis;
	int			max_lis;
	int			max_idx;
	t_lis_data	*lis_data;
	int			*result;

	lis_data = (t_lis_data *)malloc(sizeof(t_lis_data));
	if (!lis_data)
		return (NULL);
	if (initialize_arrays(arr, n, &lis, &lis_data->prev) == -1)
		return (NULL);
	max_idx = find_max_lis_index(lis, n, &max_lis);
	lis_data->result = (int *)ft_calloc(max_lis, sizeof(int));
	if (!lis_data->result)
		return (free_arrays(&lis, lis_data));
	lis_data->pos = 0;
	lis_data->arr = arr;
	construct_lis(lis_data, max_idx);
	t_stack->size_lis = max_lis;
	free(lis);
	free(lis_data->prev);
	result = lis_data->result;
	free(lis_data);
	return (result);
}
