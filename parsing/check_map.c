/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:51:03 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/05 13:17:30 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map(char *av, t_program *game)
{
	if (checking_ber(av) == 0)
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
	valid_path(game->map.player.x, game->map.player.y, game, "EB");
	ft_error(game);
	free_map(game);
	fill_map(av, game);
	checking_ecp(game);
}
