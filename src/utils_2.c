/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:15:52 by vparlak           #+#    #+#             */
/*   Updated: 2023/05/11 14:23:28 by vparlak          ###   ########.fr       */
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

void	push(t_stack *stack, int data)
{
	if (!stack)
		stack = ft_stacknew(data);
	else
		ft_stacklast(stack)->next = ft_stacknew(data);
}

int	pop(t_stack *stack)
{
	t_stack	*iter;
	t_stack	*temp;
	int		rvalue;

	if (stack->next == NULL)
	{
		rvalue = stack->data;
		free(stack);
		return (rvalue);
	}
	iter = stack;
	while (iter->next->next != NULL)
		iter = iter->next;
	rvalue = iter->next->data;
	temp = iter->next;
	iter->next = NULL;
	free(temp);
	return (rvalue);
}

t_stack	*init_stack_a(t_stack *stack_a, char **list)
{
	int	i;

	i = 1;
	stack_a = ft_stacknew(ft_atoi(list[0]));
	while (list[i])
		push(stack_a, ft_atoi(list[i++]));
	return (stack_a);
}

