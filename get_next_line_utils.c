/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:14:30 by llitovuo          #+#    #+#             */
/*   Updated: 2023/11/23 12:45:55 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	char				*dstp;
	char				*srcp;
	unsigned long		i;

	dstp = (char *)dst;
	srcp = (char *)src;
	i = 0;
	if (!srcp && !dstp && len)
		return (dst);
	if (srcp < dstp)
	{
		while (len--)
			dstp[len] = srcp[len];
		return (dst);
	}
	else
	{
		while (i != len)
		{
			dstp[i] = srcp[i];
			i++;
		}
	}
	return (dst);
}

size_t	print_line(char *buffer, ssize_t max_size)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\n' && i < max_size)
		i++;
	write(1, buffer, i);
	return (i);
}

char	save_leftovers(char *leftover, char *buffer, ssize_t max_size)
{
	size_t	i;

	while (buffer[i] != '\n' && i < max_size)
		i++;
	ft_memmove(leftover, buffer, i);
}
