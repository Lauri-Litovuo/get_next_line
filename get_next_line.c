/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:13:29 by llitovuo          #+#    #+#             */
/*   Updated: 2023/11/29 09:33:09 by llitovuo         ###   ########.fr       */
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

i = 0;
j = 0;
while (mix_bin[i] != '\n')
	i++;
new_mix = calloc(j, sizeof(char));
j = ft_strlen(mix_bin) - i;
ft_strlcpy(new_mix, mix_bin + i + 1, j);
free (mix_bin);
mix_bin = new_mix;


/**
 * @brief Combines the residue of buffer after line extraction to the mixed_bin.
 * Dynamically adjusts memory for the bin.
 * 
 * @param buffer 
 * @param mixed_bin 
 * @return char* return combined string.
 */
static char	*combine_to_mix(char *buffer, char *mix_bin)
{
	int		len;
	char	*temp;

	len = 0;
	temp = malloc ((sizeof(mix_bin) + BUFFER_SIZE) * sizeof(char));
	if (!temp)
	{
		free(mix_bin);
		return (NULL);
	}
	temp = ft_strjoin(mix_bin, buffer);
	free (mix_bin);
	return (temp);
}

/**
 * @brief This function reads the file and returns a line for the get_next_line.
 * With the use of other static functions it should check for nulls and '\n'
 * 
 */

static char	*read_file(int fd, char *buffer)
{
	char		*buffer;
	const char	*mix_bin;
	size_t		bit_read;

	if (mix_bin == 0)
		mix_bin = ft_calloc(1, sizeof(char));
	while (bit_read > 0 && ft_strchr(buffer, '\n') != NULL)
	{
		bit_read = read(fd, buffer, BUFFER_SIZE);
		if (bit_read == -1)
		{
			free (mix_bin);
			return (NULL);
		}
		mix_bin = combine_to_mix(buffer, mix_bin);
		if (!mix_bin)
			return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;

	if (fd < 0)
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1) * sizeof(char));
	line = read_file(fd, buffer);
	if (line)
	if (line == 0)
	{
		free (buffer);
		return (NULL);
	}
	free (buffer);
	return (line);
}
