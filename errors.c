/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:47:39 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/07 13:10:53 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
