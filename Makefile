NC			=	\e[0m
RED			=	\e[0;91m
ORANGE		=	\e[93m
GREEN		=	\e[0;92m
PURPLE		=	\e[0;95m
BLUE		=	\e[0;34m
BOLD		=	\e[1m
RESET		=	\e[0m

NAME		=	fractol

LIBFT		=	./libft/libft.a

CC			=	cc

PTH_INCLUDE	=	./includes

CFLAGS		=	-Wall -Wextra -Werror -g

SRC_FILES	=	fractol.c

SRC			=	$(addprefix src/, $(SRC_FILES))

LIB_DIR		= 	./libft

OBJ			=	$(SRC:.c=.o)

RM			=	rm -fr

UNAME		= $(shell uname)

ifeq ($(UNAME), Linux)
	OFLAGS	=	$(CFLAGS) -L ./mlx_Linux -lmlx_Linux -L /usr/lib -I mlx_linux -lXext -lX11 -lm -lz 
	MLX		=	./mlx_Linux
else
	OFLAGS	= 	$(CFLAGS) -L ./mlx -lmlx -framework OpenGL -framework AppKit
	MLX		= 	./mlx
endif

.c.o:		
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(PTH_INCLUDE)

$(NAME):   	$(OBJ)
			make -C $(LIB_DIR)
			make -C $(MLX)
			$(CC) $(OBJ) $(OFLAGS) $(LIBFT) -o $(NAME) 

all:		$(NAME)


clean:
			make clean -C $(LIB_DIR)
			make clean -C $(MLX)
			$(RM) $(OBJ)

fclean:		clean
			make fclean -C $(LIB_DIR)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
