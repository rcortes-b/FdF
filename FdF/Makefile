NAME = fdf

CC = gcc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SRCS = srcs/fdf.c srcs/parse.c srcs/aux.c srcs/algorithm.c srcs/window.c \
srcs/key.c srcs/menu.c srcs/colors.c srcs/aux_colors.c

OBJS = $(SRCS:.c=.o)

HEAD = includes/fdf.h mlx/mlx.h

LIBFT = libft/libft.a

all : $(NAME)

%.o : %.c Makefile $(HEAD)
	$(CC) $(FLAGS) -Imlx -c $< -o $@

libs:
	make -C mlx
	make -C libft

$(NAME): $(OBJS) libs
	$(CC) $(FLAGS) $(LIBFT) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	make clean -C mlx
	make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re libs