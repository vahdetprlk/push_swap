/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:55:11 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/04 17:32:57 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../include/libft/libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

char	**add_to_list(int argc, char **argv);

int		is_int_item(char *item);
int		is_int_list(char **list);
int		is_duplicate(char **list);
int		pop(t_stack **stack);
int		is_sorted(t_stack **stack);
int		find_min(t_stack **stack);
int		find_middle(t_stack **stack);

t_stack	*ft_stacknew(int data);
t_stack	*ft_stacklast(t_stack *stack);

size_t	ft_stacksize(t_stack *stack);

void	init_stack_a(t_stack **a, char **list);
void	error_case(char *msg, int status);
void	print_stack(t_stack *stack);
void	push(t_stack **stack, int data);
void	push_init(t_stack **stack, int data);
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
void	sort_three(t_stack **stack);
void	sort(t_stack **a, t_stack **b);
void	divide(t_stack **a, t_stack **b);
void	pre_divide(t_stack **a, int pivot);

#endif
