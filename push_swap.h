#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <ctype.h>

typedef int (*t_validation_func)(const char *);
typedef int (*t_is_separator)(int);
typedef int (*t_filter_func)(int, int *, int);

typedef struct s_stack
{
  int *items;
  int *ideal_indexes;
  int current_size;
  int fixed_size;
  int top;
  int bottom;
  int threshold;
} t_stack;

//FILTER FUNCTIONS
int   is_num_repeated(int index, int *arr, int size);
int   *filter_(int *int_arr, int *len, t_filter_func filter);

//CORE VALIDATION
int   validate_and_get(char *arg, t_validation_func validate, int *valid_args);
int   *get_valid_args(int argc, char **argv, t_validation_func validate, int *valid_args_size);
int   is_valid_num(const char *str);

//CORE FUNCTIONS FOR PUSH_SWAP
//void  solve_stacks(t_stack *stack_a, t_stack *stack_b);
void  solve_stacks(t_stack *stack_a, t_stack *stack_b, int length);
int   fill_stack(t_stack *stack, int *valid_args, int valid_args_len);
int   fill_stacks(t_stack *stack_a, t_stack *stack_b, int *valid_args, int valid_args_len);

//STACK FUNCTIONS
int init_stack(t_stack *stack, int len);
int push(t_stack *stack, int value);
int push_back(t_stack *stack, int value);
int pop(t_stack *stack, int *value);
int pop_back(t_stack *stack, int *value);
int peek(t_stack *stack);

//STACK FUNCTION UTILS
void  copy_stack_items(int *dest, t_stack *stack);
int   resize_stack(t_stack *stack);
void  print_stack(t_stack stack);
void  swap_ideal_indexes(t_stack *stack, int index_1, int index_2);

//FT_SPLIT FUCNTIONS
int   calc_words(const char *s, t_is_separator is_separator);
char  *get_word(const char *s, t_is_separator is_separator);
char  **clean_matrix(char **matrix);
char  **split_on(const char *s, t_is_separator is_separator);

//INSTRUCTIONS
void  swap(t_stack *stack);
void  push_from(t_stack *dst_s, t_stack *src_s);
void  rotate(t_stack *stack);
void  rrotate(t_stack *stack);

//LIBFT_FUNCTIONS
int     ft_isalpha(int c);
int     ft_isdigit(int c);
int     count_nums(char *arg);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
long    ft_atoi(const char *str);

#endif
