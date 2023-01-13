/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:19:45 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/04 16:19:45 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	fill_map(char *av, t_program *game)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\n", 7);
		write(2, "File couldn't be opened", 24);
		exit(EXIT_FAILURE);
	}
	game->map.map = malloc((game->map.y * (game->map.x + 1) * sizeof(char)));
	if (!game->map.map)
		return ;
	while (i < game->map.y)
		game->map.map[i++] = get_next_line(fd);
	close(fd);
}
