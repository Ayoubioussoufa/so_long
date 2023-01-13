
NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX = ft_free.c  ft_new_window.c  keys.c  moves.c  rendering.c
PARSING = check_map.c  checking_ber.c  fill_map.c  get_map.c  player_coords.c  valid_path.c  walls.c

SRCS = $(addprefix ./mlx/,$(MLX))\
	$(addprefix ./parsing/,$(PARSING))\
	errors.c  free_map.c  get_next_line_utils.c  get_next_line.c so_long.c  ft_strchr.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all