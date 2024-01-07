/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:28:52 by asuc              #+#    #+#             */
/*   Updated: 2024/01/07 22:23:50 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

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

void	free_stack_final(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->moves);
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

int	parse_instru(char *line, t_stack *stack_a)
{
	if (ft_strlen(line) == 3 && ft_strncmp(line, "sa", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_sa;
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "sb", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_sb;
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "ss", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_ss;
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "pa", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_pa;
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "pb", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_pb;
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "ra", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_ra;
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "rb", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_rb;
	else if (ft_strlen(line) == 4 && ft_strncmp(line, "rra", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_rra;
	else if (ft_strlen(line) == 4 && ft_strncmp(line, "rrb", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_rrb;
	else if (ft_strlen(line) == 4 && ft_strncmp(line, "rrr", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_rrr;
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "rr", ft_strlen(line) - 1) == 0)
		stack_a->moves[stack_a->nb_moves++] = i_rr;
	else
		return (-1);
	return (0);
}

void	make_moves(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < stack_a->nb_moves)
	{
		if (stack_a->moves[i] == i_sa)
			sa(stack_a);
		else if (stack_a->moves[i] == i_sb)
			sb(stack_b);
		else if (stack_a->moves[i] == i_ss)
			ss(stack_a, stack_b);
		else if (stack_a->moves[i] == i_pa)
			pa(stack_a, stack_b);
		else if (stack_a->moves[i] == i_pb)
			pb(stack_a, stack_b);
		else if (stack_a->moves[i] == i_ra)
			ra(stack_a);
		else if (stack_a->moves[i] == i_rb)
			rb(stack_b);
		else if (stack_a->moves[i] == i_rr)
			rr(stack_a, stack_b);
		else if (stack_a->moves[i] == i_rra)
			rra(stack_a);
		else if (stack_a->moves[i] == i_rrb)
			rrb(stack_b);
		else if (stack_a->moves[i] == i_rrr)
			rrr(stack_a, stack_b);
		i++;
	}
}

int	checker(int *tab, int range)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*line;

	init_stack(&stack_a, &stack_b, range);
	fill_stack_from_array(&stack_a, tab, range);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (parse_instru(line, &stack_a) == -1)
			return (putstr_error("Error\n"));
		free(line);
		line = get_next_line(0);
		if (line != NULL && line[ft_strlen(line) - 1] != '\n')
		{
			free_stack_final(&stack_a, &stack_b);
			return (putstr_error("Error\n"));
		}
	}
	make_moves(&stack_a, &stack_b);
	if (stack_is_sorted(&stack_a) == 1 && stack_b.top == NULL)
		ft_printf("OK\n");
	else
	{
		ft_printf("KO\n");
	}
	free_stack_final(&stack_a, &stack_b);
	return (range);
}

int	main(int argc, char **argv)
{
	int	res;
	int	range;
	int	*tab;

	if (argc < 2)
		return (0);
	range = check_input_main(argv, argc, &tab);
	if (range == -1)
		return (-1);
	res = checker(tab, range);
	if (res == -1)
		return (-1);
	free_tab(&tab);
	return (0);
}
