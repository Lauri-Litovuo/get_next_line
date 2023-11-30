/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:14:30 by llitovuo          #+#    #+#             */
/*   Updated: 2023/11/29 16:17:37 by llitovuo         ###   ########.fr       */
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
	while (a[i] != 0)
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	temp;
	unsigned int	i;

	if ((dst == NULL || *dst == '\0') && src && dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	temp = 0;
	if (dstsize > 0)
	{
		temp = dst_len;
		while (dst_len < dstsize - 1 && src[i] != '\0')
		{
			dst[dst_len] = src[i];
			dst_len++;
			i++;
		}
		dst[dst_len] = '\0';
	}
	if (dstsize < dst_len)
		return (dstsize + src_len);
	return (temp + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	int		len;

	len = ft_strlen((char *)s1);
	len += ft_strlen((char *)s2);
	joint = (char *) malloc(len * sizeof(char) + 1);
	if (!(joint))
		return (NULL);
	ft_strlcpy(joint, s1, len + 1);
	ft_strlcat(joint, s2, len + 1);
	return (joint);
}
