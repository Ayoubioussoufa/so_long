/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:04:02 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/10 10:11:53 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*get_collectible(void)
{
	static int	i;
	char		*output;

	output = NULL;
	if (++i <= 30)
		output = "images_bonus/Dofus_cawotte.xpm";
	else if (i > 30 && i <= 60)
		output = "images_bonus/Dofus_pourpre.xpm";
	else if (i < 100)
		output = "images_bonus/Dofus_vulbis.xpm";
	else
	{
		output = "images_bonus/Dofus_cawotte.xpm";
		i = 0;
	}
	return (output);
}

char	*get_wall(void)
{
	static int	i;
	char		*output;

	output = NULL;
	if (++i <= 30)
		output = "images_bonus/orangewall.xpm";
	else if (i > 30 && i <= 60)
		output = "images_bonus/redwall.xpm";
	else if (i < 100)
		output = "images_bonus/wall.xpm";
	else
	{
		output = "images_bonus/orangewall.xpm";
		i = 0;
	}
	return (output);
}
