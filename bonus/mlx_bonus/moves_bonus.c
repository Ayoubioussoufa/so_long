/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:20:11 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/05 13:58:27 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_swap(char *x, char *y)
{
	char	z;

	z = *x;
	*x = *y;
	*y = z;
}

void	move_up(t_program *game)
{
	if (game->map.map[game->map.player.y - 1][game->map.player.x] == '0')
	{
		ft_swap(&game->map.map[game->map.player.y - 1][game->map.player.x],
			&game->map.map[game->map.player.y][game->map.player.x]);
		game->map.player.y--;
		game->count++;
	}
	else if (game->map.map[game->map.player.y - 1][game->map.player.x] == 'C')
	{
		game->map.c--;
		game->map.map[game->map.player.y][game->map.player.x] = '0';
		game->map.map[game->map.player.y - 1][game->map.player.x] = 'P';
		game->map.player.y--;
		game->count++;
	}
	else if (game->map.map[game->map.player.y - 1][game->map.player.x] == 'E'
			&& !game->map.c)
		ft_free(game);
	else if (game->map.map[game->map.player.y - 1][game->map.player.x] == 'B')
		ft_free(game);
}

void	move_down(t_program *game)
{
	if (game->map.map[game->map.player.y + 1][game->map.player.x] == '0')
	{
		ft_swap(&game->map.map[game->map.player.y + 1][game->map.player.x],
			&game->map.map[game->map.player.y][game->map.player.x]);
		game->map.player.y++;
		game->count++;
	}
	else if (game->map.map[game->map.player.y + 1][game->map.player.x] == 'C')
	{
		game->map.c--;
		game->map.map[game->map.player.y][game->map.player.x] = '0';
		game->map.map[game->map.player.y + 1][game->map.player.x] = 'P';
		game->map.player.y++;
		game->count++;
	}
	else if (game->map.map[game->map.player.y + 1][game->map.player.x] == 'E'
			&& !game->map.c)
		ft_free(game);
	else if (game->map.map[game->map.player.y + 1][game->map.player.x] == 'B')
		ft_free(game);
}

void	move_left(t_program *game)
{
	if (game->map.map[game->map.player.y][game->map.player.x - 1] == '0')
	{
		ft_swap(&game->map.map[game->map.player.y][game->map.player.x - 1],
			&game->map.map[game->map.player.y][game->map.player.x]);
		game->map.player.x--;
		game->count++;
	}
	else if (game->map.map[game->map.player.y][game->map.player.x - 1] == 'C')
	{
		game->map.c--;
		game->map.map[game->map.player.y][game->map.player.x] = '0';
		game->map.map[game->map.player.y][game->map.player.x - 1] = 'P';
		game->map.player.x--;
		game->count++;
	}
	else if (game->map.map[game->map.player.y][game->map.player.x - 1] == 'E'
			&& !game->map.c)
		ft_free(game);
	else if (game->map.map[game->map.player.y][game->map.player.x - 1] == 'B')
		ft_free(game);
}

void	move_right(t_program *game)
{
	if (game->map.map[game->map.player.y][game->map.player.x + 1] == '0')
	{
		ft_swap(&game->map.map[game->map.player.y][game->map.player.x + 1],
			&game->map.map[game->map.player.y][game->map.player.x]);
		game->map.player.x++;
		game->count++;
	}
	else if (game->map.map[game->map.player.y][game->map.player.x + 1] == 'C')
	{
		game->map.c--;
		game->map.map[game->map.player.y][game->map.player.x] = '0';
		game->map.map[game->map.player.y][game->map.player.x + 1] = 'P';
		game->map.player.x++;
		game->count++;
	}
	else if (game->map.map[game->map.player.y][game->map.player.x + 1] == 'E'
			&& !game->map.c)
		ft_free(game);
	else if (game->map.map[game->map.player.y][game->map.player.x + 1] == 'B')
		ft_free(game);
}
