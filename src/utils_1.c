/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:40:35 by vparlak           #+#    #+#             */
/*   Updated: 2023/06/16 20:59:21 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**add_to_list(int argc, char **argv)
{
	char	**str_list;

	if (argc == 2)
		str_list = ft_split(argv[1], ' ');
	else
		str_list = argv + 1;
	return (str_list);
}

int	is_int_item(char *item)
{
	char	*iter;

	if (item[0] == '-')
		iter = &item[1];
	else
		iter = &item[0];
	while (*iter)
	{
		if (!ft_isdigit(*iter))
			return (0);
		iter++;
	}
	return (1);
}

int	is_int_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		if (!is_int_item(list[i]) || ft_strlen(list[i]) == 0)
			return (0);
		i++;
	}
	i = 0;
	while (list[i])
	{
		if (!(ft_atol(list[i]) >= -2147483648
				&& ft_atol(list[i]) <= 2147483647))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i])
	{
		j = i + 1;
		while (list[j])
		{
			if (!ft_strcmp(list[i], list[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	error_case(char *msg, int status)
{
	ft_printf("%s\n", msg);
	exit (status);
}
