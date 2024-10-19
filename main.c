#include "push_swap.h"

void  clean_stack(t_stack *stack)
{
  if (stack)
  {
    if (stack->items)
      free(stack->items);
    if (stack->ideal_indexes)
      free(stack->ideal_indexes);
  }
}

void clean_all(t_stack *stack1, t_stack *stack2)
{
  clean_stack(stack1);
  clean_stack(stack2);
}

int main(int argc, char **argv)
{
  t_stack stack_a;
  t_stack stack_b;
  int     valid_args_len;
  int     *valid_args;

  if (argc < 3)
    exit(EXIT_FAILURE);

  //TODO: could pass transformation function, in this case (ft_atoi()). or (strdup())
  valid_args = get_valid_args(argc, argv, &is_valid_num, &valid_args_len);
  printf("\n==== Arguments Size : %i \n", argc - 1);
  printf("==== Numbers counted, valid ones, from argv : %i\n", valid_args_len);
  valid_args = filter_(valid_args, &valid_args_len, &is_num_repeated);
  printf("==== Numbers counted, filtered ones, from argv : %i\n", valid_args_len);

  if (!valid_args)
  {
    printf("Error getting valids_args vector\n");
    if (valid_args_len == 0 || valid_args_len == 1)
      printf("Not enought valid arguments or only 1 element\n");
    exit(EXIT_FAILURE);
  }

  if (!init_stack(&stack_a, valid_args_len) || !init_stack(&stack_b, valid_args_len))
  {
    clean_all(&stack_a, &stack_b);
    printf("Error: initializing stack a\n");
    exit(EXIT_FAILURE);
  }
  printf("\n==== Prepararing stacks function \n");
  if ((fill_stacks(&stack_a, &stack_b, valid_args, valid_args_len)) == -1)
  {
    clean_all(&stack_a, &stack_b);
    printf("Error\n");
    exit(EXIT_FAILURE);
  }
  printf("\n==== Stack_a size after fill %d\n", stack_a.current_size);
  printf("==== Stack_b size after fill %d\n", stack_b.current_size);

  //TODO: Only first part of the algorithm implemented
  solve_stacks(&stack_a, &stack_b, valid_args_len);

  printf("\n stack_a size : %d\n", stack_a.current_size);
  printf("==== Printing stacks_a from main call \n");
  print_stack(stack_a);
  printf("stack_b size : %d\n", stack_b.current_size);
  printf("==== Printing stacks_b from main call \n");
  print_stack(stack_b);

  printf("==== Printing stacks_a ideal_indexes from main call \n");
  for (int a = 0; a < stack_a.current_size; a++)
    printf("Ideal_Index_stack_a Item[%d] - %d\n", a+1, stack_a.ideal_indexes[a]);

  clean_all(&stack_a, &stack_b);
  return (0);
}
//TODO: Simple compilation w/o Makefile 26/Sept/2024
// gcc -fsanitize=address -g main.c get_valid_args.c fill_stack.c stack_methods.c split_on.c n_atoi.c solve_stacks.c stack_methods_utils.c stack_instructions.c str_functions.c filter_functions.c

