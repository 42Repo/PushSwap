/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_lis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:46:56 by asuc              #+#    #+#             */
/*   Updated: 2023/12/16 22:16:40 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void update_lis(int *arr, int *lis, int *prev, int n, int i, int j) {
    if (i < n) {
        if (j < i) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prev[i] = j;
            }
            update_lis(arr, lis, prev, n, i, j + 1);
        } else {
            update_lis(arr, lis, prev, n, i + 1, 0);
        }
    }
}

void construct_lis(int *arr, int *prev, int *result, int idx, int size, int *pos) {
    if (prev[idx] != -1) {
        construct_lis(arr, prev, result, prev[idx], size, pos);
    }
    result[*pos] = arr[idx];
    (*pos)++;
}

int *find_lis(int *arr, int n) {
    int *lis = (int *)malloc(n * sizeof(int));
    int *prev = (int *)malloc(n * sizeof(int));
    int *result;
    int i, max_lis = 0, max_idx = 0, pos = 0;

    if (!lis || !prev) return NULL; // Error handling for malloc

    for (i = 0; i < n; i++) {
        lis[i] = 1;
        prev[i] = -1;
    }

    update_lis(arr, lis, prev, n, 1, 0);

    for (i = 0; i < n; i++) {
        if (max_lis < lis[i]) {
            max_lis = lis[i];
            max_idx = i;
        }
    }

    result = (int *)malloc(max_lis * sizeof(int));
    if (!result) return NULL; // Error handling for malloc

    construct_lis(arr, prev, result, max_idx, max_lis, &pos);
    free(lis);
    free(prev);
    return result;
}

