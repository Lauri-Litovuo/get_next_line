/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:13:29 by llitovuo          #+#    #+#             */
/*   Updated: 2023/11/27 17:40:26 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//For tuesday: check how the pointers move around that the line is returned to next_line. What should be sent to read_file?
// is the strchr necessary? How about strlen?
// how to deal with the temporal char arrays? how to implement the static character here?

/**
 * @brief Get the line that ends with the next line character.
 * 
 * @param buffer 
 * @param line 
 * @return char* returns a full line.
 */
static char	*get_line(char *mix_bin)
{
	char			*line;
	static int		i;
	int				j;

	while (mix_bin[i] != '\n' && mix_bin[i] != '\0')
	{
		i++;
	}
	if (mix_bin[i] == '\0')
		return (NULL);
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
	{
		free (mix_bin);
		return (NULL);
	}
	j = 0;
	while (j <= i)
	{
		line[j] = mix_bin[j];
		j++;
	}
	return (line);
}
/**
 * @brief Combines the residue of buffer after line extraction to the mixed_bin.
 * Dynamically adjusts memory for the bin.
 * 
 * @param buffer 
 * @param mixed_bin 
 * @return char* return combined string.
 */
static char	*combine_incomplete(char *buffer, char *mix_bin)
{
	char	*temp;
	int		len;

	len = 0;
	while (mix_bin[len] = '\0')
	{
		len++;
	}
	temp = malloc((len + 1) * sizeof(char));
	if (!temp)
	{
		free(mix_bin);
		return (NULL);
	}
}

/**
 * @brief This function reads the file and returns a line for the get_next_line.
 * With the use of other static functions it should check for nulls and '\n'
 * 
 */

static char	*read_file(int fd)
{
	char	*buffer;
	char	*mix_bin;
	size_t	bit_read;

	if (mix_bin == 0)
		mix_bin = ft_calloc(1, 1)
	while (bit_read > 0)
	{
		bit_read = read(fd, buffer, BUFFER_SIZE);
		if (bit_read == -1)
			return (NULL);
		mix_bin = combine_incomplete(buffer, mix_bin);
		
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	int			bit_read;

	bit_read = 1;
	if (fd < 0)
		return (NULL);
	while (bit_read > 0)
	{
		bit_read = read_file(fd);
		line = get_line(line)
	}
	return (line);
}
