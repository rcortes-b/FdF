#Define el nombre de la libreria que se va a crear
NAME	= libft.a

#Define el compilador que se va a utilizar
CC		= gcc

#Define las opciones de compilador y/o 'FLAGS' que se van a utilizar
CFLAGS	= -Wall -Wextra -Werror

#Define los archivos fuente
SRCS    = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
ft_strlen.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_split.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strlcpy.c \
ft_printf/itoa.c ft_printf/aux.c ft_printf/ft_printf.c ft_printf/hex.c \
get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

#Define los archivos fuente de la parte del bonus
B_SRCS	= ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

#Define el Header a utilizar
HEAD	= libft.h ft_printf/ft_printf.h get_next_line/get_next_line.h

#Define el como se van a obtener los archivos objeto
OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)

#Define el comando para crear la libreria estatica
AR		= ar rcs

#Define el comando para eliminar archivos
RM		= rm -f

#Define lo que hara el Makefile si ejecutamos Make sin ninguna regla [p.e --> clean] // Indica el objetivo del Makefile
all: $(NAME)

#Limpia los archivos objeto
clean:
	$(RM) $(OBJS) $(B_OBJS)

#Limpia los archivos objeto y la libreria .a
fclean: clean
	$(RM) $(NAME)

#Limpia todos los archivos objeto y la libreria.a y vuelve a compilar todo rehaciendolo
re: fclean all

#Define como convertir los archivos fuente en archivos objeto. Define las dependecias de los archivos objeto. Define el comando que se utilizara para compilar
%.o : %.c Makefile $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

#Define las dependencias para crear la libreria. Define el comando que se utilizara.
$(NAME): $(OBJS)
	$(AR) $@ $^

#Define las dependencias del bonus y el comando para crear la libreria
bonus: $(OBJS) $(B_OBJS)
	$(AR) $(NAME) $^

#Reserva los nombres para el Makefile. Si hay un archivo con el nombre 'p.e' all, el Makefile tiene prioridad
.PHONY: all clean fclean re
