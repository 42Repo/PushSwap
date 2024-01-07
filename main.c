/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:28:20 by asuc              #+#    #+#             */
/*   Updated: 2024/01/07 22:27:10 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	init_stack(t_stack *stack_a, t_stack *stack_b, int range)
{
	stack_a->top = NULL;
	stack_a->bottom = NULL;
	stack_b->top = NULL;
	stack_b->bottom = NULL;
	stack_a->range = range;
	stack_b->range = 0;
	stack_a->median = stack_a->range / 2;
	stack_b->median = stack_b->range / 2;
	stack_a->nb_moves = 0;
	stack_a->moves = ft_calloc(sizeof(enum e_instru), (range * range));
	if (stack_a->moves == NULL)
		return (putstr_error("Error\n"));
	return (0);
}

int	final_print(enum e_instru instru)
{
	if (instru == i_ra)
		ft_printf("ra\n");
	else if (instru == i_rb)
		ft_printf("rb\n");
	else if (instru == i_rr)
		ft_printf("rr\n");
	else if (instru == i_rra)
		ft_printf("rra\n");
	else if (instru == i_rrb)
		ft_printf("rrb\n");
	else if (instru == i_rrr)
		ft_printf("rrr\n");
	else if (instru == i_sa)
		ft_printf("sa\n");
	else if (instru == i_sb)
		ft_printf("sb\n");
	else if (instru == i_ss)
		ft_printf("ss\n");
	else if (instru == i_pa)
		ft_printf("pa\n");
	else if (instru == i_pb)
		ft_printf("pb\n");
	return (0);
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

int	check_input_main(char **argv, int argc, int **tab)
{
	char	**fake_argv;
	int		range;

	if (argc < 2)
		return (0);
	if (argc != 2 && has_multiple_nb(argv[1]) == 1)
	{
		fake_argv = ft_split(argv[1], ' ');
		if (fake_argv[0] == NULL)
		{
			free_argv(&fake_argv);
			return (putstr_error("Error\n"));
		}
		fake_argv = ft_join_argv(fake_argv, argv + 2, argc);
		range = main_check_input_and_fill_tab(fake_argv, tab);
		free_argv(&fake_argv);
	}
	else if (argc == 2)
	{
		fake_argv = ft_split(argv[1], ' ');
		if (fake_argv[0] == NULL)
		{
			free_argv(&fake_argv);
			return (putstr_error("Error\n"));
		}
		range = main_check_input_and_fill_tab(fake_argv, tab);
		free_argv(&fake_argv);
	}
	else
	{
		range = main_check_input_and_fill_tab(argv + 1, tab);
	}
	if (range == -1)
	{
		return (-1);
	}
	return (range);
}

int	main_sort(t_stack *stack_a, t_stack	*stack_b, int range, int *lis_array)
{
	while (stack_is_sorted(stack_a) == 0)
	{
		if (range == 2)
			ra(stack_a);
		else if (range == 3)
			sort_three(stack_a);
		else
		{
			sort_stack(stack_a, stack_b, lis_array);
		}
	}
	return (0);
}

int	push_swap_with_lis(int print, int *tab, int range)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*lis_array;
	int		i;

	i = 0;
	init_stack(&stack_a, &stack_b, range);
	lis_array = find_lis(&stack_a, tab, range);
	fill_stack_from_array(&stack_a, tab, range);
	main_sort(&stack_a, &stack_b, range, lis_array);
	free(lis_array);
	while (i < stack_a.nb_moves && print == 1)
	{
		final_print(stack_a.moves[i]);
		i++;
	}
	range = stack_a.nb_moves;
	free_stack_final(&stack_a, &stack_b);
	return (range);
}

int	push_swap_without_lis(int print, int *tab, int range)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*lis_array;
	int		i;

	init_stack(&stack_a, &stack_b, range);
	lis_array = NULL;
	stack_a.size_lis = 0;
	fill_stack_from_array(&stack_a, tab, range);
	main_sort(&stack_a, &stack_b, range, lis_array);
	i = 0;
	while (i < stack_a.nb_moves && print == 1)
	{
		final_print(stack_a.moves[i]);
		i++;
	}
	range = stack_a.nb_moves;
	free_stack_final(&stack_a, &stack_b);
	return (range);
}

int	main(int argc, char **argv)
{
	int	res;
	int	range;
	int	*tab;
	int	res_bis;

	range = check_input_main(argv, argc, &tab);
	if (range == -1)
		return (-1);
	res = push_swap_with_lis(0, tab, range);
	if (res == -1)
		return (-1);
	res_bis = push_swap_without_lis(0, tab, range);
	if (res_bis == -1)
		return (-1);
	if (res > res_bis)
		push_swap_without_lis(1, tab, range);
	else
		push_swap_with_lis(1, tab, range);
	free_tab(&tab);
	return (0);
}
