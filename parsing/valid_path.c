/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:19:38 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/05 13:24:15 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(t_program *game)
{
	int	xx;
	int	yy;

	yy = 0;
	while (yy < game->map.y)
	{
		xx = 0;
		while (xx < game->map.x)
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
		fill = 'B';
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

// x < 0 || y < 0 || x >= game->map.x - 1 || y >= game->map.y - 1
// 		|| game->map.map[y][x] == '1' || 