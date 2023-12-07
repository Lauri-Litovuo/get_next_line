/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:44:10 by llitovuo          #+#    #+#             */
/*   Updated: 2023/12/07 12:44:49 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	char	*line;
	int		reads;
	int		fd;

	line = "lol";
	reads = 0;
	fd = open("oneliner.txt", O_RDONLY);
	if (fd == -1)
		printf("failure");
	while (reads < 200 && line != 0)
	{
		line = get_next_line(fd);
		reads++;
		printf("Line %d:%s\n", reads, line);
		if (line == NULL || line == 0)
			break ;
	}
	close (fd);
	free (line);
	return (0);
}