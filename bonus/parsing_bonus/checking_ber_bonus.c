/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_ber_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:19:50 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/04 16:19:50 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	checking_ber(char *av)
{
	int	length;

	length = ft_strlen(av);
	if (ft_strnstr(&av[length - 3], ".ber", 4) == 0)
		return (1);
	else
		return (0);
}
