/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:55:11 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/14 21:14:01 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./../include/libft/libft.h"
# include "./../include/ft_printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_stack
{
	int				d;
	struct s_stack	*p;
	struct s_stack	*n;
}					t_stack;

char	**add_to_list(int argc, char **argv);

char	*get_next_line(int fd);

int		is_int_item(char *item);
int		is_int_list(char **list);
int		is_duplicate(char **list);
int		pop(t_stack **stack);
int		is_sorted(t_stack **stack, char flag, int len);
int		find_min(t_stack **stack);
int		sort_a(t_stack **a, t_stack **b, int len, int count);
int		sort_b(t_stack **b, t_stack **a, int len, int count);
int		find_middle(int *pivot, t_stack **stack_a, int len);

t_stack	*ft_stacknew(int d);
t_stack	*ft_stacklast(t_stack *stack);

size_t	ft_stacksize(t_stack *stack);

void	check_arguments(char **str_list);
void	init_stack_a(t_stack **a, char **list);
void	error_case(char *msg, int status);
void	print_stack(t_stack *stack);
void	push(t_stack **stack, int d);
void	push_init(t_stack **stack, int d);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	swap_top(t_stack **stack);
void	pa(t_stack **a, t_stack**b);
void	pb(t_stack **a, t_stack**b);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rotate_reverse(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sort_three_a(t_stack **a, t_stack **b, int len);
void	sort_three_a_i(t_stack **a, t_stack **b, int len);
void	sort_small_b_i(t_stack **b, t_stack **a, int len);
void	sort_three_first(t_stack **stack, char flag);
void	sort_small_b(t_stack **b, t_stack **a, int len);
void	ft_sort(t_stack **a, t_stack **b, int len);
void	ft_sort_int_tmp(int *tmp_stack, int size);
void	free_stacks(t_stack **stack_a, t_stack **stack_b);

#endif
