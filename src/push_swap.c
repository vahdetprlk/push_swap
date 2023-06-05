/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:00:34 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/05 17:41:59 by vparlak          ###   ########.fr       */
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
		sort_a(&a, &b);
		printf("a---\n");
		print_stack(a);
		printf("b---\n");
		print_stack(b);

		// Kullanılmayan Fonksiyonları en son silmeyi unutma.
		/* buraya free fonksiyonları gelecek bu free
		fonksiyonları stackin daha önce free bırakılıp bırakılmadığını
		kontol ederek eğer allocated memory varsa free bırakacak */
	}
	return (0);
}
