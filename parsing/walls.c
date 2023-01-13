/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:28:46 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/05 13:29:57 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_mapp(t_program *game)
{
	write(2, "Error\n", 7);
	write(2, "Correct the map", 16);
	free_map(game);
	exit(EXIT_FAILURE);
}

int	checking_walls(t_program *game)
{
	int	i;

	i = 0;
	while (game->map.y - 1 > i)
	{
		if (game->map.map[i][0] == '1')
			i++;
		else
			return (0);
	}
	i = 0;
	while (game->map.x - 1 > i)
	{
		if (game->map.map[0][i] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int	checking_outer_walls(t_program *game)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	x = game->map.x - 1;
	y = game->map.y - 1;
	while (x >= i)
	{
		if (game->map.map[y][i] == '1')
			i++;
		else
			return (0);
	}
	i = 0;
	while (y >= i)
	{
		if (game->map.map[i][x] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int	checking(t_program *game)
{
	if (game->map.e == 1 && game->map.c >= 1 && game->map.p == 1)
		return (1);
	else
		return (0);
}

void	checking_ecp(t_program *game)
{
	int	x;
	int	y;

	y = 0;
	game->map.p = 0;
	game->map.c = 0;
	game->map.e = 0;
	while (game->map.y > y)
	{
		x = 0;
		while (game->map.x > x)
		{
			if (game->map.map[y][x] == 'E')
				game->map.e++;
			else if (game->map.map[y][x] == 'C')
				game->map.c++;
			else if (game->map.map[y][x] == 'P')
				game->map.p++;
			else if (game->map.map[y][x] != '0' && game->map.map[y][x] != '1')
				error_mapp(game);
			x++;
		}
		y++;
	}
}
