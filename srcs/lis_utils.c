/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 07:55:14 by asuc              #+#    #+#             */
/*   Updated: 2024/02/02 20:16:55 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	*free_arrays(int **lis, t_lis_data *lis_data)
{
	free(*lis);
	free(lis_data->prev);
	free(lis_data);
	return (NULL);
}
