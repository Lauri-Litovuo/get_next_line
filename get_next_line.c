/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:13:29 by llitovuo          #+#    #+#             */
/*   Updated: 2023/11/22 14:08:28 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			buffer[100];
	ssize_t			b_read;
	int				index;

	index = 0;
	b_read = read(fd, buffer, sizeof(buffer));
	if (b_read == -1)
		return (NULL);
	if (b_read < sizeof(buffer))
		buffer[b_read + 1] = '\0';
	if (get_index(buffer, '\n', &index) < 0)
		index = sizeof(buffer);
	return (buffer);
}