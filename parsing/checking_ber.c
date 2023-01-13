/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_ber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:53:03 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/05 13:28:43 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checking_ber(char *av)
{
	int	length;

	length = ft_strlen(av);
	if (ft_strnstr(&av[length - 3], ".ber", 4) == 0)
		return (1);
	else
		return (0);
}
