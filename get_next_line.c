/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:13:29 by llitovuo          #+#    #+#             */
/*   Updated: 2023/11/30 14:37:01 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Must check the EOF behavior if there is no \n character.
EoB error, check combine function that it does not overwrite.
*/

/**
 * @brief Function extracts and returns a line, when newline character
 *  is found from mix_bin.
 * 
 * @param mix_bin The static variable, to which reads are appended.
 * @return char* The next line.
 */
char	*get_line(char *mix_bin)
{
	char			*line;
	int				i;

	i = 0;
	while (mix_bin[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, mix_bin, i + 2);
	return (line);
}
/**
 * @brief Assigns the residual after a newline char to mix_bin and
 * adjusts the memory for fit.
 * 
 * @param mix_bin The static variable, to which reads are appended.
 * @return char* Returns the address of the residual to be assigned
 * to mix_bin.
 */

char	*save_residual(char	*mix_bin)
{
	char	*residual;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (mix_bin[i] != '\n')
		i++;
	j = ft_strlen(mix_bin) - i;
	residual = calloc(j, sizeof(char));
	if (!residual)
		return (NULL);
	ft_strlcpy(residual, mix_bin + i + 1, j);
	free (mix_bin);
	return (residual);
}

/**
 * @brief Function combines each read buffer to static variable
 * with allocating fitting memory.
 * 
 * @param read_buffer the string from each read calls of size BUF_SIZE.
 * @param mix_bin Static variable collecting reads.
 * @return char* Allocated static variable of joined strings.
 */
char	*combine_to_mix(char *read_buffer, char *mix_bin)
{
	int		len;
	char	*temp;

	len = 0;
	temp = ft_calloc ((ft_strlen(mix_bin) + BUFFER_SIZE + 1), sizeof(char));
	if (!temp)
		return (NULL);
	temp = ft_strjoin(mix_bin, read_buffer);
	free (mix_bin);
	mix_bin = ft_calloc(ft_strlen(temp), sizeof(char));
	ft_strlcpy(mix_bin, temp, ft_strlen(temp));
	free (temp);
	return (mix_bin);
}

/**
 * @brief Function reads file until EOF or '\n' is found.
 * 
 * @param fd File descriptor to read from.
 * @param mix_bin Static variable of appended reads.
 * @return char* Returns the static variable if EOF reached or '\n' found.
 */
char	*read_file(int fd, char *mix_bin)
{
	char		*read_buffer;
	int			bit_read;

	read_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!read_buffer)
		return (NULL);
	bit_read = 1;
	while (bit_read > 0)
	{
		bit_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bit_read == -1)
		{
			free (read_buffer);
			return (NULL);
		}
		mix_bin = combine_to_mix(read_buffer, mix_bin);
		if (ft_strchr(mix_bin, '\n') != NULL)
			break ;
	}
	free (read_buffer);
	return (mix_bin);
}
/**
 * @brief Get the next line from a file (fd). Keeps residual 
 * beyond next-line in static variable
 * 
 * @param fd File descriptor.
 * @return char* Returns a pointer to allocated new line.
 */

char	*get_next_line(int fd)
{
	static char		*mix_bin;
	char			*line;

	if (!mix_bin)
		mix_bin = ft_calloc(1, sizeof(char));
	if (fd < 0 || !mix_bin)
		return (NULL);
	if (ft_strchr(mix_bin, '\n') == NULL)
	{
		mix_bin = read_file(fd, mix_bin);
		if (!mix_bin)
		{
			free (mix_bin);
			return (NULL);
		}
	}
	line = get_line(mix_bin);
	mix_bin = save_residual(mix_bin);
	return (line);
}
