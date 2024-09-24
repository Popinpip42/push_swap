#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# define MAX_SIZE 500

typedef struct s_stack
{
  int items[MAX_SIZE];
  int top;
} t_stack;
int get_args_len(int argc, char **argv);
int ft_isalpha(int c);
int ft_isdigit(int c);
int count_nums (char *arg);

int is_valid(char *str, t_stack *stack);
int add_numbers(t_stack *stack, char *str);
void  fill_stack(t_stack *stack, int stack_len, char **argv, int argc);

void  init(t_stack *stack);
int push(t_stack *stack, int value);
int pop(t_stack *stack);
int peek(t_stack *stack);
void  print_stack(t_stack *stack);

int calc_words(char const *s, char c);
char  *get_word(char const *s, char c);
char  **clean_matrix(char **matrix, int row);
char  **ft_split(char const *s, char c);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
long ft_atoi(const char *str);

#endif
