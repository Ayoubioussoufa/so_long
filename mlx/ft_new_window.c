/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:39:58 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/05 11:42:27 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(t_program *game)
{
	ft_free(game);
	return (0);
}

void	ft_new_window(t_program *game)
{
	game->win = mlx_new_window(game->mlx, (game->map.x) * 60,
			(game->map.y) * 60, "so_long");
	if (!game->win)
	{
		write(2, "Error\n", 7);
		write(2, "Unable to create a window.", 27);
		free_map(game);
		exit(EXIT_FAILURE);
	}
	mlx_hook(game->win, 17, 0, &ft_close, game);
}
