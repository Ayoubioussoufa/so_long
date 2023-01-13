/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_coords_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:19:25 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/04 16:19:25 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_player_coords(t_program *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.y - 1 >= y)
	{
		x = 0;
		while (game->map.x - 1 >= x)
		{
			if (game->map.map[y][x] == 'P')
			{
				game->map.player.x = x;
				game->map.player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	checking_b(t_program *game)
{
	int	x;
	int	y;

	y = 0;
	game->map.b = 0;
	while (game->map.y - 1 > y)
	{
		x = 0;
		while (game->map.x - 1 > x)
		{
			if (game->map.map[y][x] == 'B')
				game->map.b++;
			else if (game->map.map[y][x] != '0' && game->map.map[y][x] != '1'
				&& game->map.map[y][x] != 'P' && game->map.map[y][x] != 'C'
				&& game->map.map[y][x] != 'E')
				error_mapp(game);
			x++;
		}
		y++;
	}
}
