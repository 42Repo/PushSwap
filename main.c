/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:36:26 by asuc              #+#    #+#             */
/*   Updated: 2023/12/10 00:54:19 by asuc             ###   ########.fr       */
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
	// char *fake_argv[2] = {"fake argv", "35 315 362 436 484 8 256 480 63 222 491 450 176 52 401 130 230 94 76 117 97 270 4 50 184 399 146 386 411 111 88 212 388 393 487 316 250 15 417 408 283 392 170 420 122 419 426 23 302 341 263 354 163 476 62 186 38 309 479 447 80 423 85 287 211 235 413 292 499 421 192 257 342 101 217 225 406 26 231 161 295 304 441 119 58 349 328 472 142 180 103 31 374 317 200 193 277 162 278 191 169 368 333 9 242 246 253 261 371 150 357 425 2 299 179 300 59 477 96 339 356 301 248 46 330 224 51 126 136 493 469 337 437 324 497 86 214 40 37 140 402 181 325 269 201 379 260 198 481 116 350 329 145 13 233 323 25 243 454 486 285 113 276 36 433 72 215 204 463 206 148 188 208 439 490 446 327 167 252 196 266 114 104 380 75 84 3 120 107 17 129 422 152 473 223 410 294 359 100 131 160 378 360 318 418 71 5 351 245 185 41 77 175 127 157 272 124 118 218 190 438 489 110 467 452 54 153 135 91 448 383 108 247 28 164 14 70 64 244 232 78 229 216 213 498 471 264 414 73 30 10 475 430 390 488 16 407 158 82 109 297 115 66 6 279 105 125 307 32 254 151 259 465 338 90 220 432 57 404 67 449 149 182 396 377 445 424 375 98 187 29 195 262 12 241 165 207 326 141 298 203 384 74 68 385 365 345 412 92 156 320 464 48 45 461 314 143 429 409 133 400 47 495 83 121 397 171 65 311 347 139 87 444 159 271 500 238 398 415 132 106 343 239 431 284 251 177 249 344 321 282 474 458 49 95 455 240 460 451 1 39 69 138 219 457 427 352 280 334 376 236 293 394 440 227 485 428 478 290 355 331 482 468 395 194 209 466 189 174 33 79 361 367 89 144 470 56 44 403 459 335 205 381 183 286 155 134 310 60 288 11 366 405 443 228 332 340 416 137 18 123 42 234 61 55 7 456 313 305 308 319 273 21 372 363 382 291 442 237 172 494 453 173 303 364 358 22 128 81 370 296 391 154 258 373 312 369 102 221 483 99 197 322 267 268 306 20 199 210 19 275 346 348 93 53 265 336 389 274 435 226 289 462 353 166 202 24 27 147 434 496 34 387 255 43 168 492 281 178 112"};
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
