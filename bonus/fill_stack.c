/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_fill_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:28:19 by asuc              #+#    #+#             */
/*   Updated: 2024/01/11 18:21:17 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

t_node	*create_new_node(int content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

void	push_to_stack(t_stack *stack, t_node *new_node)
{
	if (!stack->top)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		stack->bottom->next = new_node;
		new_node->previous = stack->bottom;
		stack->bottom = new_node;
	}
}

void	clear_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	stack->top = NULL;
	stack->bottom = NULL;
}

void	fill_stack_from_array(t_stack *stack, int *array, int size)
{
	int			i;
	t_node		*new_node;

	i = 0;
	while (i < size)
	{
		new_node = create_new_node(array[i]);
		if (!new_node)
		{
			clear_stack(stack);
			return ;
		}
		new_node->rank = i;
		push_to_stack(stack, new_node);
		stack->range = i + 1;
		stack->median = stack->range / 2;
		i++;
	}
}
