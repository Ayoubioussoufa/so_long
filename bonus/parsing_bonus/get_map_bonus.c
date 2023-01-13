/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:19:33 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/04 16:19:33 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_strn(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	return (i);
}

void	error_mappp(char *line)
{
	free(line);
	write(2, "Error\n", 7);
	write(2, "Correct the map", 16);
	exit(EXIT_FAILURE);
}

char	*line_protection(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		error_mappp(line);
	return (line);
}

void	width_height_filling_map(char *av, t_program *game)
{
	int		fd;
	char	*line;
	int		width_recent;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		error_file();
	game->map.y = 0;
	line = line_protection(fd);
	while (line)
	{
		if (ft_strchr(line, '\n'))
			width_recent = ft_strn(line) - 1;
		else
			width_recent = ft_strn(line);
		if (game->map.y == 0)
			game->map.x = width_recent;
		else if (game->map.x != width_recent)
			error_map();
		game->map.y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	fill_map(av, game);
}
