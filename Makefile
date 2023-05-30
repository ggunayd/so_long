NAME = so_long
FLAGS = -framework OpenGl -framework AppKit
SRC = $(wildcard src/*.c)
SRC += $(wildcard ft_printf/*.c)
SRC += $(wildcard get_next_line/*.c)
MLX_DIR = ./mlx
CC = gcc -g
INC = -I./inc
INC += -I./ft_printf

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME) $(INC) $(MLX_DIR)/libmlx.a libft/libft.a

all: MINILIBX $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all

norm:
	norminette src/
	norminette inc/

MINILIBX:
	make -C $(MLX_DIR) --silent
	@echo "MINILIBX compiled !"