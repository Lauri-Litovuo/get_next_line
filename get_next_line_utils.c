/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:14:30 by llitovuo          #+#    #+#             */
/*   Updated: 2023/11/22 13:59:57 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	char	*sp;
	char	ch;

	sp = (char *)s;
	ch = c;
	while (*sp != '\0')
	{
		if (*sp == ch)
			return (sp);
		sp++;
	}
	if (*sp == ch)
		return (sp);
	return (NULL);
}

int	get_index(char *s, int c, int *index)
{
	char	*ptr;

	ptr = ft_strchr(s, c);
	if (ptr == NULL)
		return (-1);
	*index = (int)(ptr - s);
}
