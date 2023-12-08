/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:36:26 by asuc              #+#    #+#             */
/*   Updated: 2023/12/08 23:48:19 by asuc             ###   ########.fr       */
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

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
}
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>

	#define SIZE 10 // Nombre de chiffres à générer

int	main(int argc, char **argv)
{
	// int		i;
	int		range;
	int		*tab;
	t_stack	stack_a;
	t_stack	stack_b;
	// TEST
	(void)argv;
	// char *fake_argv[SIZE + 1];
	// // on met 10 chiffres aleatoire dans argv
	// srand(time(NULL)); // Initialisation de la graine pour la génération aléatoire

	// for (int i = 0; i < SIZE; i++) {
	// 	int random_num = rand() % 100; // Génère un nombre aléatoire entre 0 et 99
	// 	char *num_str = malloc(3 * sizeof(char)); // Alloue de la mémoire pour stocker le nombre en tant que chaîne de caractères
	// 	sprintf(num_str, "%d", random_num); // Convertit le nombre en chaîne de caractères
	// 	fake_argv[i] = num_str; // Stocke la chaîne de caractères dans fake_argv
	// }
	// fake_argv[SIZE] = NULL; // On termine fake_argv avec un pointeur NULL

	// // on affiche tous les nombres de argv
	// for (int i = 0; i < SIZE; i++) {
	// 	printf("%s\n", argv[i]);
	// }
	// // TEST
	// char *fake_argv[11] = {"60", "71", "80", "14", "33" , "51", "77" , "36" , "4", "87",NULL};
	// on affiche argv
	// int i = 0;
	// while (argv[i])
	// {
	// 	ft_printf("%s\n", argv[i]);
	// 	i++;
	// }

	init_stack(&stack_a);
	init_stack(&stack_b);
	// i = 0;
	//  argc = 11;
	if (argc < 2)
		return (0);
	range = main_check_input_and_fill_tab(argv + 1, &tab);
	if (range == -1)
		return (-1);
	stack_a.range = range;
	stack_b.range = 0;
	stack_a.median = stack_a.range / 2;
	stack_b.median = stack_b.range / 2;
	fill_stack_from_array(&stack_a, tab, range);

	while (stack_is_sorted(&stack_a) == 0)
	{
		if (range == 2)
			swap(&stack_a);
		else if (range == 3)
			sort_three(&stack_a);
		else
			sort_stack(&stack_a, &stack_b, range);
	}
	// TEST
	// t_node *tmp = stack_a.top;
	// while (i < range)
	// {
	// 	ft_printf("%d\n", stack_a.top->content);
	// 	stack_a.top = stack_a.top->next;
	// 	i++;
	// }
	// stack_a.top = tmp;
	// TEST
	free_tab(&tab);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
