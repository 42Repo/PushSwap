/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:28:20 by asuc              #+#    #+#             */
/*   Updated: 2023/12/19 22:31:12 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->top != NULL)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
}

void	free_tab(int **tab)
{
	free(*tab);
	*tab = NULL;
}

void	free_argv(char ***argv)
{
	int	i;

	i = 0;
	while ((*argv)[i] != NULL)
	{
		free((*argv)[i]);
		i++;
	}
	free(*argv);
	*argv = NULL;
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
}

void	free_stack_final(t_stack *stack_a, t_stack *stack_b, int **tab)
{
	free(stack_a->moves);
	free_tab(tab);
	free_stack(stack_a);
	free_stack(stack_b);
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

char **ft_join_argv(char **fake_argv, char **argv, int argc)
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

int	main2(int argc, char **argv, int print)
{
	int		range;
	int		*tab;
	t_stack	stack_a;
	t_stack	stack_b;
	int		*lis_array;
	int		n;
	int		i;
	char 	**fake_argv;

	init_stack(&stack_a);
	init_stack(&stack_b);
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
		range = main_check_input_and_fill_tab(fake_argv, &tab);
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
		range = main_check_input_and_fill_tab(fake_argv, &tab);
		free_argv(&fake_argv);
	}
	else
	{
		range = main_check_input_and_fill_tab(argv + 1, &tab);
	}
	if (range == -1)
	{
		return (-1);
	}
	stack_a.range = range;
	stack_b.range = 0;
	stack_a.median = stack_a.range / 2;
	stack_b.median = stack_b.range / 2;
	stack_a.nb_moves = 0;
	stack_a.moves = ft_calloc(sizeof(enum e_instru), (range * range));
	n = range;
	lis_array = find_lis(&stack_a, tab, n);
	fill_stack_from_array(&stack_a, tab, range);
	while (stack_is_sorted(&stack_a) == 0)
	{
		if (range == 2)
			ra(&stack_a);
		else if (range == 3)
			sort_three(&stack_a);
		else
		{
			sort_stack(&stack_a, &stack_b, range, lis_array);
		}
	}
	free(lis_array);
	i = 0;
	while (i < stack_a.nb_moves && print == 1)
	{
		final_print(stack_a.moves[i]);
		i++;
	}
	n = stack_a.nb_moves;
	free_stack_final(&stack_a, &stack_b, &tab);
	return (n);
}

int	main3(int argc, char **argv, int print)
{
	int		range;
	int		*tab;
	t_stack	stack_a;
	t_stack	stack_b;
	int		*lis_array;
	int		n;
	int		i;

	init_stack(&stack_a);
	init_stack(&stack_b);
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		range = main_check_input_and_fill_tab(argv, &tab);
	}
	else
		range = main_check_input_and_fill_tab(argv + 1, &tab);
	if (range == -1)
	{
		if (argc == 2)
			free_argv(&argv);
		return (-1);
	}
	stack_a.range = range;
	stack_b.range = 0;
	stack_a.median = stack_a.range / 2;
	stack_b.median = stack_b.range / 2;
	stack_a.nb_moves = 0;
	stack_a.moves = ft_calloc(sizeof(enum e_instru), (range * range));
	n = range;
	lis_array = find_lis(&stack_a, tab, n);
	stack_a.size_lis = 0;
	fill_stack_from_array(&stack_a, tab, range);
	while (stack_is_sorted(&stack_a) == 0)
	{
		if (range == 2)
			ra(&stack_a);
		else if (range == 3)
			sort_three(&stack_a);
		else
		{
			sort_stack(&stack_a, &stack_b, range, lis_array);
		}
	}
	free(lis_array);
	if (argc == 2)
		free_argv(&argv);
	i = 0;
	while (i < stack_a.nb_moves && print == 1)
	{
		final_print(stack_a.moves[i]);
		i++;
	}
	n = stack_a.nb_moves;
	free_stack_final(&stack_a, &stack_b, &tab);
	return (n);
}

int	main(int argc, char **argv)
{
	int	res;
	int	res_bis;

	res = main2(argc, argv, 1);
	if (res == -1)
		return (-1);
	return (0);
	res_bis = main3(argc, argv, 0);
	if (res_bis == -1)
		return (-1);
	if (res > res_bis)
		main3(argc, argv, 1);
	else
		main2(argc, argv, 1);
	return (0);
}
