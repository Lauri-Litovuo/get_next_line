/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:13:29 by llitovuo          #+#    #+#             */
/*   Updated: 2023/11/23 12:48:51 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE];
	char			leftover[BUFFER_SIZE];
	ssize_t			b_read;
	ssize_t			index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	index = 0;
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, sizeof(buffer));
		if (b_read == -1)
			return (NULL);
		if (b_read == 0)
			print_line(buffer, BUFFER_SIZE);
		else
			save_leftovers(leftover, buffer, BUFFER_SIZE);
		index = 0;
	}
	return (buffer);
}
