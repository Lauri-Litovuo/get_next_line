/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:14:30 by llitovuo          #+#    #+#             */
/*   Updated: 2023/11/23 11:14:34 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
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

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	write(fd, s, i);
}
