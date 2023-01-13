/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:18:53 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/05 13:40:58 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_program *game)
{
	int	i;

	i = 0;
	while (game->map.y > i)
		free(game->map.map[i++]);
	free(game->map.map);
}
