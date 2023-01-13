/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:19:17 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/04 16:19:17 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_error(t_program *game)
{
	int	xx;
	int	yy;

	yy = 0;
	while (yy < game->map.y - 1)
	{
		xx = 0;
		while (xx < game->map.x - 1)
		{
			if (game->map.map[yy][xx] != '1' && (game->map.map[yy][xx] == 'C'
				|| game->map.map[yy][xx] == 'E'))
			{
				write(2, "Error\n", 7);
				write(2, "No valid path", 14);
				free_map(game);
				exit(EXIT_FAILURE);
			}
			xx++;
		}
		yy++;
	}
}

void	valid_path(int x, int y, t_program *game, char *s)
{
	char	fill;

	if (s[0] == 'P')
		fill = 'I';
	else
		fill = '1';
	if (!ft_strchr(s, game->map.map[y][x]))
		return ;
	else
		game->map.map[y][x] = fill;
	valid_path(x, y - 1, game, s);
	valid_path(x, y + 1, game, s);
	valid_path(x - 1, y, game, s);
	valid_path(x + 1, y, game, s);
}
