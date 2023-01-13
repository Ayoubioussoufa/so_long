/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:16:10 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/05 11:43:29 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	keys(int key, t_program *game)
{
	if (key == 0)
		move_left(game);
	else if (key == 1)
		move_down(game);
	else if (key == 2)
		move_right(game);
	else if (key == 13)
		move_up(game);
	else if (key == 53)
		ft_free(game);
	mlx_clear_window(game->mlx, game->win);
	ft_render_images(*game);
	return (0);
}
