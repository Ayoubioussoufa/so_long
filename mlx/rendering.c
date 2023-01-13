/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:51:55 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/05 13:35:00 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_image(char c, int can_exit)
{
	char	*output;

	output = NULL;
	if (c == '1')
		output = "./images/wall.xpm";
	else if (c == '0')
		output = "./images/black.xpm";
	else if (c == 'C')
		output = "./images/Dofus_ocre.xpm";
	else if (c == 'P')
		output = "./images/slime.xpm";
	else if (c == 'E')
	{
		if (can_exit)
			output = "./images/opendoorE.xpm";
		else
			output = "./images/doorE.xpm";
	}
	return (output);
}

void	render_image(t_program game, int i, int j)
{
	char	*imgg;

	game.can_exit = 0;
	if (game.map.c == 0)
		game.can_exit = 1;
	imgg = get_image(game.map.map[j][i], game.can_exit);
	game.img = mlx_xpm_file_to_image(game.mlx, imgg,
			&game.img_size, &game.img_size);
	if (!game.img)
		error_image(&game);
	mlx_put_image_to_window(game.mlx, game.win, game.img, i * 60, j * 60);
	mlx_destroy_image(game.mlx, game.img);
}

void	ft_render_images(t_program game)
{
	int	i;
	int	j;

	j = 0;
	while (game.map.y > j)
	{
		i = 0;
		while (game.map.x > i)
		{
			render_image(game, i, j);
			i++;
		}
		j++;
	}
}
