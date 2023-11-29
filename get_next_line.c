/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:13:29 by llitovuo          #+#    #+#             */
/*   Updated: 2023/11/29 14:38:08 by llitovuo         ###   ########.fr       */
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

static char	*save_residual(char	*mix_bin)
{
	char	*new_mix;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (mix_bin[i] != '\n')
		i++;
	j = ft_strlen(mix_bin) - i;
	new_mix = calloc(j, sizeof(char));
	if (!new_mix)
		return (NULL);
	new_mix = ft_strlcpy(new_mix, mix_bin + i + 1, j);
	free (mix_bin);
	return (new_mix);
}


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

static char	*read_file(int fd, char *mix_bin)
{
	char		*read_buffer[BUFFER_SIZE + 1];
	size_t		bit_read;

	while (bit_read > 0)
	{
		bit_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bit_read == -1)
			return (NULL);
		mix_bin = combine_to_mix(read_buffer, mix_bin);
		if (!mix_bin)
			return (NULL);
		if (ft_strchr(mix_bin, '\n') != NULL)
			break ;
	}
	return (mix_bin);
}

char	*get_next_line(int fd)
{
	const char		*mix_bin;
	char			*line;

	if (!mix_bin)
		mix_bin = ft_calloc(1, sizeof(char));
	if (fd < 0 !mix_bin)
		return (NULL);
	if (ft_strchr(mix_bin, '\n') == NULL)
	{
		mix_bin = read_file(fd, mix_bin);
		if (mix_bin == NULL)
		{
			free (mix_bin);
			return (NULL);
		}
	}
	line = get_line(mix_bin);
	mix_bin = save_residual(mix_bin);
	//here should be propably some kind of check if the read-file has reached EOF
	if (line == NULL)
	{
		free (mix_bin);
		return (NULL);
	}
	return (line);
}
