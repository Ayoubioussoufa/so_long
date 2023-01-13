/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:12:53 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/05 13:22:23 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