//TODO: Tested with
//1 - ./a.out "aefa" asdfa 11 22a12 "2223 123a1 asdf 33 aa" "adf- as 44" " " "adsfadzxc_ asfd _ 55 a " 55
//  - Expect : items 1 - 11, items 2 - 2223, items 3 - 33, items 4 - 44, items 5 - 55
//2 - ./a.out "2147483647" 2147483648 "--+-2147483648" -2147483649
//  - Expect : items 1 - 2147483647, items 2 - -2147483648
//3 - ./a.out 259 125 325 83 343 446 295 275 135 483 268 248 462 71 156 441 97 89 139 66 376 287 120 19 330 185 421 331 270 375 312 117 138 233 243 36 278 46 435 427 341 178 380 364 116 225 64 14 170 151 29 345 344 372 302 105 301 167 361 422 467 186 204 315 490 261 386 257 41 393 397 129 431 470 33 394 340 84 169 373 205 303 152 226 447 326 389 471 453 284 280 242 442 355 8 24 228 293 258 407 182 175 194 497 23 360 250 31 374 436 439 354 145 367 171 106 48 109 433 464 319 269 494 121 434 246 255 196 57 253 308 334 238 488 402 491 126 190 472 141 413 104 119 410 96 94 206 285 342 420 172 299 369 142 103 63 86 392 387 391 227 486 148 485 457 449 424 267 448 266 239 404 456 20 128 294 187 272 107 21 291 108 382 76 477 358 208 95 296 377 90 245 309 203 184 495 398 13 403 183 200 195 22 417 232 140 406 332 329 37 237 314 390 333 136 438 173 82 362 144 466 58 306 118 199 474 213 1 12 383 131 60 311 252 450 159 68 357 265 351 346 444 16 112 78 460 262 500 459 212 155 162 290 209 359 54 263 81 177 215 379 454 418 157 74 43 75 498 401 6 219 197 271 62 318 110 229 349 77 73 124 214 352 279 34 80 123 416 160 59 499 52 88 3 9 321 484 452 154 286 264 328 305 445 27 327 251 277 51 39 0 475 101 300 411 247 222 161 220 137 310 99 289 98 56 17 26 399 489 335 463 322 415 207 176 313 493 165 166 221 365 85 451 211 276 127 297 400 223 396 25 69 338 18 347 42 478 273 45 260 163 419 323 423 425 180 168 317 115 432 193 350 368 179 133 437 87 405 496 274 79 218 30 288 61 240 414 235 395 149 5 412 189 201 202 143 198 363 164 292 337 15 254 11 298 384 174 307 231 102 348 216 378 224 388 487 111 113 316 147 244 150 409 158 130 458 188 426 492 134 428 191 44 468 461 339 283 50 91 455 429 371 256 67 65 385 304 281 236 72 320 35 324 482 230 70 465 366 28 55 132 249 440 217 381 10 49 100 476 47 181 146 443 153 408 210 481 93 32 122 430 353 473 234 2 370 479 192 241 480 7 469 356 38 92 53 336 40 114 282
//  - Expect : 500items, 500 items, 500 filtered items.
//          - Add one extra repeated number in this test
//4 - ./a.out 333 368 485 417 351 369 412 354 295 383 127 29 61 461 74 237 266 222 82 341 9 28 44 334 189 411 357 98 346 385 207 355 441 247 18 7 480 401 198 217 3 194 73 118 339 68 364 248 145 166 394 136 94 186 451 124 34 426 254 15 108 38 273 430 304 202 463 391 30 493 287 375 42 442 407 60 449 390 20 210 289 458 123 335 196 459 143 106 410 23 213 25 31 456 16 195 239 21 93 96

//TODO: TEST CODE FOR MOVING IDEAL INDEXES ALONG INSTRUCTIONS
  /*
  printf("\n==== Trying moving ideal_indexes on each instruction\n");
  swap(&stack_a);
  rotate(&stack_a);
  rrotate(&stack_a);
  push_from(&stack_b, &stack_a);

  printf("==== Printing stacks_a from main call \n");
  print_stack(stack_a);
  printf("==== Printing stacks_a ideal_indexes from main call \n");
  for (int a = 0; a < stack_a.current_size; a++)
    printf("Ideal_Index_stack_a Item[%d] - %d\n", a+1, stack_a.ideal_indexes[a]);

  printf("==== Printing stacks_b from main call \n");
  print_stack(stack_b);
  printf("==== Printing stacks_b ideal_indexes from main call \n");
  for (int b = 0; b < stack_b.current_size; b++)
    printf("Ideal_Index_stack_b Item[%d] - %d\n", b+1, stack_b.ideal_indexes[b]);
  */

//TODO: TEST CODE FOR RESIZING
  /*
  printf("\nTRYING IF RESIZING WORKS OUT\n");
  int i = 0;
  int num = 100;
  while (i < num / 2)
  {
    if (i < (num / 2) / 2)
      push_back(stack_a, i);
    else {
      push(stack_a, i);
    }
    i++;
  }
  */

//TODO: TEST CODE FOR POP FUNCTIONS
  /*
  printf("Trying pop function\n");
  int value;
  while (stack_a->current_size > 0)
  {
    pop_back(stack_a, &value);
    printf("Popped -> %d\n", value);
  }
  */

//TODO: TEST CODE FOR INSTRUCTIONS
  /*
  printf("Trying instructions based on push_swap PDF\n");
  printf("--- SA\n");
  swap(stack_a);
  print_stacks(stack_a, stack_b);
  printf("--- PB PB PB\n");
  push_from(stack_b, stack_a);
  push_from(stack_b, stack_a);
  push_from(stack_b, stack_a);
  print_stacks(stack_a, stack_b);
  printf("--- RA RB\n");
  rotate(stack_a);
  rotate(stack_b);
  print_stacks(stack_a, stack_b);
  printf("--- RRA RRB\n");
  rrotate(stack_a);
  rrotate(stack_b);
  print_stacks(stack_a, stack_b);
  printf("--- SA\n");
  swap(stack_a);
  print_stacks(stack_a, stack_b);
  printf("--- PA PA PA\n");
  push_from(stack_a, stack_b);
  push_from(stack_a, stack_b);
  push_from(stack_a, stack_b);
  print_stacks(stack_a, stack_b);
  */

