/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:20:30 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/04 16:20:30 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_free(t_program *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game);
	exit(EXIT_SUCCESS);
}
