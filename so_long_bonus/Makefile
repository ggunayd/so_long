NAME = so_long_bonus
FLAGS = -framework OpenGl -framework AppKit
SRC = $(wildcard src/*.c)
SRC += $(wildcard ../ft_printf/*.c)
SRC += $(wildcard ../get_next_line/*.c)
MLX_DIR = ./mlx
CC = gcc
INC = -I./inc
INC += -I../ft_printf

$(NAME): LIBFT MINILIBX
	$(CC) $(FLAGS) $(SRC) -o $(NAME) $(INC) $(MLX_DIR)/libmlx.a ../libft/libft.a

all: $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean
	make -C ../libft clean 
	make -C $(MLX_DIR) clean

re: clean all

norm:
	norminette src/
	norminette inc/

MINILIBX:
	make -C $(MLX_DIR) --silent
	@echo "MINILIBX compiled !"

LIBFT:
	make -C ../libft
	@echo "libft compiled !"

.PHONY: all clean fclean re norm MINILIBX LIBFT
