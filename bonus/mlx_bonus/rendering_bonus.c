/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:20:05 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/05 14:04:02 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*get_image(char c, int can_exit)
{
	char	*output;

	output = NULL;
	if (c == '1')
		output = get_wall();
	else if (c == '0')
		output = "./images_bonus/black.xpm";
	else if (c == 'C')
		output = get_collectible();
	else if (c == 'P')
		output = "images_bonus/pacmanleft.xpm";
	else if (c == 'B')
		output = "images_bonus/orange.xpm";
	else if (c == 'E')
	{
		if (can_exit)
			output = "./images_bonus/opendoorE.xpm";
		else
			output = "./images_bonus/doorE.xpm";
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
	mlx_clear_window(game.mlx, game.win);
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
	put_count_window(&game);
}
