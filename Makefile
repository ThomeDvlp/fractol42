NAME		=	fractol

LIBFT		=	./libft/libft.a

CC			=	cc

PTH_INCLUDE	=	./includes

CFLAGS		=	-Wall -Wextra -Werror -g

SRC			=	fractol.c

LIB_DIR		= 	./libft

OBJ			=	$(SRC:.c=.o)

RM			=	rm -fr

UNAME		= $(shell uname)

ifeq ($(UNAME), Linux)
	OFLAGS	=	$(CFLAGS) -L ./mlx_linux -lmlx_Linux -L /usr/lib -I mlx_linux -lXext -lX11 -lm -lz 
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
