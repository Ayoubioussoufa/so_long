/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:45:20 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/05 11:41:23 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(t_program *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game);
	exit(EXIT_SUCCESS);
}
