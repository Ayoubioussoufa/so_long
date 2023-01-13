/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:19:03 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/07 13:11:13 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_width_height(t_program *game)
{
	write(2, "Error\n", 7);
	write(2, "The map must be rectangular", 28);
	free_map(game);
	exit(EXIT_FAILURE);
}

void	error_map(void)
{
	write(2, "Error\n", 7);
	write(2, "Correct the map", 16);
	exit(EXIT_FAILURE);
}

void	error_name(void)
{
	write(2, "Error\n", 7);
	write(2, "Wrong file name", 31);
	exit(EXIT_FAILURE);
}

void	error_file(void)
{
	write(2, "Error\n", 7);
	write(2, "No such file or directory", 26);
	exit(EXIT_FAILURE);
}

void	error_image(t_program *game)
{
	write(2, "Error\n", 7);
	write(2, "Error image", 12);
	free_map(game);
	exit(EXIT_FAILURE);
}
