/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:14:30 by llitovuo          #+#    #+#             */
/*   Updated: 2023/11/27 11:15:32 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	char			*cpysrc;

	cpysrc = (char *)src;
	i = 0;
	if (dstsize > 0)
	{
		while (cpysrc[i] != '\0' && i + 1 < dstsize)
		{
			dst[i] = cpysrc[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (cpysrc[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strndup(char *s, size_t n)
{
	char	*dest;
	int		len;

	len = 0;
	while (s[len] != '\0')
		len++;
	if (len < n)
		dest = (char *)malloc (len * sizeof(char) + 1);
	else
		dest = (char *)malloc (n * sizeof(char) + 1);
	if (!(dest))
		return (NULL);
	if (len < n)
		ft_strlcpy(dest, s, (len + 1));
	else
		ft_strlcpy(dest, s, (n + 1));
	return (dest);
}
