/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:56:40 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/12 00:06:00 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack **stack)
{
	int		tmp;
	t_stack	*iter_i;
	t_stack	*iter_j;

	iter_i = *stack;
	while (iter_i)
	{
		iter_j = iter_i->next;
		while (iter_j)
		{
			if (iter_i->data < iter_j->data)
			{
				tmp = iter_i->data;
				iter_i->data = iter_j->data;
				iter_j->data = tmp;
			}
			iter_j = iter_j->next;
		}
		iter_i = iter_i->next;
	}
}

int	find_middle(t_stack **stack, int len)
{
	int		i;
	t_stack	*iter;
	t_stack	*tmp;

	iter = *stack;
	tmp = NULL;
	i = 0;
	while ((int)ft_stacksize(*stack) - len > i++)
		iter = iter->next;
	while (len--)
	{
		push(&tmp, iter->data);
		iter = iter->next;
	}
	bubble_sort(&tmp);
	i = 1;
	iter = tmp;
	while (((int)ft_stacksize(tmp) / 2 + (int)ft_stacksize(tmp) % 2) > i)
	{
		iter = iter->next;
		i++;
	}
	return (iter->data);
}

void	reset_stack_a(int pivot, t_stack **a)
{
	t_stack	*iter;
	int		size;
	int		i;

	iter = *a;
	i = 0;
	size = ft_stacksize(*a);
	while (iter->next != NULL)
	{
		if (iter->data == pivot)
			break ;
		iter = iter->next;
		i++;
	}
	if (i >= size / 2)
		while (pivot != ft_stacklast(*a)->data)
			ra(a);
	else
		while (pivot != ft_stacklast(*a)->data)
			rra(a);
}

int	divide_a(t_stack **a, t_stack **b, int len)
{
	t_stack	*iter;
	int		pivot;
	int		i;

	iter = *a;
	pivot = find_middle(a, len);
	i = 0;
	while ((int)ft_stacksize(*a) - len > i++)
		iter = iter->next;
	i = len;
	while (len != i / 2 + i % 2)
	{
		if (ft_stacklast(*a)->data < pivot && len--)
			pb(a, b);
		else
			ra(a);
	}
	//reset_stack_a(pivot, a);
	return (i / 2 + i % 2);
}

int	divide_b(t_stack **b, t_stack **a, int len)
{
	t_stack	*iter;
	int		pivot;
	int		i;

	pivot = find_middle(b, len);
	i = 0;
	iter = *b;
	while ((int)ft_stacksize(*b) - len > i++)
		iter = iter->next;
	while (len != i / 2)
	{
		if (pivot < ft_stacklast(*b)->data && len--)
			pa(a, b);
		else
			rb(b);
	}
	return (i / 2);
}

int	is_sorted(t_stack **stack, char flag, int len)
{
	int		i;
	int		*tmp;
	t_stack	*iter;

	iter = *stack;
	tmp = malloc(ft_stacksize(*stack) * sizeof(int));
	if (!tmp)
		return (0);
	i = 0;
	while (iter->next != NULL)
	{
		tmp[i++] = iter->data;
		iter = iter->next;
	}
	while (*stack != NULL)
	{
		if (flag == 'a' && len--)
		{
			if (tmp[i] > tmp[i - 1])
				return (0);
		}
		else if (flag == 'b' && len--)
		{
			if (tmp[i] < tmp[i - 1])
				return (0);
		}
		else
			return (1);
	}
	free (tmp);
	return (0);
}

int	find_min(t_stack **stack)
{
	t_stack	*iter;
	int		min;

	iter = *stack;
	min = iter->data;
	while (iter->next)
	{
		if (iter->next->data < min)
			min = iter->next->data;
		iter = iter->next;
	}
	return (min);
}

void	sort_three_a(t_stack **stack, char flag)
{
	if (!is_sorted(stack, flag, 3))
	{
		if (find_min(stack) == (*stack)->next->data
			&& (*stack)->data < ft_stacklast(*stack)->data)
			ra(stack);
		if (find_min(stack) == (*stack)->next->data
			&& (*stack)->data > ft_stacklast(*stack)->data)
			sa(stack);
		if (find_min(stack) == (*stack)->data
			&& (*stack)->next->data > ft_stacklast(*stack)->data)
			rra(stack);
		if (find_min(stack) == (*stack)->data
			&& (*stack)->next->data < ft_stacklast(*stack)->data)
		{
			ra(stack);
			sa(stack);
		}
		if (find_min(stack) == ft_stacklast(*stack)->data
			&& (*stack)->data < (*stack)->next->data)
		{
			rra(stack);
			sa(stack);
		}
	}
}

void	sort_three_b(t_stack **stack, char flag)
{
	if (!is_sorted(stack, flag, 3))
	{
		if (find_min(stack) == (*stack)->next->data
			&& (*stack)->data < ft_stacklast(*stack)->data)
		{
			rrb(stack);
			sb(stack);
		}
		if (find_min(stack) == (*stack)->next->data
			&& (*stack)->data > ft_stacklast(*stack)->data)
			rrb(stack);
		if (find_min(stack) == (*stack)->data
			&& (*stack)->next->data > ft_stacklast(*stack)->data)
			sb(stack);
		if (find_min(stack) == ft_stacklast(*stack)->data
			&& (*stack)->data < (*stack)->next->data)
			rb(stack);
		if (find_min(stack) == ft_stacklast(*stack)->data
			&& (*stack)->data > (*stack)->next->data)
		{
			rb(stack);
			sb(stack);
		}
	}
}

void	sort_a(t_stack **a, t_stack **b, int len)
{
	if (len && !is_sorted(a, 'a', len))
	{
		if (len == 2)
			sa(a);
		else if (len == 3)
		{
			sort_three_a(a, 'a');
		}
		else
		{
			len = divide_a(a, b, len);
			sort_a(a, b, len);
			sort_b(b, a, len);
		}
	}
}

void	sort_b(t_stack **b, t_stack **a, int len)
{
	if (is_sorted(b, 'b', len))
		while (len--)
			pa(a, b);
	if (len <= 3)
		printf("3den aşağı olanları sırala");
	else
	{
		len = divide_b(b, a, len);
		sort_a(a, b, len);
		sort_b(b, a, len);
	}
}




