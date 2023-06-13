/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:15:52 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/13 20:18:02 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int d)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->d = d;
	new_stack->n = NULL;
	new_stack->p = NULL;
	return (new_stack);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->n != NULL)
		stack = stack->n;
	return (stack);
}

void	push(t_stack **stack, int d)
{
	t_stack	*tmp;

	if (!*stack)
		*stack = ft_stacknew(d);
	else
	{
		tmp = ft_stacknew(d);
		tmp->p = ft_stacklast(*stack);
		ft_stacklast(*stack)->n = tmp;
	}
}

void	push_init(t_stack **stack, int d)
{
	t_stack	*new_stack;

	new_stack = ft_stacknew(d);
	if (!new_stack)
		return ;
	new_stack->n = *stack;
	(*stack)->p = new_stack;
	*stack = new_stack;
}

int	pop(t_stack **stack)
{
	t_stack	*iter;
	t_stack	*temp;
	t_stack	*last;
	int		rvalue;

	if ((*stack)->n == NULL)
	{
		rvalue = (*stack)->d;
		free(*stack);
		*(stack) = NULL;
		return (rvalue);
	}
	iter = *stack;
	last = ft_stacklast(*stack);
	iter = last->p;
	rvalue = last->d;
	temp = last;
	iter->n = NULL;
	last->p = NULL;
	free(temp);
	return (rvalue);
}
