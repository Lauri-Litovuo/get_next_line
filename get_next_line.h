/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:15:23 by llitovuo          #+#    #+#             */
/*   Updated: 2023/12/05 12:50:17 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
char		*read_file(int fd, char *mix_bin);
char		*save_residual(char	*mix_bin, char *residual);
char		*extract_line(char *mix_bin, char *line);

size_t		ft_strlen(char *a);
char		*ft_strchr(char *s, int c);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, char *src, size_t dstsize);
char		*ft_strjoin(char *s1, char *s2);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
#endif