/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_window_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:20:23 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/04 16:20:23 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_close(t_program *game)
{
	ft_free(game);
	return (0);
}

void	ft_new_window(t_program *game)
{
	game->win = mlx_new_window(game->mlx, (game->map.x) * 60,
			(game->map.y) * 60, "PTSD");
	if (!game->win)
	{
		write(2, "Error\n", 7);
		write(2, "Unable to create connection to X server.", 41);
		free_map(game);
		exit(EXIT_FAILURE);
	}
	mlx_hook(game->win, 17, 0, &ft_close, game);
}
