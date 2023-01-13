/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:07:06 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/10 10:35:53 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_enemy_coords(t_program *game)
{
	int	yy;
	int	xx;
	int	i;

	yy = 0;
	i = 0;
	while (game->map.y - 1 >= yy)
	{
		xx = 0;
		while (game->map.x - 1 >= xx)
		{
			if (game->map.map[yy][xx] == 'B' && i < game->map.b)
			{
				game->map.enemy[i].x = xx;
				game->map.enemy[i].y = yy;
				i++;
			}
			xx++;
		}
		yy++;
	}
}

void	move_up_enemy(t_program *game, int i)
{
	int	x;
	int	y;

	y = game->map.player.y;
	x = game->map.player.x;
	if (game->map.map[game->map.enemy[i].y - 1][game->map.enemy[i].x] != '0'
		&& game->map.map[game->map.enemy[i].y - 1][game->map.enemy[i].x] != 'P')
		game->map.enemy[i].alrd = 1;
	else if (game->map.map[game->map.enemy[i].y - 1]
		[game->map.enemy[i].x] == '0')
	{
		ft_swap(&game->map.map[game->map.enemy[i].y][game->map.enemy[i].x],
			&game->map.map[game->map.enemy[i].y - 1][game->map.enemy[i].x]);
		game->map.enemy[i].y -= 1;
	}
	else if (game->map.map[game->map.enemy[i].y - 1] == game->map.map[y]
		&& game->map.map[game->map.enemy[i].x] == game->map.map[x])
		ft_free(game);
}

void	move_down_enemy(t_program *game, int i)
{
	int	x;
	int	y;

	y = game->map.player.y;
	x = game->map.player.x;
	if (game->map.map[game->map.enemy[i].y + 1][game->map.enemy[i].x] != '0'
		&& game->map.map[game->map.enemy[i].y + 1][game->map.enemy[i].x] != 'P')
		game->map.enemy[i].alrd = 0;
	else if (game->map.map[game->map.enemy[i].y + 1]
		[game->map.enemy[i].x] == '0')
	{
		ft_swap(&game->map.map[game->map.enemy[i].y][game->map.enemy[i].x],
			&game->map.map[game->map.enemy[i].y + 1][game->map.enemy[i].x]);
		game->map.enemy[i].y += 1;
	}
	else if (game->map.map[game->map.enemy[i].y + 1] == game->map.map[y]
		&& game->map.map[game->map.enemy[i].x] == game->map.map[x])
		ft_free(game);
}

void	move_left_enemy(t_program *game, int i)
{
	int	x;
	int	y;

	y = game->map.player.y;
	x = game->map.player.x;
	if (game->map.map[game->map.enemy[i].y][game->map.enemy[i].x - 1] != '0'
		&& game->map.map[game->map.enemy[i].y][game->map.enemy[i].x - 1] != 'P')
		game->map.enemy[i].alr = 0;
	else if (game->map.map[game->map.enemy[i].y]
		[game->map.enemy[i].x - 1] == '0')
	{
		ft_swap(&game->map.map[game->map.enemy[i].y][game->map.enemy[i].x],
			&game->map.map[game->map.enemy[i].y][game->map.enemy[i].x - 1]);
		game->map.enemy[i].x -= 1;
	}
	else if (game->map.map[game->map.enemy[i].y] == game->map.map[y]
		&& game->map.map[game->map.enemy[i].x - 1] == game->map.map[x])
		ft_free(game);
}

void	move_right_enemy(t_program *game, int i)
{
	int	x;
	int	y;

	y = game->map.player.y;
	x = game->map.player.x;
	if (game->map.map[game->map.enemy[i].y][game->map.enemy[i].x + 1] != '0'
		&& game->map.map[game->map.enemy[i].y][game->map.enemy[i].x + 1] != 'P')
		game->map.enemy[i].alr = 1;
	else if (game->map.map[game->map.enemy[i].y]
		[game->map.enemy[i].x + 1] == '0')
	{
		ft_swap(&game->map.map[game->map.enemy[i].y][game->map.enemy[i].x],
			&game->map.map[game->map.enemy[i].y][game->map.enemy[i].x + 1]);
		game->map.enemy[i].x += 1;
	}
	else if (game->map.map[game->map.enemy[i].y] == game->map.map[y]
		&& game->map.map[game->map.enemy[i].x + 1] == game->map.map[x])
		ft_free(game);
}
