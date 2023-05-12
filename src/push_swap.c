/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:00:34 by vparlak           #+#    #+#             */
/*   Updated: 2023/05/13 01:24:02 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**str_list;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		str_list = add_to_list(argc, argv);
		if (!is_int_list(str_list))
			error_case("Error", 0);
		else if (!is_duplicate(str_list))
			error_case("Error", 0);
		init_stack_a(&a, str_list);
		printf("---\n");
		bastir(a);
		printf("---\n");
		pb(&a, &b);
		pb(&a, &b);
		pb(&a, &b);
		printf("---\n");
		bastir(a);
		printf("---\n");
		rra(&a);
		printf("---\n");
		bastir(a);
		printf("---\n");
		printf("---\n");
		bastir(b);
		printf("---\n");
		rrb(&b);
		printf("---\n");
		bastir(b);
		printf("---\n");
		rrr(&a, &b);
		printf("---\n");
		bastir(a);
		printf("---\n");
		printf("---\n");
		bastir(b);
		printf("---\n");
		rr(&a, &b);
		printf("---\n");
		bastir(a);
		printf("---\n");
		printf("---\n");
		bastir(b);
		printf("---\n");
		free(a);
	}
	return (0);
}
