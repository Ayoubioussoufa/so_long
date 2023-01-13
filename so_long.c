/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:39:44 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/05 11:36:18 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

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
	mlx_loop(game.mlx);
	return (0);
}
