#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_stack
{
  int *items;
  //int *ideal_indexe
  int current_size;
  int fixed_size;
  int top;
  int bottom;
  int threshold;
} t_stack;

//CORE FUNCTIONS FOR PUSH_SWAP
void  solve_stacks(t_stack *stack_a, t_stack *stack_b);
int add_numbers(t_stack *stack, char *str);
int  fill_stack(t_stack *stack, int stack_len, char **argv, int argc);
int is_valid(char *str, t_stack *stack);

//STACK FUNCTIONS
int init_stack(t_stack *stack, int len);
int push(t_stack *stack, int value);
int push_back(t_stack *stack, int value);
int pop(t_stack *stack, int *value);
int pop_back(t_stack *stack, int *value);
int peek(t_stack *stack);
//STACK FUNCTION UTILS
void  copy_stack_items(int *dest, t_stack *stack);
int resize_stack(t_stack *stack);
void print_stack(t_stack stack);

//FT_SPLIT FUCNTIONS
int calc_words(char const *s, char c);
char  *get_word(char const *s, char c);
char  **clean_matrix(char **matrix, int row);
char  **ft_split(char const *s, char c);

//INSTRUCTIONS
void  swap(t_stack *stack);
void  push_from(t_stack *dst_s, t_stack *src_s);
void  rotate(t_stack *stack);
void  rrotate(t_stack *stack);

//LIBFT_FUNCTIONS
int get_args_len(int argc, char **argv);
int ft_isalpha(int c);
int ft_isdigit(int c);
int count_nums (char *arg);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
long ft_atoi(const char *str);

#endif
