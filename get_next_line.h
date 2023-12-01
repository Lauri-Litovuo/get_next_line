/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:15:23 by llitovuo          #+#    #+#             */
/*   Updated: 2023/12/01 12:32:49 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
char		*read_file(int fd, char *mix_bin);
char		*combine_to_mix(char *read_buffer, char *mix_bin);
char		*save_residual(char	*mix_bin);
char		*get_line(char *mix_bin);

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(const char *a);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
#endif
