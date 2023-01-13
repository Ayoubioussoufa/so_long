/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:40:21 by aybiouss          #+#    #+#             */
/*   Updated: 2022/12/30 12:40:21 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include "mlx.h"

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	char		**map;
	int			y;
	int			x;
	int			c;
	int			e;
	int			p;
	t_player	player;
}	t_map;

typedef struct s_program
{
	void		*mlx;
	void		*win;
	void		*img;
	t_map		map;
	int			img_size;
	int			can_exit;
	int			count;
}	t_program;

//utils
size_t	ft_strlen(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*get_next_line(int fd);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strchr(const char *s, int c);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

//errors
void	error_width_height(t_program *game);
void	error_map(void);
void	error_name(void);
void	error_file(void);
void	free_map(t_program *game);
void	error_image(t_program *game);
void	error_mapp(t_program *game);

//moves
int		keys(int key, t_program *game);
void	move_up(t_program *game);
void	move_down(t_program *game);
void	move_left(t_program *game);
void	move_right(t_program *game);

//window
void	ft_new_window(t_program *game);
int		ft_close(t_program *game);
void	ft_free(t_program *game);

//rendering
void	ft_render_images(t_program game);
void	render_image(t_program game, int x, int y);
char	*get_image(char c, int can_exit);

//parsing
void	width_height_filling_map(char *av, t_program *game);
void	check_map(char *av, t_program *game);
void	fill_map(char *av, t_program *game);
int		checking_ber(char *av);
void	check_player_coords(t_program *game);
void	valid_path(int x, int y, t_program *game, char *s);
void	ft_free(t_program *game);
int		checking_walls(t_program *game);
int		checking_outer_walls(t_program *game);
int		checking(t_program *game);
void	checking_ecp(t_program *game);
void	ft_error(t_program *game);

#endif