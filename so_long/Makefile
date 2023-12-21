.SILENT:

NAME = so_long

COMPILER = cc

FLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

SRCS = so_long.c\
basic_utils.c\
map_utils.c\
parsing_utils.c

OBJS := $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	cd libft && $(MAKE) && $(MAKE) bonus
	cc -o $(NAME) $(OBJS) $(MLX_FLAGS) ./libft/libft.a
	
%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@ -I./

clean:
	cd libft && $(MAKE) fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
