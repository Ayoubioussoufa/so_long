/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:06:53 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/07 12:13:54 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_program *game)
{
	int	i;

	i = 0;
	while (game->map.y > i)
		free(game->map.map[i++]);
	free(game->map.map);
}
