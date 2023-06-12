/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:15:52 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/11 19:39:14 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int data)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->data = data;
	new_stack->next = NULL;
	new_stack->prev = NULL;
	return (new_stack);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	push(t_stack **stack, int data)
{
	t_stack	*tmp;

	if (!*stack)
		*stack = ft_stacknew(data);
	else
	{
		tmp = ft_stacknew(data);
		tmp->prev = ft_stacklast(*stack);
		ft_stacklast(*stack)->next = tmp;
	}
}

void	push_init(t_stack **stack, int data)
{
	t_stack	*new_stack;

	new_stack = ft_stacknew(data);
	if (!new_stack)
		return ;
	new_stack->next = *stack;
	(*stack)->prev = new_stack;
	*stack = new_stack;
}

int	pop(t_stack **stack)
{
	t_stack	*iter;
	t_stack	*temp;
	t_stack	*last;
	int		rvalue;

	if ((*stack)->next == NULL)
	{
		rvalue = (*stack)->data;
		free(*stack);
		*(stack) = NULL;
		return (rvalue);
	}
	iter = *stack;
	last = ft_stacklast(*stack);
	iter = last->prev;
	rvalue = last->data;
	temp = last;
	iter->next = NULL;
	last->prev = NULL;
	free(temp);
	return (rvalue);
}
