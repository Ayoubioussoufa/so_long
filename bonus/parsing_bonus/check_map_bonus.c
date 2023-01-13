/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:19:56 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/04 16:19:56 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_map(char *av, t_program *game)
{
	if (!checking_ber(av))
		error_name();
	width_height_filling_map(av, game);
	if (game->map.x == game->map.y)
		error_width_height(game);
	checking_ecp(game);
	if (!checking_walls(game) || !checking_outer_walls(game)
		|| !checking(game))
		error_mapp(game);
	check_player_coords(game);
	valid_path(game->map.player.x, game->map.player.y, game, "P0C");
	valid_path(game->map.player.x, game->map.player.y, game, "EI");
	ft_error(game);
	free_map(game);
	fill_map(av, game);
	checking_ecp(game);
	checking_b(game);
}
