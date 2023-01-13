/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:20:17 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/09 16:15:40 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*ft_strjnofree(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (s1[j])
		s[i++] = s1[j++];
	while (s2[k])
		s[i++] = s2[k++];
	s[i] = '\0';
	return (s);
}

int	keys(int key, t_program	*game)
{
	if (key == 0)
		move_left(game);
	else if (key == 1)
		move_down(game);
	else if (key == 2)
		move_right(game);
	else if (key == 13)
		move_up(game);
	else if (key == 53)
		ft_free(game);
	return (0);
}
