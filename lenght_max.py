def longest_increasing_subsequence(seq):
    if not seq:
        return []

    # Initialisation d'une liste pour stocker la longueur de la plus longue sous-séquence jusqu'à chaque élément
    lis = [1] * len(seq)
    for i in range(1, len(seq)):
        for j in range(i):
            if seq[i] > seq[j] and lis[i] < lis[j] + 1:
                lis[i] = lis[j] + 1

    # Trouver l'indice de la plus longue sous-séquence
    max_index = max(range(len(lis)), key=lis.__getitem__)
    max_lis = lis[max_index]
    print("La taille de la plus longue sous-séquence est :", lis[max_index])

    # Reconstruire la plus longue sous-séquence
    longest_seq = []
    for i in range(max_index, -1, -1):
        if lis[i] == max_lis:
            longest_seq.append(seq[i])
            max_lis -= 1

    return longest_seq[::-1]

# Conversion de la chaîne en liste de nombres
numbers = list(map(int, "16 202 315 56 102 305 18 277 98 497 3 473 188 85 482 31 344 425 249 247 171 183 440 90 371 460 452 437 350 379 335 268 279 215 294 499 433 120 222 129 428 481 432 494 273 373 422 316 278 466 69 254 122 45 431 453 465 4 450 488 410 286 348 91 420 331 7 228 395 283 409 28 107 125 456 200 164 65 48 168 289 443 490 355 23 227 449 272 399 477 276 429 418 119 424 496 237 194 413 367 22 403 374 179 411 205 267 68 324 297 366 19 243 442 140 25 77 169 427 491 101 87 478 280 131 439 299 118 358 383 408 458 469 192 61 137 455 421 99 388 180 337 480 314 126 251 241 149 14 253 144 162 334 81 306 177 301 303 385 393 49 246 309 287 153 464 341 88 34 12 362 238 36 75 401 53 382 444 114 10 117 38 72 100 359 83 476 447 475 255 165 151 150 342 479 310 457 446 115 415 111 390 322 364 471 43 79 263 313 256 1 109 338 213 434 389 380 17 57 326 214 296 187 319 206 336 189 262 300 148 39 230 166 423 35 142 291 26 419 46 248 70 323 134 329 96 204 492 92 29 152 304 176 467 156 44 232 174 318 60 37 173 308 104 266 307 190 396 295 172 356 386 493 66 145 363 360 398 196 470 82 317 209 224 357 381 8 486 210 136 116 71 130 343 400 184 113 135 468 498 430 157 500 24 197 448 445 182 242 51 5 20 320 345 138 438 185 387 198 186 451 416 244 372 472 95 485 261 340 293 220 167 199 392 64 6 441 41 330 47 110 250 378 484 327 259 312 141 426 86 270 391 170 346 370 217 80 347 257 298 203 94 97 325 50 226 265 407 52 93 404 127 397 132 339 302 352 351 84 139 459 54 405 406 195 105 89 474 212 462 112 59 154 27 260 258 211 487 483 417 394 282 239 333 63 365 193 124 133 402 461 21 40 377 233 376 361 240 489 158 436 11 208 103 201 288 78 9 62 155 384 369 161 121 108 128 73 375 106 321 58 264 207 225 13 15 42 33 328 353 219 269 354 218 55 159 160 435 229 368 32 143 221 495 414 178 463 74 349 234 216 290 30 412 281 181 223 245 275 163 284 274 191 235 175 146 123 231 2 454 236 76 311 67 292 285 252 271 147 332".split()))

# Trouver et afficher la plus longue séquence croissante
longest_sequence = longest_increasing_subsequence(numbers)
print("La plus longue séquence croissante est :", longest_sequence)
# on print la taille de la plus longue séquence croissante
print("La taille de la plus longue séquence croissante est :", len(longest_sequence))
