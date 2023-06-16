/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:17:35 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/16 20:40:41 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stack **stack_a, char **list)
{
	int	i;

	i = 1;
	*stack_a = ft_stacknew(ft_atoi(list[0]));
	while (list[i])
		push_init(stack_a, ft_atoi(list[i++]));
}

size_t	ft_stacksize(t_stack *stack)
{
	size_t	n;

	n = 0;
	while (stack != NULL)
	{
		stack = stack->n;
		n++;
	}
	return (n);
}

void	print_stack(t_stack *stack)
{
	t_stack	*iter;

	iter = ft_stacklast(stack);
	while (!(iter == NULL))
	{
		printf("%d\n", iter->d);
		iter = iter->p;
	}
}

void	free_stacks(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = NULL;
	while (*a != NULL)
	{
		temp = *a;
		*a = (*a)->n;
		free(temp);
	}
	while (*b != NULL)
	{
		temp = *b;
		*b = (*b)->n;
		free(temp);
	}
}

void	check_arguments(char **str_list)
{
	if (!is_int_list(str_list))
		error_case("Error", 1);
	else if (!is_duplicate(str_list))
		error_case("Error", 1);
}
