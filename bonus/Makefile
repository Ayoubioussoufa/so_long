NAME = so_long_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX = ft_free_bonus.c enemy_moves.c ft_new_window_bonus.c  keys_bonus.c  moves_bonus.c  rendering_bonus.c count_bonus.c get_stuff_bonus.c enemy_bonus.c
PARSING = check_map_bonus.c  checking_ber_bonus.c  fill_map_bonus.c  get_map_bonus.c  player_coords_bonus.c  valid_path_bonus.c  walls_bonus.c

SRCS = $(addprefix ./mlx_bonus/,$(MLX))\
	$(addprefix ./parsing_bonus/,$(PARSING))\
	errors_bonus.c ft_strchr_bonus.c free_map_bonus.c  get_next_line_utils_bonus.c  get_next_line_bonus.c so_long_bonus.c  ft_itoa_bonus.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all