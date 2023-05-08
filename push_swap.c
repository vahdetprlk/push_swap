/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:13:21 by vparlak           #+#    #+#             */
/*   Updated: 2023/05/08 16:55:14 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_addtolist(int argc, char **argv)
{
	char	**str_list;

	if (argc == 2)
		str_list = ft_split(argv[1], ' ');
	else
		str_list = argv + 1;
	return (str_list);
}

int	ft_isintitem(char *item)
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

int	ft_isintlist(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		if (!ft_isintitem(list[i]))
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

int	ft_isduplicate(char **list)
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

int	main(int argc, char *argv[])
{
	char	**str_list;

	if (argc > 1)
	{
		str_list = ft_addtolist(argc, argv);
		if (!ft_isintlist(str_list))
		{
			printf("Error\n");
			exit (0);
		}
		else if (!ft_isduplicate(str_list))
		{
			printf("Error\n");
			exit (0);
		}
	}
	return (0);
}
