/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:04:57 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/07 11:38:36 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_count_window(t_program *game)
{
	char	*num;
	char	*str;

	num = ft_itoa(game->count);
	str = ft_strjnofree("Moves :", num);
	mlx_string_put(game->mlx, game->win, 0, 0, 2147483647, str);
	free(num);
	free(str);
}
