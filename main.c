/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:36:26 by asuc              #+#    #+#             */
/*   Updated: 2023/11/13 19:08:28 by asuc             ###   ########.fr       */
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
	(void)argv;
	int nombres[100];
	int nombre = 0;
	int i = 0;
	srand(time(NULL));
	while (i < 100) {
		nombre = rand() % 101; // Génère un nombre entre 0 et 100

		if (nombreEstUnique(nombres, i, nombre)) {
			nombres[i] = nombre;
			i++;
		}
	}
	i = 0;
	push_swap(nombres);
	return	(0);
}

