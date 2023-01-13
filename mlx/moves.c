/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:31:50 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/05 11:49:09 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		ft_putnbr_fd(game->count, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (game->map.map[game->map.player.y - 1][game->map.player.x] == 'C')
	{
		game->map.c--;
		game->map.map[game->map.player.y][game->map.player.x] = '0';
		game->map.map[game->map.player.y - 1][game->map.player.x] = 'P';
		game->map.player.y--;
		game->count++;
		ft_putnbr_fd(game->count, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (game->map.map[game->map.player.y - 1][game->map.player.x] == 'E'
			&& !game->map.c)
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
		ft_putnbr_fd(game->count, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (game->map.map[game->map.player.y + 1][game->map.player.x] == 'C')
	{
		game->map.c--;
		game->map.map[game->map.player.y][game->map.player.x] = '0';
		game->map.map[game->map.player.y + 1][game->map.player.x] = 'P';
		game->map.player.y++;
		game->count++;
		ft_putnbr_fd(game->count, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (game->map.map[game->map.player.y + 1][game->map.player.x] == 'E'
			&& !game->map.c)
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
		ft_putnbr_fd(game->count, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (game->map.map[game->map.player.y][game->map.player.x - 1] == 'C')
	{
		game->map.c--;
		game->map.map[game->map.player.y][game->map.player.x] = '0';
		game->map.map[game->map.player.y][game->map.player.x - 1] = 'P';
		game->map.player.x--;
		game->count++;
		ft_putnbr_fd(game->count, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (game->map.map[game->map.player.y][game->map.player.x - 1] == 'E'
			&& !game->map.c)
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
		ft_putnbr_fd(game->count, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (game->map.map[game->map.player.y][game->map.player.x + 1] == 'C')
	{
		game->map.c--;
		game->map.map[game->map.player.y][game->map.player.x] = '0';
		game->map.map[game->map.player.y][game->map.player.x + 1] = 'P';
		game->map.player.x++;
		game->count++;
		ft_putnbr_fd(game->count, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (game->map.map[game->map.player.y][game->map.player.x + 1] == 'E'
			&& !game->map.c)
		ft_free(game);
}
