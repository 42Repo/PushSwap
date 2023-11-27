/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:36:26 by asuc              #+#    #+#             */
/*   Updated: 2023/11/27 22:04:38 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include "ft_push_swap.h"

int nombreEstUnique(int tableau[], int longueur, int nombre) {
	for (int i = 0; i < longueur; i++) {
		if (tableau[i] == nombre) {
			return 0; // Le nombre n'est pas unique
		}
	}
	return 1; // Le nombre est unique
}

int main(int argc, char **argv)
{
	(void)argc;
	int nombres[100];
	int nombre = 0;
	int i = 0;
	int range;
	int *tab;
	t_stack stack_a;
	t_stack stack_b;
	(void)stack_b;
	srand(time(NULL));
	while (i < 100) {
		nombre = rand() % 101; // Génère un nombre entre 0 et 100

		if (nombreEstUnique(nombres, i, nombre)) {
			nombres[i] = nombre;
			i++;
		}
	}
	i = 0;
	if (argc < 2)
		return (0);
	range = main_check_input_and_fill_tab(argv + 1, &tab);
	if (range == -1)
		return (-1);
	fill_stack_from_array(&stack_a, tab, range);
	while (i < range)
	{
		ft_printf("%d\n", stack_a.top->content);
		stack_a.top = stack_a.top->next;
		i++;
	}
	return (0);
}

