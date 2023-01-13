/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:27:09 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/05 13:41:23 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_length(int n)
{
	int		count;
	long	num;

	num = n;
	count = 1;
	if (n < 0)
	{
		num = -num;
		count++;
	}
	else if (num == 0)
		return (1);
	while (num > 9)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*mem;
	unsigned long	num;
	int				i;

	num = n;
	i = ft_length(n);
	mem = malloc(i + 1);
	if (!mem)
		return (NULL);
	if (n < 0)
	{
		mem[0] = '-';
		num = -num;
	}
	mem[i--] = '\0';
	if (num == 0)
		mem[i] = '0';
	while (i >= 0 && num != 0)
	{
		mem[i--] = '0' + num % 10;
		num /= 10;
	}
	return (mem);
}
