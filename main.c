/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:28:20 by asuc              #+#    #+#             */
/*   Updated: 2023/12/16 22:17:47 by asuc             ###   ########.fr       */
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

void	free_stack_final(t_stack *stack_a, t_stack	*stack_b, int **tab)
{
	free_tab(tab);
	free_stack(stack_a);
	free_stack(stack_b);
}


int	main(int argc, char **argv)
{
	int		range;
	int		*tab;
	t_stack	stack_a;
	t_stack	stack_b;

	init_stack(&stack_a);
	init_stack(&stack_b);
	// char *fake_argv[2] = {"fake argv", "16 202 315 56 102 305 18 277 98 497 3 473 188 85 482 31 344 425 249 247 171 183 440 90 371 460 452 437 350 379 335 268 279 215 294 499 433 120 222 129 428 481 432 494 273 373 422 316 278 466 69 254 122 45 431 453 465 4 450 488 410 286 348 91 420 331 7 228 395 283 409 28 107 125 456 200 164 65 48 168 289 443 490 355 23 227 449 272 399 477 276 429 418 119 424 496 237 194 413 367 22 403 374 179 411 205 267 68 324 297 366 19 243 442 140 25 77 169 427 491 101 87 478 280 131 439 299 118 358 383 408 458 469 192 61 137 455 421 99 388 180 337 480 314 126 251 241 149 14 253 144 162 334 81 306 177 301 303 385 393 49 246 309 287 153 464 341 88 34 12 362 238 36 75 401 53 382 444 114 10 117 38 72 100 359 83 476 447 475 255 165 151 150 342 479 310 457 446 115 415 111 390 322 364 471 43 79 263 313 256 1 109 338 213 434 389 380 17 57 326 214 296 187 319 206 336 189 262 300 148 39 230 166 423 35 142 291 26 419 46 248 70 323 134 329 96 204 492 92 29 152 304 176 467 156 44 232 174 318 60 37 173 308 104 266 307 190 396 295 172 356 386 493 66 145 363 360 398 196 470 82 317 209 224 357 381 8 486 210 136 116 71 130 343 400 184 113 135 468 498 430 157 500 24 197 448 445 182 242 51 5 20 320 345 138 438 185 387 198 186 451 416 244 372 472 95 485 261 340 293 220 167 199 392 64 6 441 41 330 47 110 250 378 484 327 259 312 141 426 86 270 391 170 346 370 217 80 347 257 298 203 94 97 325 50 226 265 407 52 93 404 127 397 132 339 302 352 351 84 139 459 54 405 406 195 105 89 474 212 462 112 59 154 27 260 258 211 487 483 417 394 282 239 333 63 365 193 124 133 402 461 21 40 377 233 376 361 240 489 158 436 11 208 103 201 288 78 9 62 155 384 369 161 121 108 128 73 375 106 321 58 264 207 225 13 15 42 33 328 353 219 269 354 218 55 159 160 435 229 368 32 143 221 495 414 178 463 74 349 234 216 290 30 412 281 181 223 245 275 163 284 274 191 235 175 146 123 231 2 454 236 76 311 67 292 285 252 271 147 332"};
	// argc = 2;
	// argv = fake_argv;
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
	stack_a.tab = NULL;
	stack_b.tab = NULL;
	int n = argc - 1;
	int *lis_array = find_lis(tab, n);
	int i = 0;
	while (i < n) {
		printf("%d ", lis_array[i]);
		i++;
	}
	return (0);
	fill_stack_from_array(&stack_a, tab, range);
	while (stack_is_sorted(&stack_a) == 0)
	{
		if (range == 2)
			ra(&stack_a);
		else if (range == 3)
			sort_three(&stack_a);
		else
		{
			sort_stack(&stack_a, &stack_b, range);
		}
	}
	if (argc == 2)
		free_argv(&argv);
	free_stack_final(&stack_a, &stack_b, &tab);
	return (0);
}
