/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:40:21 by aybiouss          #+#    #+#             */
/*   Updated: 2022/12/30 12:40:21 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include "mlx.h"

# define B

typedef struct s_enemy {
	int	x;
	int	y;
	int	alr;
	int	alrd;
}	t_enemy;

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
	int			b;
	t_player	player;
	t_enemy		enemy[1000];
}	t_map;

typedef struct s_program
{
	void	*mlx;
	void	*win;
	void	*img;
	t_map	map;
	int		img_size;
	int		can_exit;
	int		count;
}	t_program;

// enemy moves
void	check_enemy_coords(t_program *game);
void	move_down_enemy(t_program *game, int i);
void	move_up_enemy(t_program *game, int i);
void	move_right_enemy(t_program *game, int i);
void	move_left_enemy(t_program *game, int i);

//utils
size_t	ft_strlen(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*get_next_line(int fd);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);

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
int		moves_enemy(t_program *game);
void	ft_swap(char *x, char *y);

//window
void	ft_new_window(t_program *game);
int		ft_close(t_program *game);
void	ft_free(t_program *game);
void	put_count_window(t_program *game);

//rendering
void	ft_render_images(t_program game);
void	render_image(t_program game, int x, int y);
char	*get_image(char c, int can_exit);
char	*ft_strjnofree(char *s1, char *s2);
void	put_count_window(t_program *game);
char	*get_collectible(void);
char	*get_wall(void);

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
void	checking_b(t_program *game);

#endif