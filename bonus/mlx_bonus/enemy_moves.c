/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:10:59 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/09 16:14:38 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	moves_enemy(t_program *game)
{
	static int	i;

	check_enemy_coords(game);
	if (i < game->map.b)
	{
		if (i % 2 == 0)
		{
			if (!game->map.enemy[i].alr)
				move_right_enemy(game, i);
			else
				move_left_enemy(game, i);
		}
		else
		{
			if (!game->map.enemy[i].alrd)
				move_up_enemy(game, i);
			else
				move_down_enemy(game, i);
		}
		i++;
	}
	else
		i = 0;
	ft_render_images(*game);
	return (0);
}
