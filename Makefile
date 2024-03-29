NAME		=	fractol

LIBFT		=	./libft/libft.a

CC			=	cc

PTH_INCLUDE	=	./includes

CFLAGS		=	-Wall -Wextra -Werror -g

SRC_FILES	=	fractol.c										\
				mandelbrot.c									\
				julia.c

SRC_VAL		=	arg_checker.c

SRC_MLX_CTL	=	mlx_px_setter.c									\
				mlx_controller.c								\
				mlx_methods.c

SRC			=	$(addprefix src/, $(SRC_FILES))					\
				$(addprefix mlx_controller/, $(SRC_MLX_CTL))	\
				$(addprefix validation/, $(SRC_VAL))

LIB_DIR		= 	./libft

OBJ			=	$(SRC:.c=.o)

RM			=	rm -fr

UNAME		= $(shell uname)

ifeq ($(UNAME), Linux)
	OFLAGS	=	$(CFLAGS) -L ./mlx_Linux -lmlx_Linux -L /usr/lib -I mlx_Linux -lXext -lX11 -lm -lz 
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
			$(CC) $(OBJ) $(OFLAGS)  -o $(NAME) $(LIBFT)

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
