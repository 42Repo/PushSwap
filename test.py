# on veut transfomer les string de type = "4 654 1 654 46544656534 324654" en "4, 654, 1, 654, 46544656534, 324654" et l'ecrire

# Définir la chaîne de nombres d'entrée
input_string = "16 202 315 56 102 305 18 277 98 497 3 473 188 85 482 31 344 425 249 247 171 183 440 90 371 460 452 437 350 379 335 268 279 215 294 499 433 120 222 129 428 481 432 494 273 373 422 316 278 466 69 254 122 45 431 453 465 4 450 488 410 286 348 91 420 331 7 228 395 283 409 28 107 125 456 200 164 65 48 168 289 443 490 355 23 227 449 272 399 477 276 429 418 119 424 496 237 194 413 367 22 403 374 179 411 205 267 68 324 297 366 19 243 442 140 25 77 169 427 491 101 87 478 280 131 439 299 118 358 383 408 458 469 192 61 137 455 421 99 388 180 337 480 314 126 251 241 149 14 253 144 162 334 81 306 177 301 303 385 393 49 246 309 287 153 464 341 88 34 12 362 238 36 75 401 53 382 444 114 10 117"

# Diviser la chaîne en une liste de nombres
numbers = input_string.split()

# Joindre les nombres avec des virgules
output_string = ", ".join(numbers)

# Afficher la chaîne de sortie
print(output_string)

# Écrire la chaîne de sortie dans un fichier
# with open("output.txt", "w") as file:
# 	file.write(output_string)
