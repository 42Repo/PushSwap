/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_lis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:46:56 by asuc              #+#    #+#             */
/*   Updated: 2023/12/16 23:32:12 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	update_lis(int *arr, int *lis, int *prev, int n, int i, int j)
{
	if (i < n)
	{
		if (j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
			update_lis(arr, lis, prev, n, i, j + 1);
		}
		else
		{
			update_lis(arr, lis, prev, n, i + 1, 0);
		}
	}
}

void	construct_lis(int *arr, int *prev, int *result, int idx, int size,
		int *pos)
{
	if (prev[idx] != -1)
	{
		construct_lis(arr, prev, result, prev[idx], size, pos);
	}
	result[*pos] = arr[idx];
	(*pos)++;
}

int	*find_lis(t_stack *t_stack, int *arr, int n)
{
	int	*lis;
	int	*prev;
	int	*result;
	int	i;
	int	max_lis;
	int	max_idx;
	int	pos;

	max_lis = 0;
	max_idx = 0;
	pos = 0;
	lis = (int *)malloc(n * sizeof(int));
	prev = (int *)malloc(n * sizeof(int));
	if (!lis || !prev)
		return (NULL);
	i = 0;
	while (i < n)
	{
		lis[i] = 1;
		prev[i] = -1;
		i++;
	}
	update_lis(arr, lis, prev, n, 1, 0);
	i = 0;
	while (i < n)
	{
		if (max_lis < lis[i])
		{
			max_lis = lis[i];
			max_idx = i;
		}
		i++;
	}
	result = (int *)ft_calloc(max_lis, sizeof(int));
	if (!result)
		return (NULL);
	construct_lis(arr, prev, result, max_idx, max_lis, &pos);
	t_stack->size_lis = max_lis;
	free(lis);
	free(prev);
	return (result);
}
