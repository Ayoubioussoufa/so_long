/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:39:44 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/05 13:39:28 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_program	game;

	if (ac != 2)
		exit(EXIT_FAILURE);
	check_map(av[1], &game);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		write(2, "Error\n", 7);
		write(2, "Unable to create connection to X server.", 41);
		free_map(&game);
		exit(EXIT_FAILURE);
	}
	ft_new_window(&game);
	ft_render_images(game);
	mlx_hook(game.win, 2, 0, *keys, &game);
	mlx_loop_hook(game.mlx, moves_enemy, &game);
	mlx_loop(game.mlx);
	return (0);
}
