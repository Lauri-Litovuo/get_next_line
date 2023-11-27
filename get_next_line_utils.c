/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:14:30 by llitovuo          #+#    #+#             */
/*   Updated: 2023/11/27 15:13:06 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	zero;
	char	*zerop;

	zero = 0;
	zerop = s;
	while (n > 0)
	{
		*zerop = zero;
		zerop++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size && count && ((count * size) / count) != size)
		return (NULL);
	if (count == 0)
		count = 1;
	ptr = malloc(count * size);
	if (!(ptr))
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}

size_t	ft_strlen(const char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
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
