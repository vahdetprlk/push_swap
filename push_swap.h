/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparlak <vparlak@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:55:11 by vparlak           #+#    #+#             */
/*   Updated: 2023/05/08 18:52:13 by vparlak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "include/libft/libft.h"

char	**add_to_list(int argc, char **argv);

int		is_int_item(char *item);
int		is_int_list(char **list);
int		is_duplicate(char **list);

void	error_case(char *msg, int status);

#endif
