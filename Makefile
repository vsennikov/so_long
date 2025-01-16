CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = main.c error_msg.c map_validation/name_validation.c map_validation/map_parsing.c \
map_validation/map_validation.c map_validation/flood_fill.c game_control/init_map.c \
game_control/moovement.c map_validation/pars_vals_erros.c game_control/check_displaying.c
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
INCLUDES = -I./$(LIBFT_PATH)
GNL = gnl/get_next_line.c gnl/get_next_line_utils.c
GNL_O = $(GNL:.c=.o)
FRAEMWORK = -lmlx -lX11 -lXext -lm

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft
	
$(NAME): $(OBJS) $(LIBFT) $(GNL_O)
	$(CC) $(CFLAGS) $(FRAEMWORK) $(OBJS) $(GNL_O) -L./$(LIBFT_PATH) -lft -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE)  -C ./libft clean
	@rm -f $(OBJS) $(GNL_O)

fclean: clean
	@$(MAKE) -C ./libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re